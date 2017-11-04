/*
** my_strndup_cr.c for my_strndup_cr in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Oct  6 23:25:31 2001 jean-daniel michaud
** Last update Sun Oct  7 15:21:28 2001 jean-daniel michaud
*/

#include "get_next_line.h"

char		*my_strndup_cr(char *str, int size)
{
  char		*dst;
  int		i;

  dst = malloc(size * sizeof (char));
  for (i = 0; i < (size - 1); ++i)
    dst[i] = str[i];
  dst[i] = '\0';
  return (dst);
}
