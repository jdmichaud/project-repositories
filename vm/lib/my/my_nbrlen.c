/*
** my_nbrlen.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Tue Nov 13 19:55:23 2001 GIZMO
** Last update Tue Nov 13 19:55:43 2001 GIZMO
*/

#include "my.h"

int	my_nbrlen(int nbr)
{
  int	len;
  
  if (nbr == 0)
    return (1);
  for (len = 0; nbr != 0; nbr /= 10, len++)
    ;
  return (len);
}

