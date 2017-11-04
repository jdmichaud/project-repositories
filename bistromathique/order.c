/*
** order.c for bistromathique in ~/c/rendu/projs/bistromathique
** 
** Made by jonathan mimouni
** Login   <mimoun_j@epita.fr>
** 
** Started on  Sat Oct 20 20:46:32 2001 jonathan mimouni
** Last update Sat Oct 27 19:12:37 2001 jonathan mimouni
*/

#include <stdlib.h>
#include "bistromathique.h"
#include "eval_str_sub.h"
#include "utils_str.h"
#include "order.h"
#include "order_hop.h"
#include "eval_str.h"

char	*order_dif_sign_lplus(char *a, char *b, t_rules *rules)
{
  if ((a[0] == rules->op[1]) && (b[0] != rules->op[1]))
    {
      a[0] = rules->base[0];
      return (subl(b, a, rules));
    }
  else
    {
      b[0] = rules->base[0];
      return (subl(a, b, rules));
    }
}

char	*order_lplus(char *a, char *b, t_rules *rules)
{
  char	*tmp;
  char	*res;
  char	*save;

  if ((a[0] == rules->op[1]) && (b[0] == rules->op[1]))
    {     
      tmp = lplus(++a, ++b, rules);
      res = malloc(my_strlen(tmp) + 1);
      res[0] = rules->op[1];
      save = res;
      ++save;
      save = my_strcpy(save, tmp);
      free(tmp);
      return (res);
    }
  else
    if ((a[0] != rules->op[1]) && (b[0] != rules->op[1]))
      return (lplus(a, b, rules));
    else
      return (order_dif_sign_lplus(a, b, rules));
}

char	*order_dif_sign_subl(char *a, char *b, t_rules *rules)
{
  if ((a[0] != rules->op[1]) && (b[0] == rules->op[1]))
    return (lplus(a, ++b, rules));
  else
    return (subl(++b, ++a, rules));
}

char	*order_subl(char *a, char *b, t_rules *rules)
{
  char	*tmp;
  char	*res;
  char	*save;

  if ((a[0] == rules->op[1]) && (b[0] != rules->op[1]))
    {
      tmp = lplus(++a, b, rules);
      res = malloc(my_strlen(tmp) + 1);
      res[0] = rules->op[1];
      save = res;
      ++save;
      save = my_strcpy(save, tmp);
      free(tmp);
      return (res);
    }
  else
    if ((a[0] != rules->op[1]) && (b[0] != rules->op[1]))
      return (subl(a, b, rules));
    else
      return (order_dif_sign_subl(a, b, rules));
}

char	*order_hop(char *a, char *b, t_rules *rules, char op)
{
  if ((a[0] == rules->op[1]) && (b[0] == rules->op[1]))
    return (eval_hop(++a, ++b, rules, op));
  else
    if ((a[0] != rules->op[1]) && (b[0] != rules->op[1])) 
      return (eval_hop(a, b, rules, op));
    else
      return (order_dif_hop(a, b, rules, op));
}




