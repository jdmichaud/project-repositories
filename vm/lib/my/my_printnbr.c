/*
** my_print_nbr.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Tue Sep 25 21:09:50 2001 GIZMO
** Last update Sun Nov 11 21:54:44 2001 GIZMO
*/

#include "my.h"

void	my_printnbr(int nbr)
{
  int	i;
  
  i = 1;
  if (nbr < 0)
    {
      i = -1;
      my_printchar('-');
    }
  for (; (nbr / i) >= 10; i *= 10)
    ;
  while ((i >= 1) || (i <= -1))
    {
      my_printchar('0' + nbr / i);
      nbr = nbr % i;
      i /= 10;
    }
}
