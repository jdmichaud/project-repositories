/*
** my_fgetpos.c for libstream in 
** 
** Made by Jean-Daniel Michaudf
** Login   <jedi@epita.fr>
** 
** Started on  Tue Oct 16 00:07:56 2001 Jean-Daniel Michaudf
** Last update Thu Oct 18 12:26:40 2001 jean-daniel michaud
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "defines.h"
#include <stdio.h>
#include "libstream.h"

int	my_fgetpos(my_file *stream, fpos_t *pos)
{
  errno = 0;
  *pos = lseek(stream->fd, 0, SEEK_CUR);
  return (0);
}
