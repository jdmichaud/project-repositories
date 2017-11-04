/*
** my_xmalloc.c for sploum in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Nov 22 21:14:52 2001 jean-daniel michaud
** Last update Sun Nov 25 10:43:23 2001 jean-daniel michaud
*/

#include <curses.h>
#include <stdlib.h>

#include "my_xmalloc.h"

void	*my_xmalloc(unsigned int size)
{
  void	*ptr;

  if ((ptr = malloc(size)) == NULL)
    {
      beep();
      endwin();
      printf("Not enougth memory.\n");
      exit(2);
    }
  return (ptr);
}
