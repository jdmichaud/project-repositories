/*
** xmalloc.c for 21sh in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Nov 29 11:43:01 2001 jean-daniel michaud
** Last update Mon Dec 31 10:54:12 2001 Adrien Pestel
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

void	*my_malloc(unsigned int i)
{
  void  *ptr;

  if ((ptr = malloc(i)) != NULL)
    return (ptr);
  else
    exit(1);
  return (ptr);
}

char	*my_realloc(char *ptr, int new_size)
{
  char	*res;
 
  res = malloc(new_size);
  if (ptr)
  {
    strcpy(res, ptr);
    free(ptr);
  }
  return (res);
}

void	my_free(void *pa, void *pb, void *pc, void *pd)
{
  if (pa != NULL)
    free(pa);
  if (pb != NULL)
    free(pb);
  if (pc != NULL)
    free(pc);
  if (pd != NULL)
    free(pd);
}
