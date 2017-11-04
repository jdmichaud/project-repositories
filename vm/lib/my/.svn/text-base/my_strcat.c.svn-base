/*
** my_strcat.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Nov  8 00:41:59 2001 GIZMO
** Last update Thu Nov  8 00:42:58 2001 GIZMO
*/

#include "my.h"

char	*my_strcat(char *s, char *append)
{
  char	*save;
  
  save = s;
  if (s && append)
    {
      for (; *(s++) != '\0'; )
	;
      s--;
      while (*append != '\0')
	*(s++) = *(append++);
      *s = '\0';
    }
  return (save);
}
