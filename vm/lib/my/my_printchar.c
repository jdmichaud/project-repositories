/*
** my_printchar.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Tue Sep 25 20:42:29 2001 GIZMO
** Last update Tue Nov  6 19:11:48 2001 GIZMO
*/

#include <unistd.h>
#include "my.h"

void    my_printchar(char c)
{
  write(1, &c, 1);
}

