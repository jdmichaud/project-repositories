/*
** stack.h for louisemathique in 
** 
** Made by Jean-Daniel Michaudf
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Oct 25 23:59:38 2001 Jean-Daniel Michaudf
** Last update Mon Oct 29 09:39:07 2001 jean-daniel michaud
*/

#ifndef __STACK_H_
# define __STACK_H_

struct			s_stack
{
  t_node		*elm;
  struct s_stack	*next;
};

typedef struct s_stack	t_stack;

void	push(t_stack **stack, t_node *node);
t_node	*pop(t_stack **stack);

#endif
