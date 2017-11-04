/*
** utils2.c for bistromathique in ~/c/rendu/bistromathique
** 
** Made by jonathan mimouni
** Login   <mimoun_j@epita.fr>
** 
** Started on  Sun Oct 21 01:24:43 2001 jonathan mimouni
** Last update Sat Oct 27 10:51:55 2001 jonathan mimouni
*/

#include <stdlib.h>
#include "bistromathique.h"
#include "utils2.h"

int	is_hpop2(t_rules *rules, char c)
{
  int	i;

  for (i = 2; (i < 7) && (c != rules->op[i]); ++i)
    ;
  if (i < 7)
    return (1);
  else
    return (0);
}

int	is_op(t_rules *rules, char c)
{
  int	i;

  for (i = 0; i < 7; ++i)
    if (c == rules->op[i])
      return (1);
  return (0);
}

int	priority(t_rules *rules, char op)
{
  if ((op == rules->op[0]) || (op == rules->op[1]))
    return (1);
  else
    if ((op == rules->op[2]) || (op == rules->op[3]) || (op == rules->op[4]))
      return (2);
    else
      if (op == rules->op[5])
	return (0);
  else
    return (-1);
}


char	*my_strdup_fc(char c)
{
  char	*str;

  if ((str = malloc(2 * sizeof (char))) == 0)
    return (0);
  str[0] = c;
  str[1] = '\0';
  return (str);
}

int	is_zero(char *a, t_rules *rules)
{
  for (; (*a != '\0') && (*a == rules->base[0]); ++a)
    ;
  if (*a == '\0')
    return (1);
  else
    return (0);
}



