/*
** my_atoi.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Tue Sep 25 21:56:10 2001 GIZMO
** Last update Sun Nov 11 22:07:19 2001 GIZMO
*/

#include "my.h"

int		my_atoi(char *str)
{
  unsigned int	i;
  int		res;
  int		tmp;
  
  if (*str == '-')
    return (-my_atoi(str + 1));
  if (*str == '+')
    return (my_atoi(str + 1));
  res = 0;
  tmp = 1;
  for (i = 1; i < my_strlen(str); i++)
    tmp *= 10;
  for (i = 0; i < my_strlen(str); i++)
    {
      res += tmp * (str[i] - '0');
      tmp /= 10;
    }
  return (res);
}

