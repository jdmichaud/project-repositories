#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

#define TRUE         1
#define FALSE        0

#define MAX_MATCHES  255
#define MAX_NFA_SIZE 255
#define BACKSLASH    '\\'
#define CATENATION   8 // bell character

static char *g_meta = "*+?()|";

void serror()
{
  perror(strerror(errno));
  exit(errno);
}

void error(char *msg, int code)
{
  fprintf(stderr, "%s\n", msg);
  exit(code);
}

void usage()
{
  printf("Copyright 2008 Free Software Foundation, Inc.\n");
  printf("This is free software with ABSOLUTELY NO WARRANTY.\n");
  printf("usage: rxp [POSIX regexp] <filename>\n");
  exit(1);
}

void remap(char *filename)
{
  int stdinno = fileno(stdin);
  //close(stdinno);
  FILE *f;
  if (!(f = fopen(filename, "r")))
    serror();
  int input = fileno(f);
  if (dup2(input, stdinno) == -1)
    serror();
  close(input);
}

char ismeta(char c)
{
  if (c == CATENATION) return TRUE;

  char *m = g_meta;
  for ( ; *m; ++m)
    if (c == *m)
      return TRUE;

  return FALSE;
}

char *printable_nfa(char *nfa, char rep)
{
  char *printable_nfa = (char *) malloc(sizeof (char) * strlen(nfa));
  memcpy(printable_nfa, nfa, sizeof (char) * strlen(nfa) + 1);
  char *p;
  for (p = printable_nfa; *p; ++p)
    if (*p == CATENATION)
      *p = rep;

  return printable_nfa;
}

int operator_precedence(char c)
{
  static char operators[4][4] = 
    { 
      "()",
      "|",
      { CATENATION, 0 },
      "*+?",
    };

  int i, j;
  for (i = 0; i < 5; ++i)
    for (j = 0; operators[i][j]; ++j)
      if (operators[i][j] == c)
        return i;

  return 0;
}

/* Algorithm: shunting yard
 * Test:
 * a|b        -> ab|
 * (a|b)      -> ab|
 * aa|bb      -> aa.bb.|
 * a(bb)+a    -> abb.+.a.
 * a(c|bb)+a  -> acbb.|+.a
 * a(b(bc))+a -> abbc..+.a.
 * a|b|c      -> abc||
 */
char *re2post(char *re)
{
  /* postfix notation may take more room than prefix notation */
  char *post = (char *) malloc(sizeof (char) * 2 * strlen(re));
  char *op_stack = (char *) malloc(sizeof (char) * strlen(re));
  memset(post, 0, sizeof (char) * 2 * strlen(re));
  memset(op_stack, 0, sizeof (char) * strlen(re));

  char *r;
  char *n = post;
  char *o = op_stack;
  for (r = re; *r; )
  {
    if (!ismeta(*r))
    {
      *n++ = *r;
    }
    else switch (*r)
    {
    case '(':
      *o++ = '(';
      break;
    case ')':
      for (o--; *o && *o != '('; )
        *n++ = *o--;
      if (*o != '(')
        error("mismatch parenthesis", 1);
      break;
    default:
      while (o != op_stack
             && (operator_precedence(*r) <= operator_precedence(*(o - 1)))
             && !((*r == '|') && (*(o - 1) == '|'))) // | n-ary operator
        *n++ = *--o;
      *o++ = *r;
    }

    /* special handling of implicit concatenation operator */
    if (*r == CATENATION 
        || (*r == '(') 
        || (*r == '|') 
        || (!*(r + 1)) 
        || (ismeta(*(r + 1)) && *(r + 1) != '('))
      ++r;
    else
      *r = CATENATION;

  }
  while (o-- != op_stack)
  {
    if (*o == '(')
      error("mismatch parenthesis", 2);
    *n++ = *o;
  }

  free(op_stack);
  return post;
}

/*
 * Concert the postfix expression to an NFA.
 */
typedef enum { CHARACTER, SPLIT, END } type_e;

typedef struct state_s
{
  char c;
  type_e t;
  struct state_s *next;
  struct state_s *next2;
} state;

typedef struct state_list_s
{
  state **state;
  struct state_list_s *next;
} state_list;

typedef struct helper_s
{
  state *start;
  state_list *nexts;
} helper;

state *create_state(type_e type, char c, state *next, state *next2)
{
  state *s = (state *) malloc(sizeof (state));
  s->c = c;
  s->t = type;
  s->next = next;
  s->next2 = next2;
  return s;
}

state_list *merge(state_list *head, state_list *next)
{
  state_list *s;
  for (s = head; s->next; s = s->next) ;
  s->next = next;
  return s;
}

state_list *create_state_list(state **s)
{
  state_list *sl = (state_list *) malloc(sizeof (state_list));
  sl->state = s;
  sl->next = NULL;
  return sl;
}

helper *create_helper(state *start, state_list *nexts)
{
  helper *h = (helper *) malloc(sizeof (helper));
  h->start = start;
  h->nexts = nexts;
  return h;
}

void assign(state_list *sl, state *s)
{
  for (; sl; sl = sl->next)
    *(sl->state) = s;
}

state *post2nfa(char *post)
{
  helper *stack[MAX_NFA_SIZE];
  memset(stack, 0, MAX_NFA_SIZE * sizeof (helper *));
  int    i = 0;
  char  *p = post;
  state *n;

  for (; *p; ++p)
  {
    switch (*p)
    {
    case '|':
    {
      helper *h1 = stack[--i];
      helper *h2 = stack[--i];
      n = create_state(SPLIT, 0, h1->start, h2->start);
      stack[i++] = create_helper(n, merge(h1->nexts, h2->nexts));
      free(h1); free(h2);
      break;
    }
    case '+':
    {
      helper *h1 = stack[--i];
      n = create_state(SPLIT, 0, h1->start, NULL);
      assign(h1->nexts, n);
      stack[i++] = create_helper(h1->start, create_state_list(&(n->next2)));
      free(h1);
      break;
    }
    case '*':
    {
      helper *h1 = stack[--i];
      n = create_state(SPLIT, 0, h1->start, NULL);
      assign(h1->nexts, n);
      stack[i++] = create_helper(n, create_state_list(&(n->next2)));
      free(h1);
      break;
    }
    case '?':
    {
      helper *h1 = stack[--i];
      n = create_state(SPLIT, 0, h1->start, NULL);
      stack[i++] = create_helper(n, merge(create_state_list(&(n->next2)), h1->nexts));
      free(h1);
      break;
    }
    case CATENATION:
    {
      helper *h1 = stack[--i];
      helper *h2 = stack[--i];
      n = create_state(SPLIT, 0, h2->start, NULL);
      assign(h1->nexts, n);
      stack[i++] = create_helper(h1->start, h2->nexts);
      free(h1); free(h2);
      break;
    }
    default:
      n = create_state(CHARACTER, *p, NULL, NULL);
      stack[i++] = create_helper(n, create_state_list(&(n->next)));
    }
  }
  assign(stack[--i]->nexts, create_state(END, 0, NULL, NULL));
  return stack[i]->start;
}

char *nfa2char(state *s)
{
  
}

char*
re2post2(char *re)
{
	int nalt, natom;
	static char buf[8000];
	char *dst;
	struct {
		int nalt;
		int natom;
	} paren[100], *p;

	p = paren;
	dst = buf;
	nalt = 0;
	natom = 0;
	if(strlen(re) >= sizeof buf/2)
		return NULL;
	for(; *re; re++){
		switch(*re){
		case '(':
			if(natom > 1){
				--natom;
				*dst++ = '#';
			}
			if(p >= paren+100)
				return NULL;
			p->nalt = nalt;
			p->natom = natom;
			p++;
			nalt = 0;
			natom = 0;
			break;
		case '|':
			if(natom == 0)
				return NULL;
			while(--natom > 0)
				*dst++ = '#';
			nalt++;
			break;
		case ')':
			if(p == paren)
				return NULL;
			if(natom == 0)
				return NULL;
			while(--natom > 0)
				*dst++ = '#';
			for(; nalt > 0; nalt--)
				*dst++ = '|';
			--p;
			nalt = p->nalt;
			natom = p->natom;
			natom++;
			break;
		case '*':
		case '+':
		case '?':
			if(natom == 0)
				return NULL;
			*dst++ = *re;
			break;
		default:
			if(natom > 1){
				--natom;
				*dst++ = '#';
			}
			*dst++ = *re;
			natom++;
			break;
		}
	}
	if(p != paren)
		return NULL;
	while(--natom > 0)
		*dst++ = '#';
	for(; nalt > 0; nalt--)
		*dst++ = '|';
	*dst = 0;
	return buf;
}


char **parse(char *r, char *line)
{
  char **matches = (char **) malloc(sizeof (char *) * MAX_MATCHES);
  matches[0] = strdup("1");
  matches[1] = NULL;
  return matches;
}

int main(int argc, char **argv)
{
  //printf("%s\n", re2post2(argv[1]));
  //char *p = printable_nfa(re2post(argv[1]), '#');
  //printf("%s\n", p);
  //free(p);
  //return 0;

  char *post = re2post(argv[1]);
  state *nfa = post2nfa(post);
  return 0;

  if (argc != 2 && argc != 3) usage();
  if (argc == 3)
    remap(argv[2]);

  int i = 0;
  char line[1024];
  char **matches;
  while (!feof(stdin))
  {
    *line = 0;
    scanf("%s", line);
    printf("%s\n", line);
    matches = parse(argv[1], line);
    for (i = 0; i < 1024 && matches[i] != NULL; ++i)
    {
      printf("%s ", matches[i]);
      free(matches[i]);
    }
    free(matches);
    printf("\n");
  }

  return 0;
}
