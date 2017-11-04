/*
** my_isnum.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Jan  3 13:55:02 2002 GIZMO
** Last update Thu Jan  3 13:58:26 2002 GIZMO
*/

#include "my.h"

int	my_isnum(char *str)
{
  int	c;

  if (!*str)
    return (0);
  for (c = *str; *str && my_isdigit(c); c = *str++)
    ;
  return (!*str);
}

