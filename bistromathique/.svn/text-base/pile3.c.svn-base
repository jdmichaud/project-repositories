/*
** pile3.c for  in 
** 
** Made by jonathan mimouni
** Login   <mimoun_j@epita.fr>
** 
** Started on  Sat Oct 27 22:22:13 2001 jonathan mimouni
** Last update Sat Oct 27 22:53:24 2001 jonathan mimouni
*/

#include <stdlib.h>
#include "bistromathique.h"
#include "order.h"
#include "pile.h"

void	eval_pile_lplus(t_rules *rules, t_pile_str **pile_str, 
			char *op1, char *op2)
{
  char	*tmp;

  tmp = order_lplus(op1, op2, rules);
  push_str(pile_str, tmp);
  free(tmp);
}
