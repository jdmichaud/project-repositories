/*
** read_block.h for block_read in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Oct  6 23:27:33 2001 jean-daniel michaud
** Last update Sun Oct  7 15:21:52 2001 jean-daniel michaud
*/

#include "get_next_line.h"

char		*read_block(int fd)
{
  ssize_t	i;
  char		*buf;

  i = 0;
  buf = malloc((READ_SIZE + 1) * sizeof (char));
  i = read(fd, buf, READ_SIZE);
  if (i <= 0)
    return (NULL);
  buf[i + 1] = '\0';
  return (buf);
}
