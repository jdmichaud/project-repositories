/*
** my_strncpy.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Nov  8 00:41:18 2001 GIZMO
** Last update Thu Nov  8 00:41:50 2001 GIZMO
*/

#include "my.h"

char	*my_strncpy(char *dest, const char *src, int n)
{
  char	*save;
  int	i;
  
  save = dest;
  i = 0;
  while ((*src != '\0') && (i < n))
    {
      *(dest++) = *(src++);
      i++;
    }
  return (save);
}
