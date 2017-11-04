/*
** utils_parser.c for bistromathique in ~/rendu/projs/bistromathique
** 
** Made by jonathan mimouni
** Login   <mimoun_j@epita.fr>
** 
** Started on  Sun Oct 21 01:24:07 2001 jonathan mimouni
** Last update Sat Oct 27 19:51:06 2001 jonathan mimouni
*/

#include <stdlib.h>
#include "bistromathique.h"
#include "utils_parser.h"
#include "utils.h"
#include "utils2.h"
#include "pile.h"
#include "parser_pile.h"
#include "parser.h"
#include "errors.h"

void	hpop_lpop(t_rules *rules, t_pile_str **p_str, 
		     t_pile_op **p_op, char **expr)
{
  int	i;
  char	*moins_un;

  i = signe(rules, expr);
  if (i == -2)
    {
      push_op(p_op, rules->op[2]);
      if ((moins_un = malloc(3)) == NULL)
	errors(rules, 3);
      else
	{
	  moins_un[0] = rules->op[1];
	  moins_un[1] = rules->base[1];
	  moins_un[2] = '\0';
	  push_str(p_str, moins_un);
	}
    }
  else
    if (i != 2)
      push_str(p_str, get_next_number(rules, i, expr));
} 

void	nbr_lpop(t_rules *rules, t_pile_str **p_str, 
		     t_pile_op **p_op, char **expr)
{
  int	i;
  char	*tmp;

  i = signe(rules, expr);
  tmp = malloc(2);
  tmp[1] = '\0';
  if ((i == -1) || (i == -2))
    {
      tmp[0] = rules->op[1];
      parser_pile_op(rules, p_str, p_op, &tmp);
    }
  else
    {
      tmp[0] = rules->op[0];
      parser_pile_op(rules, p_str, p_op, &tmp);
    }
}

char	*get_next_number(t_rules *rules, int s, char **expr)
{
  char	*save;
  char	*res;
  int	i;
  int	j;
  int	k;

  save = *expr;
  for (i = 0; (**expr != '\0') && (!(is_op(rules, **expr))) 
	 && (is_known(rules, **expr)) ; ++i)
    ++(*expr);
  if ((**expr != '\0') && (!(is_op(rules, **expr)))
      && (!(is_known(rules, **expr))))
    errors(rules, 2);
  j = 0;
  res = malloc(i + 2);
  if (s < 0) 
    {
      res[0] = rules->op[1];
      ++j;
    }
  for (k = 0; k < i; ++save, ++j, ++k)
    res[j] = *save;
  res[j] = '\0';
  return (res);
}






