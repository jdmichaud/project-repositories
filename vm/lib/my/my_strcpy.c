/*
** my_strcpy.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Nov  8 00:39:57 2001 GIZMO
** Last update Sun Nov 11 22:16:53 2001 GIZMO
*/

#include "my.h"

char	*my_strcpy(char *dest, const char *src)
{
  char	*save;
  
  save = dest;
  while (*src)
    *dest++ = *src++;
  *dest = '\0';
  return (save);
}
