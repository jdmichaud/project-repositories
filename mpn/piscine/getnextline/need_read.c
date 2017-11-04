/*
** need_read.c for read_need in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Oct  6 23:26:37 2001 jean-daniel michaud
** Last update Sun Oct  7 11:11:45 2001 jean-daniel michaud
*/

#include "get_next_line.h"

unsigned int	need_read(char *buf)
{
  int		i;

  if (!buf)
    return (1);
  for (i = 0; ((buf[i] != '\0') && (buf[i] != '\n')); ++i)
    ;
  if (buf[i] == '\0')
    return (1);
  else
    return (0);
}
