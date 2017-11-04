/*
** my_printnbr.c for my_printnbr in ~/c/rendu/piscine/j2
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Sep 25 20:49:15 2001 jean-daniel michaud
** Last update Wed Oct 10 16:19:05 2001 jean-daniel michaud
*/

#include "my_cat.h"

void    my_printdigit(int d)
{
  my_printchar('0' + d);
}

void	my_printnbr(int nbr)
{
  int	div;
  int	temp;

  div = 1;
  if (nbr < 0)
    {
      my_printchar('-');
      div = -1;
    }
  while ((nbr / div) >= 10)
    div *= 10;
  while ((div >= 1) || (div <= -1))
  {
    temp = nbr / div;
    my_printdigit(temp);
    nbr %= div;
    div /= 10;
  }
}
