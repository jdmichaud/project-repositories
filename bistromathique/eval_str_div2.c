/*
** eval_str_div2.c for bistromathique in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Oct 27 22:44:58 2001 jean-daniel michaud
** Last update Sun Oct 28 15:49:30 2001 jean-daniel michaud
*/

#include <stdlib.h>
#include "bistromathique.h"
#include "utils_str.h"
#include "eval_str_div2.h"
#include "eval_str_sub2.h"

int	its_end(char **res, char *div, t_rules *rules, char *divseur)
{
  int	i;
  int	j;
  char	*r;
  char	**t;
  
  if (div[0] != rules->base[0])
    return (1);
  for (i = 1; (div[i] == rules->base[0]) && (div[i] != '\0'); ++i)
      ;
  if ((div[i] != '\0') || ((div[i] == '\0') && (i == 1)))
    return (1);
  r = malloc((my_strlen(*res) + i + 1) * sizeof (char));
  t = malloc(2 * sizeof (char *));
  for (j = 0; (*res)[j] != '\0'; ++j)
    r[j] = (*res)[j];
  for (; j < i - 1; ++j)
    r[j] = rules->base[0];
  r[j] = '\0';
  free(*res);
  *res = r;
  my_revstr(t[1] = malloc((my_strlen(*res) + 1) * sizeof (char)), *res);
  my_revstr(t[0] = malloc((my_strlen(divseur) + 1) * sizeof (char)), divseur);
  if (sup(t[0], t[1], rules->base))
    return (1);
  return (0);
}

void	rest(char **res, char *tmp, t_rules *rules)
{
  int	j;
  int	i;
  char	*r;

  r = malloc((my_strlen(*res) + my_strlen(tmp)) * sizeof (char));
  for (j = 0; (*res)[j] != '\0'; ++j)
    r[j] = (*res)[j];
  for (i = 1; tmp[i] != '\0'; ++i)
    r[i] = rules->base[0];
  r[i] = '\0';
  free(*res);
  *res = r;
}
