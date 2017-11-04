/*
** my_printnbr.c for my_printnbr in ~/c/rendu/piscine/j2
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Sep 25 20:49:15 2001 jean-daniel michaud
** Last update Wed Nov 28 17:53:10 2001 jean-daniel michaud
*/

#include <stdarg.h>

#include "my_printfnbr.h"
#include "my_printfchar.h"

void    my_printfdigit(int d)
{
  my_printfchar('0' + d);
}

int	my_printfnbr(va_list *arg)
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
      my_printfchar('-');
      div = -1;
      ++i;
    }
  while ((nbr / div) >= 10)
    div *= 10;
  while ((div >= 1) || (div <= -1))
    {
      temp = nbr / div;
      my_printfdigit(temp);
      ++i;
      nbr %= div;
      div /= 10;
    }
  return (i);
}

int		my_printfnbr_unsigned(va_list *arg)
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
      my_printfdigit(temp);
      ++i;
      nbr %= div;
      div /= 10;
    }
  return (i);
}
