/*
** my_printnbr_base.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Sep 27 08:45:02 2001 GIZMO
** Last update Sat Jan  5 22:53:17 2002 GIZMO
*/

#include "my.h"

void    my_printnbr_base(int nbr, char *base)
{
  int	len;
  int	position;
  
  if (nbr < 0)
    {
      my_printchar('-');
      nbr = -nbr;
    }
  len = 0;
  while (base[len] != '\0')
    len++;
  position = nbr % len;
  nbr = nbr / len;
  if (nbr != 0)
    my_printnbr_base(nbr, base);
  my_printchar(base[position]);
}







