/*
** my_power.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Wed Sep 26 21:13:41 2001 GIZMO
** Last update Sun Nov 11 21:59:45 2001 GIZMO
*/

#include "my.h"

int	my_power(int n, unsigned int p)
{
  if (p == 0)
    return (1);
  else
    return (n * my_power(n, p - 1));
}
