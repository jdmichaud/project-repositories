/*
** my_strcpy_cr.c for my_strcpy_cr in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Oct  6 23:29:29 2001 jean-daniel michaud
** Last update Sun Oct  7 14:04:05 2001 jean-daniel michaud
*/

#include "get_next_line.h"

void	my_strcpy_cr(char *dst, char *src)
{
  int	i;

  if ((!src) || (!dst))
    return;
  for (i = 0; ((src[i] != '\0') && (src[i] != '\n')); ++i)
    dst[i] = src[i];
  dst[i] = '\0';
}
