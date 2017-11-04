/*
** xmalloc.c for 21sh in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Nov 29 11:43:01 2001 jean-daniel michaud
** Last update Sun Dec  9 07:35:32 2001 jean-daniel michaud
*/

#include <stdio.h>
#include <stdlib.h>

#include "xmalloc.h"

void	*xmalloc(unsigned int size)
{
  void	*ptr;

  if ((ptr = malloc(size)) == NULL)
    {
      fprintf(stderr, "Not enouth memory\n");
      exit(3);
    }
  else
    return (ptr);
}
