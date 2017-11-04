/*
** utils3.c for bistromathique in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Oct 27 18:06:12 2001 jean-daniel michaud
** Last update Sat Oct 27 18:24:47 2001 jean-daniel michaud
*/

#include <stdlib.h>
#include "utils3.h"

void	free_p(char *a, char *b, char *c, char *d)
{
  if (a)
    free(a);
  if (b)
    free(b);
  if (c)
    free(c);
  if (d)
    free(d);
}
