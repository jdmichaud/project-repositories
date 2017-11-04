/*
** order_hop.c for bistromathique in ~/c/rendu/projs/bistromathique
** 
** Made by jonathan mimouni
** Login   <mimoun_j@epita.fr>
** 
** Started on  Sat Oct 20 23:37:53 2001 jonathan mimouni
** Last update Sun Oct 28 16:07:25 2001 jonathan mimouni
*/

#include <stdlib.h>
#include "bistromathique.h"
#include "eval_str_sub.h"
#include "utils_str.h"
#include "order_hop.h"
#include "eval_str.h"
#include "errors.h"
#include "utils2.h"

char	*eval_hop(char *a, char *b, t_rules *rules, char op)
{
  if (op == rules->op[2])
    return (lmul(a, b, rules));
  else
    if (op == rules->op[3])
      {
	if (is_zero(b, rules))
	  {
	    errors(rules, 1);
	    return (0);
	  }
	else
	  return (divl(a, b, rules));
      }
    else
      if (is_zero(b, rules))
	{ 
	  errors(rules, 1);
	  return (0);
	}  
      else  
	return (divl(a, b, rules));
}

char	*order_dif_hop(char *a, char *b, t_rules *rules, char op)
{
  char	*tmp;
  char	*res;
  char	*save;
  
  if (a[0] == rules->op[1])
    {
      tmp = eval_hop(++a, b, rules, op);
      res = malloc(my_strlen(tmp) + 1);
      res[0] = rules->op[1];
      save = res;
      ++save;
      save = my_strcpy(save, tmp);
      free(tmp);
      return (res);
    }
  tmp = eval_hop(a, ++b, rules, op);
  res = malloc(my_strlen(tmp) + 1);
  res[0] = rules->op[1];
  save = res;
  ++save;
  save = my_strcpy(save, tmp);
  free(tmp);
  return (res);
}
