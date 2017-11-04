/*
** parser.c for bistromathique in ~/c/rendu/projs/bistromathique
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  9 17:08:05 2001 jean-daniel michaud
** Last update Sat Oct 27 11:09:46 2001 jonathan mimouni
*/

#include <stdlib.h>
#include <unistd.h>
#include "bistromathique.h"
#include "utils.h"
#include "utils2.h"
#include "parser.h"
#include "list.h"
#include "errors.h"

t_list		*find_block_error(t_rules *rules)
{
  t_list	*list;
  char		c;

  list = NULL;  
  while (((read(0, &c, 1)) == 1) && (c != '\0'))
    list_append(&list, c);
  if (c != '\0')
    {
      errors(rules, 2);
      return (NULL);
    }
  else
    return (list);
}

int	find_block_int(t_rules *rules)
{
  int	res;
  char	c;

  c = '0';
  res = 0;
  while (((read(0, &c, 1)) == 1) && (c != '\0'))
    res = res * 10 + c - '0';
  if (c == '\0')
    return (res);
  else
    {
      errors(rules, 2);
      return (NULL);  
    }
}

char	*find_block_nb(int nb, t_rules *rules)
{
  char	c;
  char	*res;
  int	i;

  res = malloc(nb + 2);
  for (i = 0; (((read(0, &c, 1)) == 1) && (i < nb)); ++i)
    res[i] = c;
  if (i == nb)
    {
      res[i] = c;
      res[i + 1] = '\0';
      return (res);
    }
  else
    {
      errors(rules, 2);
      return (NULL);
    }
}

t_rules		*parse_in()
{
  t_rules	*rules;
  int		i;
 
  i = 0;
  rules = malloc(sizeof (t_rules));
  rules->len_base = find_block_int(rules);
  rules->len_expr = find_block_int(rules);
  for (i = 0; i < 4; ++i)
    rules->tab_errors[i] = find_block_error(rules);
  rules->op = find_block_nb(6, rules); 
  rules->base = find_block_nb(rules->len_base - 1, rules);
  rules->expr = find_block_nb(rules->len_expr - 1, rules);
  rules->save_expr = rules->expr;
  rules->nb_par = 0;
  return (rules);
}

int	signe(t_rules *rules, char **strb)
{
  int	i;
  int	res;

  for (i = 0, res = 1; is_lpop(rules, **strb); ++i, ++(*strb))
    if (**strb == rules->op[1])
      res *= -1;
  if (is_hpop(rules, **strb))
    errors(rules, 2);
  else
    if (is_hpop2(rules, **strb))
      res = res * 2;
    else
      if (**strb == '\0')
	errors(rules, 2);
  return (res);
}









