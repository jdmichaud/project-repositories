/*
** my_strlowcase.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Mon Oct  1 20:39:54 2001 GIZMO
** Last update Sun Nov 11 22:34:10 2001 GIZMO
*/

#include "my.h"

void	my_strlowcase(char *dest, char *src)
{
  while (*src != '\0')
    {
      if ((*src >= 'A') && (*src <= 'Z'))
	*dest++ = *src++ + 'a' - 'A';
      else
	*dest++ = *src++;
    }
  *dest = '\0';
}
