/*
** my_printnbr.c for my_printnbr in ~/c/rendu/piscine/j2
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Sep 25 20:49:15 2001 jean-daniel michaud
** Last update Sun Nov  4 19:07:23 2001 jean-daniel michaud
*/

#include <stdarg.h>

#include "my_printnbr.h"
#include "my_printchar.h"

void    my_printdigit(int d)
{
  my_printchar('0' + d);
}

int	my_printnbr(va_list *arg)
{
  int	nbr;
  int	div;
  int	temp;
  int	i;

  nbr = va_arg(*arg, int);
  div = 1;
  i = 0;
  if (nbr < 0)
    {
      my_printchar('-');
      div = -1;
      ++i;
    }
  while ((nbr / div) >= 10)
    div *= 10;
  while ((div >= 1) || (div <= -1))
    {
      temp = nbr / div;
      my_printdigit(temp);
      ++i;
      nbr %= div;
      div /= 10;
    }
  return (i);
}

int		my_printnbr_unsigned(va_list *arg)
{
  int		div;
  int		temp;
  int		i;
  unsigned int	nbr;

  nbr = va_arg(*arg, unsigned int);
  div = 1;
  i = 0;
  while ((nbr / div) >= 10)
    div *= 10;
  while ((div >= 1) || (div <= -1))
    {
      temp = nbr / div;
      my_printdigit(temp);
      ++i;
      nbr %= div;
      div /= 10;
    }
  return (i);
}
