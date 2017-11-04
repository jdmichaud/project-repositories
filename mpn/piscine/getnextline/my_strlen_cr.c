/*
** my_strlen_cr.c for my_strlen_cr in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Oct  6 23:24:35 2001 jean-daniel michaud
** Last update Sun Oct  7 11:12:39 2001 jean-daniel michaud
*/

#include "get_next_line.h"

unsigned int	my_strlen_cr(char *str)
{
  unsigned int	i;

  if (!str)
    return (0);
  for (i = 0; ((str[i] != '\0') && (str[i] != '\n')); ++i)
    ;
  return (i);
}
