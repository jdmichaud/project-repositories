/*
** utils.c for regis in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Dec  6 14:26:17 2001 jean-daniel michaud
** Last update Mon Dec 10 21:33:00 2001 jean-daniel michaud
*/

#include <stdio.h>

#include "defs.h"
#include "struct.h"
#include "list.h"
#include "xmalloc.h"
#include "utils.h"
#include "list_utils.h"

int		iscolorize(t_list *list)
{
  t_stack	*stack;

  for (; list; list = list->next)
    {
      stack = list->elem;
      if (stack->color == -1)
	return (0);
    }
  return (1);
}

int		isempty(int *tab, int n)
{
  int		i;

  for (i = 0; i < n; ++i)
    if (tab[i] > 0)
      return (0);
  return (1);
}

int		isnear(t_matrix *matrix, int node, t_list *neighb)
{
  int		*colors;
  t_stack	*stack;
  int		i;

  colors = xmalloc(matrix->ncolor * sizeof (int));
  memset(colors, 0, matrix->ncolor * sizeof (int));
  for (stack = neighb->elem; neighb && 
	 (stack->indice != node); neighb = neighb->next)
    { 
      if (matrix->graph[node][stack->indice])
	colors[stack->color] = 1;
      stack = neighb->elem;
    }
  for (i = 0; (i < matrix->ncolor) && colors[i]; ++i)
    ;
  if (i < matrix->ncolor)
    return (i);
  return (-1);
}

void		err_spile(t_matrix *matrix, t_list *list)
{
  t_stack	*stack;

  if (list)
    {
      printf("ERR = [");
      while (list)
	{
	  stack = list->elem;
	  printf("%s", getname(matrix->name, stack->indice));
	  if (list->next)
	    printf("; ");
	  list = list->next;
	}
      printf("];\n");
    }  
}

void		spile(t_matrix *matrix, t_list *list)
{
  t_stack	*stack;

  fflush(stdout);
  if (list)
    {
      printf("OK = [");
      while (list)
	{
	  stack = list->elem;
	  printf("(%s, %i)", getname(matrix->name, 
				      stack->indice), stack->color);
	  if (list->next)
	    printf("; ");
	  list = list->next;
	}
      printf("];\n");
    }
}
