/*
** my_atoi.c for my_atoi.c in ~/c/rendu/piscine/j2
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Sep 25 21:56:08 2001 jean-daniel michaud
** Last update Mon Nov 19 21:33:25 2001 jean-daniel michaud
*/

#include <stdarg.h>

#include "my_printfnbr.h"
#include "my_printfnbr_base.h"

int	my_printfnbr_base(unsigned int nbr, char *base)
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
    my_printfdigit(temp);
    ++i;
    nbr %= div;
    div /= size_base;
  }
  return (i);
}






