/*
** my_realloc_str.c for my_realloc_str in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sun Oct  7 10:39:25 2001 jean-daniel michaud
** Last update Sun Oct  7 13:47:49 2001 jean-daniel michaud
*/

#include "get_next_line.h"
#include <stdlib.h>

char	*my_realloc_str(char *str, unsigned int size)
{
  char	*tmp;

  tmp = malloc((my_strlen_cr(str) + size) * sizeof (char));
  my_strcpy_cr(tmp, str);
  free(str);
  return (tmp);
}
