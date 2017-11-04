/*
** algo.c for regis in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Dec  6 10:32:31 2001 jean-daniel michaud
** Last update Mon Dec 10 17:37:10 2001 jean-daniel michaud
*/

#include <stdio.h>
#include <stdlib.h>

#include "defs.h"
#include "struct.h"
#include "list.h"
#include "algo.h"
#include "graph.h"
#include "utils.h"
#include "xmalloc.h"
#include "list_utils.h"
#include "tab.h"
#include "mkgraph.h"
#include "debug.h"

t_list		*reduce(t_matrix *matrix, int node)
{
  static t_list *head = NULL;
  static t_list *current = NULL;
  t_stack       *stack;
  int           *choice;
  int		i;

  make_choice(&choice, matrix);
  if ((i = nkill(matrix, &head, choice)) >= 0)
    {
      dec_degree(matrix, i);
      reduce(matrix, i);
    }
  else
    {
      current = head;
      return (NULL);
    }
  stack = current->elem;
  if (!stack->how)
    colorize(matrix, head, current);
  else
    if (!spill(matrix, &head, current, choice))
      return (NULL);
  freehere(matrix, choice, &current, stack);
  return (head);
}

int		colorize(t_matrix *matrix, t_list *head, t_list *current)
{
  int		i;
  t_stack	*stack;

  stack = current->elem;
  if ((i = isnear(matrix, stack->indice, head)) < 0)
    return (0);
  stack->color = i;
  return (1);
}

void		freeto(t_list **begin, t_list *end)
{
  t_list	*tmp;
  t_list	*p;
  
  p = *begin;
  while (p && p != end)
    {
      tmp = p->next;
      free(p->elem);
      free(p);
      p = tmp;
    }
  tmp = p->next;
  free(p->elem);
  free(p);  
  *begin = tmp;
}

int		nkill(t_matrix *matrix, t_list **list, int *choice)
{
  int		node;
  t_stack	*stack;
  
  stack = malloc(sizeof (t_stack));
  for (node = 0; node < matrix->nnode; ++node)
    if ((choice[node] < matrix->ncolor) && (choice[node] > -1))
      {
	stack->name = getname(matrix->name, node);
	stack->indice = node;
	stack->how = 0;
	stack->color = -1;
	hadd(list, stack);
	matrix->lnode[node] = choice[node] = -2;
	return (stack->indice);
      }
  if ((node = lifr_node(choice, matrix)) != -1)
    {
      stack->name = getname(matrix->name, node);
      stack->indice = node;
      stack->how = 1;
      stack->color = -1;
      pure(choice, degree(matrix, stack->indice), matrix->nnode);
      hadd(list, stack);
      matrix->lnode[node] = choice[node] = -2;
      return (stack->indice);
    }
  return (-1);
}

t_list		*spill(t_matrix	*matrix, 
		      t_list	**head, 
		      t_list	*current, 
		      int	*choice)
{
  t_stack	*stack;
  t_list	*list;
  int		i;

  for (list = *head; !(colorize(matrix, list, current)) && 
	 !isempty(choice, matrix->nnode); list = *head)
    {
      err_spile(matrix, *head);
      stack = current->elem;
      matrix->lnode[stack->indice] = matrix->plnode[stack->indice];
      freeto(head, current);
      if ((i = nkill(matrix, head, choice)) >= 0)
	{
	  dec_degree(matrix, i);
	  current = *head;
	  reduce(matrix, i);
	  stack = (*head)->elem;
	}
      else
	return (NULL);
    }
  return (*head);
}

