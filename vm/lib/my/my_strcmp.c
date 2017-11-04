/*
** my_strcmp.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Nov  8 00:46:56 2001 GIZMO
** Last update Thu Jan  3 14:49:26 2002 GIZMO
*/

#include "my.h"

int		my_strcmp(const char *s1, const char *s2)
{
  const char	*tmp1;
  const char	*tmp2;
  
  tmp1 = s1;
  tmp2 = s2;
  while (*tmp1 && *tmp2 && *tmp1 == *tmp2)
    {
      tmp1++;
      tmp2++;
    }
  return (*tmp1 - *tmp2);
}
