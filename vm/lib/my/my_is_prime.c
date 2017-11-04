/*
** my_is_prime.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Wed Sep 26 21:17:07 2001 GIZMO
** Last update Sun Nov 11 22:07:47 2001 GIZMO
*/

#include "my.h"

unsigned int	my_is_prime(unsigned int a)
{
  unsigned int	tmp;
  
  tmp = 2;
  if (a == 1 || a == 0)
    return (0);
  while (tmp < a)
    {
      if ((a % tmp) == 0)
	return (0);
      tmp++;
    }
  return (1);
}
