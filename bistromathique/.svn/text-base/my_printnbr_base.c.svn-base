/*
** my_atoi.c for my_atoi.c in ~/c/rendu/piscine/j2
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Sep 25 21:56:08 2001 jean-daniel michaud
** Last update Sun Oct 21 17:52:04 2001 jonathan mimouni
*/

#include <stdlib.h>
#include "bistromathique.h"
#include "my_printnbr_base.h"

char	*my_printnbr_base(int nbr, int lenbase, t_rules *rules)
{
  int	div;
  char  *res;
  int   i;

  div = 1;
  if (nbr < 0)
    div = -1;
  i = 0;
  while ((nbr / div) >= lenbase)
    {
      div *= lenbase;
      ++i;
    }
  res = malloc(i * sizeof (char));
  if (nbr < 0)
    {
      res[0] = rules->op[1];
      i = 1;
    }
  else
    i = 0;
  for (; ((div >= 1) || (div <= -1)); nbr %= div, div /= lenbase, ++i)
    res[i] = rules->base[nbr / div];
  res[i] = '\0';
  return (res);
}




