/*
** my_atoi_base.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Sep 27 08:43:10 2001 GIZMO
** Last update Sun Nov 11 21:55:40 2001 GIZMO
*/

#include "my.h"

int     my_atoi_base(char *str, char *base)
{
  int	i;
  int	nb;
  int	sign;
  int	len;
  
  nb = 0;
  sign = 1;
  len = my_strlen(base);
  if (*str == '-')
    {
      sign = -1;
      str++;
    }
  while (*str != '\0')
    {
      i = 0;
      while (*str != base[i])
	i++;
      nb = (nb * len) + i;
      str++;
    }
  return (nb * sign);
}



