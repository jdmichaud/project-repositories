/*
** errors.c for bistromathique in ~/c/rendu/projs/bistromathique
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  9 17:06:01 2001 jean-daniel michaud
** Last update Sat Oct 27 23:08:45 2001 jonathan mimouni
*/

#include "bistromathique.h"
#include "utils.h"
#include "list.h"
#include "free.h"
#include "errors.h"

int	verif_syntax(t_rules *rules, char *expr)
{
  if (is_hpop(rules, *expr))
    {
      if (is_lpop(rules, expr[-1]))
	return (1);
      if (expr[1] == rules->op[6])
	return (2);      
      if (is_hpop(rules, expr[1]))
	return (3);
    }
  if (is_lpop(rules, *expr))
    {
      if (expr[1] == rules->op[6])
	return (2);
      if (is_hpop(rules, expr[1]))
	return (1);
    }
  return (0);
}

void	parse_errors(t_rules *rules, char *expr)
{
  int	i;
  int	p_open;
  int	p_close;

  for (i = 0, p_open = 0, p_close = 0; expr[i] != 0; ++i)
    {
      if (expr[i] == rules->op[5])
	++p_open;
      if (expr[i] == rules->op[6])
	++p_close;
      if (verif_syntax(rules, &expr[i]))
	errors(rules, 2);
    }
  if (p_open != p_close)
    errors(rules, 0);
}

void	errors(t_rules *rules, int err)
{
  list_print(rules->tab_errors[err]);
  free_all(rules);
  exit(1);
}



