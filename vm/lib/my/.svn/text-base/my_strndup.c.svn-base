/*
** my_strndup.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Tue Nov  6 19:17:18 2001 GIZMO
** Last update Tue Nov  6 19:17:32 2001 GIZMO
*/

#include "my.h"

char	*my_strndup(char *str, int len)
{
  char	*buff;
  int	i;
  
  buff = my_xmalloc((len + 1) * sizeof (char));
  i = 0;
  while (i < len)
    {
      buff[i] = str[i];
      i++;
    }
  buff[len] = '\0';
  return (buff);
}
