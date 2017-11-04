/*
** my_strdup.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Tue Nov  6 19:16:29 2001 GIZMO
** Last update Tue Nov  6 19:17:00 2001 GIZMO
*/

#include "my.h"

char	*my_strdup(char *str)
{
  char	*save;
  char	*buff;
  
  buff = my_xmalloc((my_strlen(str) + 1) * sizeof (char));
  save = buff;
  while (*str != '\0')
    *(buff++) = *(str++);
  *buff = '\0';
  return (save);
}
