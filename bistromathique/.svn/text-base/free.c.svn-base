/*
** free.c for bistromathique in ~c/rendu/projs/bistromathique
** 
** Made by jonathan mimouni
** Login   <mimoun_j@epita.fr>
** 
** Started on  Fri Oct 12 14:03:10 2001 jonathan mimouni
** Last update Sun Oct 21 18:35:19 2001 jonathan mimouni
*/

#include <stdlib.h>
#include "bistromathique.h"
#include "free.h"

void		free_all(t_rules *rules)
{
  t_list	*p;
  t_list	*prec;
  int		i;

  free(rules->save_expr);
  free(rules->base);
  free(rules->op);
  for (i = 0; i < 4; ++i) 
    {
      p = rules->tab_errors[i];
      while (p != NULL)
	{
	  prec = p;
	  p = p->next;
	  free(prec);
	}
    }
}

