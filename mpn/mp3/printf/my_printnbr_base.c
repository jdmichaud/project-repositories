/*
** my_atoi.c for my_atoi.c in ~/c/rendu/piscine/j2
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Sep 25 21:56:08 2001 jean-daniel michaud
** Last update Sun Nov  4 18:44:34 2001 jean-daniel michaud
*/

#include <stdarg.h>

#include "my_printnbr.h"
#include "my_printnbr_base.h"

int	my_printnbr_base(unsigned int nbr, char *base)
{
  int	size_base;
  int	temp;
  int	div;
  int	i;

  for (i = 0, size_base = 0; base[size_base] != 0; ++size_base)
    ;
  div = 1;
  while ((nbr / div) >= size_base)
    div *= size_base;
  while ((div >= 1) || (div <= -1))
  {
    temp = base[nbr / div] - 48;
    my_printdigit(temp);
    ++i;
    nbr %= div;
    div /= size_base;
  }
  return (i);
}
