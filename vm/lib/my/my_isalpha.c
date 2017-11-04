/*
** my_isalpha.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Mon Oct  1 19:26:43 2001 GIZMO
** Last update Sun Nov 11 22:32:43 2001 GIZMO
*/

#include "my.h"

int	my_isalpha(int c)
{
  if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
    return (c);
  return (0);
}
