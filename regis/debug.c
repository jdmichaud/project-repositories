/*
** debug.c for regis in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Dec  6 10:46:08 2001 jean-daniel michaud
** Last update Mon Dec 10 18:10:30 2001 jean-daniel michaud
*/

#include <stdio.h>

#include "struct.h"
#include "list.h"
#include "debug.h"
#include "list_utils.h"

#define DEBUG_

int		sg(t_matrix *matrix)
{
#ifdef DEBUG
  int		i;
  int		j;
  t_list	*list;
  
  for (i = 0, list = matrix->name; i < matrix->nnode; ++i)
    {
      printf("%4s ", list->elem);
      list = list->next;
      for (j = 0; j < matrix->nnode; ++j)
	printf("%2i", matrix->graph[i][j]);
      printf("\n");
    }
#endif
  return (0);
}

void		sc(int	*color, int ncolor)
{
#ifdef DEBUG
  int		i;

  for (i = 0; i < ncolor; ++i)
    printf("%i ", color[i]);
  printf("\n");
#endif
}

void		dspile(t_matrix *matrix, t_list *list)
{
#ifdef DEBUG
  t_stack	*stack;

  if (list)
    {
      printf("[");
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
#endif
}

void	salive(t_matrix *matrix, int *choice)
{
#ifdef DEBUG
  int	i;

  for (i = 0; i < matrix->nnode; ++i)
    if (choice[i] >= 0)
      fprintf(stdout, "%s still alive\n", getname(matrix->name, i));
#endif
}
