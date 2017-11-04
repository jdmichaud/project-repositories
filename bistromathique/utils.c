/*
** utils.c for bistromathique in ~/c/rendu/projs/bistromathique
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  9 18:23:37 2001 jean-daniel michaud
** Last update Sun Oct 21 16:49:49 2001 jonathan mimouni
*/

#include "bistromathique.h"
#include "utils.h"

int	is_hpop(t_rules *rules, char c)
{
  int	i;

  for (i = 2; (i < 5) && (c != rules->op[i]); ++i)
    ;
  if (i < 5)
    return (1);
  else
    return (0);
}

int	is_lpop(t_rules *rules, char c)
{
  if ((c == rules->op[0]) || (c == rules->op[1]))
    return (1);
  else
    return (0);
}

int	is_digit(t_rules *rules, char c)
{
  if ((c > 47) && (c < 58))
    return (0);
  return (1);
}

int	is_alpha(t_rules *rules, char c)
{
  if (((c > 64) && (c < 91)) || ((c > 96) && (c < 123)))
    return (0);
  return (1);
}

int	is_known(t_rules *rules, char c)
{
  int	i;

  for (i = 0; (i < rules->len_base) && (c != rules->base[i]); ++i)
    ;
  if (i == rules->len_base)
    return (0);
  else
    return (1);
}
