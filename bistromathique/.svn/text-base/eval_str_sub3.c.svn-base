/*
** eval_str_sub3.c for bistromathique in 
** 
** Made by Jean-Daniel Michaudf
** Login   <jedi@epita.fr>
** 
** Started on  Fri Oct 19 19:00:00 2001 Jean-Daniel Michaudf
** Last update Sat Oct 27 18:00:14 2001 jean-daniel michaud
*/

#include <stdlib.h>
#include "bistromathique.h"
#include "eval_str_sub2.h"
#include "eval_str_sub3.h"
#include "eval_str.h"
#include "utils2.h"

char	*less_t_zero(char *res, t_rules *rules, int base_size)
{
  res = complement(res, rules, base_size);
  res = lplus(res, "1", rules);
  res = add_moins(res, rules->op[1]);
  return (res);
}

char	*if_zero(char *str1p, char *str2p, t_rules *rules)
{
  char	*res;

  if ((is_zero(str1p, rules)) && (is_zero(str2p, rules)))
    {
      res = malloc(2);
      res[0] = rules->base[0];
      res[1] = '\0';
      return (res);
    }
  return (NULL);
}
