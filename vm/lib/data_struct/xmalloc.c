/*
** xmalloc.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Fri Oct 26 11:48:40 2001 julien gein

*/

#include <stdlib.h>
#include <unistd.h>

void	*xmalloc(int size)
{
  void	*res;
  
  if (!(res = malloc(size)))
    {
      write(2, "Impossible to malloc.", 21);
      exit(3);
    }
  return (res);
}
