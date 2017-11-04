/*
** tab.c for regis in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Mon Dec 10 12:22:17 2001 jean-daniel michaud
** Last update Mon Dec 10 17:37:02 2001 jean-daniel michaud
*/

#include <stdlib.h>

#include "defs.h"
#include "struct.h"
#include "tab.h"
#include "list.h"

void	dec_degree(t_matrix *matrix, int node)
{
  int	i;

  for (i = 0; i < matrix->nnode; ++i)
    if (matrix->graph[i][node] > 0)
      --matrix->lnode[i];
}

void	inc_degree(t_matrix *matrix, int node)
{
  int	i;

  for (i = 0; i < matrix->nnode; ++i)
    if (matrix->graph[i][node] > 0)
      ++matrix->lnode[i];  
}

void	update(t_matrix *matrix, int *choice)
{
  int	i;
  int	j;

  for (j = 0; j < matrix->nnode; ++j)
    if (choice[j] < 0)
     matrix->lnode[j] = 0;
  for (j = 0; j < matrix->nnode; ++j)
    for (i = 0; i < matrix->nnode; ++i)
      if ((matrix->graph[i][j] > 0) && (choice[i] >= 0))
	++matrix->lnode[j];
}

void	freehere(t_matrix	*matrix, 
		 int		*choice, 
		 t_list		**current, 
		 t_stack	*stack)
{
  matrix->lnode[stack->indice] = matrix->plnode[stack->indice];
  *current = (*current)->next;
  free(choice);
}
