/*
** my_xmalloc.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Mon Oct  8 22:55:21 2001 GIZMO
** Last update Thu Nov 29 15:00:53 2001 GIZMO
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void	*my_xmalloc(int size)
{
  void	*tmp;
  
  if ((tmp = malloc(size)) == 0)
    {
      write(2, "Error malloc\n", 13);
      exit(ERR_MALLOC);
    }
  return (tmp);
}
