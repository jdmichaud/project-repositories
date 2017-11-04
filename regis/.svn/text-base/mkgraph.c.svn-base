/*
** mkgraph.c for regis in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Dec  5 18:23:54 2001 jean-daniel michaud
** Last update Mon Dec 10 14:33:34 2001 jean-daniel michaud
*/

#include <stdio.h>
#include <stdlib.h>

#include "defs.h"
#include "struct.h"
#include "list.h"
#include "mkgraph.h"
#include "string.h"
#include "list_utils.h"
#include "xmalloc.h"
#include "graph.h"

extern	char	*gl_str;
int		yylex(void);

void		syntax_error(void)
{
   fprintf(stderr, "Syntax Error\n");
   exit(1);
}

t_matrix	*make_graph(void)
{
  t_matrix	*matrix;
  int		i;
  int		ret;

  matrix = xmalloc(sizeof (t_matrix));
  matrix->name = NULL;
  if (yylex() != EOF)
    matrix->ncolor = atoi(gl_str);
  free(gl_str);
  for (ret = yylex(); (ret != EOF) && (ret == F_NODES); ret = yylex())
    qadd(&(matrix->name), gl_str);
  if (ret == F_ERROR)
    syntax_error();
  matrix->nnode = listsize(matrix->name);
  matrix->graph = malloc(matrix->nnode * sizeof (int));
  for (i = 0; i < matrix->nnode; ++i)
    matrix->graph[i] = malloc(matrix->nnode * sizeof (int));
  make_vertex(matrix, ret);
  if (ret == F_ERROR)
    syntax_error();
  make_lnode(matrix);
 return (matrix);
}

void		make_vertex(t_matrix *matrix, int ret)
{
  char		*x;
  char		*y;
  int		i;
  int		j;
  
  for (; (ret == F_EDGE); ret = yylex())
    {
      x = gl_str;
      ret = yylex();
      if (ret == F_EDGE)
	y = gl_str;
      else
	return;
      i = getindice(matrix->name, x);
      j = getindice(matrix->name, y);
      matrix->graph[i][j] = 1;
      matrix->graph[j][i] = 1;
    }
}

void		make_lnode(t_matrix *matrix)
{
  int		i;

  matrix->lnode = xmalloc(sizeof (int) * matrix->nnode + 1);
  matrix->plnode = xmalloc(sizeof (int) * matrix->nnode + 1);
  for (i = 0; i < matrix->nnode; ++i)
    {
      matrix->lnode[i] = degree(matrix, i);
      matrix->plnode[i] = degree(matrix, i);
    }
}

void		make_choice(int **choice, t_matrix *matrix)
{
  *choice = xmalloc(matrix->nnode * sizeof (int));
  memcpy(*choice, matrix->lnode, matrix->nnode * sizeof (int));
}
