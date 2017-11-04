/*
** stack.c for louisemathique in 
** 
** Made by Jean-Daniel Michaudf
** Login   <michau_j@epita.fr>
** 
** Started on  Fri Oct 26 00:00:06 2001 Jean-Daniel Michaudf
** Last update Mon Oct 29 19:06:10 2001 jean-daniel michaud
*/

#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>
#include "tree.h"
#include "stack.h"
#include "my_stdlib.h"

void		push(t_stack **stack, t_node *node)
{
  t_stack	*tmp;
  
  if (!(*stack))
    {
      *stack = xmalloc(sizeof (t_node));
      (*stack)->next = NULL;
    }
  else
    {
      tmp = xmalloc(sizeof (t_node));
      tmp->next = *stack;
      *stack = tmp;
    }
  (*stack)->elm = node;
}

t_node		*pop(t_stack **stack)
{
  t_node	*tmp;  
  t_stack	*_tmp;

  if (*stack == NULL)
    return (NULL);
  tmp = (*stack)->elm;
  _tmp = *stack;
  *stack = (*stack)->next;
  free(_tmp);
  return (tmp);
}

