/*
** my_strupcase.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Mon Oct  1 20:20:09 2001 GIZMO
** Last update Sun Nov 11 22:34:22 2001 GIZMO
*/

#include "my.h"

void	my_strupcase(char *dest, char *src)
{
  while (*src != '\0')
    {
      if ((*src >= 'a') && (*src <= 'z'))
	*dest++ = *src++ + 'A' - 'a';
      else
	*dest++ = *src++;
    }
  *dest = '\0';
}
