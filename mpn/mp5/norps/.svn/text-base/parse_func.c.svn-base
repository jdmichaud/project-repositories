/*
** parse_func.c for norps in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Dec  1 08:08:33 2001 jean-daniel michaud
** Last update Tue Dec  4 01:50:42 2001 jean-daniel michaud
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <ctype.h>

#include "struct.h"
#include "list.h"
#include "vars.h"
#include "libs.h"
#include "parser.h"
#include "parse_func.h"
#include "parse_error.h"

static t_keyword	keywords[MAX_KW] =
{
  {"open", 3, {STRING, AS, INTEGER}}, 
  {"close", 1, {STRING}},
  {"libs", 0, {NULL}},
  {"vars", 0, {NULL}},
  {"unset", 1, {STRING}},
  {"print", 1, {STRING}},
  {"quit", 0, {NULL}},
  {"void *", 4, {STRING, SEPARATOR, STRING, STRING}},
  {"char", 4, {STRING, SEPARATOR, STRING, STRING}},
  {"short", 4, {STRING, SEPARATOR, STRING, STRING}},
  {"int", 4, {STRING, SEPARATOR, STRING, STRING}},
  {"uchar", 4, {STRING, SEPARATOR, STRING, STRING}},
  {"ushort", 4, {STRING, SEPARATOR, STRING, STRING}},
  {"uint", 4, {STRING, SEPARATOR, STRING, STRING}}
};

char		*get_to_next_parenthsis(char **cmd)
{
  t_list	*list;
  char		c;

  c = *(*cmd)++;
  list = NULL;
  while ((c != ')') && (c != 0))
    {
      if (c == 32)
	nospace(cmd);
      push(&list, c);
      c = *(*cmd)++;
    }
  if (c == 0)
    parse_error(4);
  c = *(*cmd)--;
  return (collapse(list));
}

int	get_id(char *word)
{
  int	i;

  for (i = 0; i < MAX_KW; ++i)
    if (!strcmp(keywords[i].id, word))
      return (i);
  return (i);
}

char		*get_next_word(char **cmd)
{
  char		c;
  t_list	*list;

  nospace(cmd);
  list = NULL;
  c = *(*cmd)++;
  if (c == ')')
    {
      nospace(cmd);
      c = *(*cmd)++;
    }
  while (c == ':')
    {
      push(&list, c);
      c = *(*cmd)++;
    }
  if (!list)
    while (!isspace(c) && (c != ')') && (c != 0) && (c != ':') && (c != ','))
      {
	push(&list, c);
	c = *(*cmd)++;
      }
  return (collapse(list));
}

void	nospace(char **cmd)
{
  char	c;
  
  c = *(*cmd)++;
  while ((c == 32) && (c != 0))
    c = *(*cmd)++;
  c = *(*cmd)--;
}
