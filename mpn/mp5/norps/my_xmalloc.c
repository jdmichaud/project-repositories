/*
** my_xmalloc.c for sploum in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Nov 22 21:14:52 2001 jean-daniel michaud
** Last update Sat Dec  1 10:55:12 2001 jean-daniel michaud
*/

#include <curses.h>
#include <stdlib.h>

#include "my_xmalloc.h"

void	*xmalloc(unsigned int size)
{
  void	*ptr;

  if ((ptr = malloc(size)) == NULL)
    {
      printf("Not enougth memory.\n");
      exit(2);
    }
  return (ptr);
}
