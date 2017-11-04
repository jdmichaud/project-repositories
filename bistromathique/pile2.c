/*
** pile2.c for bistromathique in ~/c/rendu/projs/bistromathique
** 
** Made by jonathan mimouni
** Login   <mimoun_j@epita.fr>
** 
** Started on  Sun Oct 21 01:26:00 2001 jonathan mimouni
** Last update Sat Oct 27 22:41:19 2001 jonathan mimouni
*/

#include <stdlib.h>
#include "bistromathique.h"
#include "pile.h"
#include "pile2.h"
#include "pile3.h"
#include "order.h"
#include "errors.h"

void	print_pile_op(t_pile_op *pile)
{
  while (pile != NULL)
    pile = pile->next;
}

void	print_pile_str(t_pile_str *pile)
{
  while (pile != NULL)
    pile = pile->next;
}

void	eval_pile(t_rules *rules, t_pile_str **pile_str, t_pile_op **pile_op)
{
  char	*op1;
  char	*op2;
  char	op;
  char	*tmp;

  op2 = pop_str(pile_str);
  op1 = pop_str(pile_str);
  if (op1 == NULL)
    errors(rules, 2);
  op = pop_op(pile_op);
  if (op == rules->op[0])
    eval_pile_lplus(rules, pile_str, op1, op2);
  else
    if (op == rules->op[1])
      {
	tmp = order_subl(op1, op2, rules);
	push_str(pile_str, tmp);
	free(tmp); 
      }
    else
      {
	tmp = order_hop(op1, op2, rules, op);
	push_str(pile_str, tmp);
	free(tmp);
      }
}

char	*pop_all(t_rules *rules, t_pile_str **pile_str, t_pile_op **pile_op)
{
  char	*result;

  while ((*pile_op != NULL) && (*pile_str != NULL))
    eval_pile(rules, pile_str, pile_op);
  if (*pile_op == NULL)
    if (*pile_str == NULL)
      {
	errors(rules, 2);
	return (NULL);
      }
    else
      {
	result = pop_str(pile_str);
	if (*pile_str == NULL)
	  return (result);
	else
	  return (NULL);
      }
  else 
    return (NULL);
}

char	head_op(t_pile_op *pile)
{
  if (pile == NULL)
    return (NULL);
  else
    return (pile->elem);
}








