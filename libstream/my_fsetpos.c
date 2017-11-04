/*
** my_fsetpos.c for libstream in 
** 
** Made by Jean-Daniel Michaudf
** Login   <jedi@epita.fr>
** 
** Started on  Mon Oct 15 23:06:25 2001 Jean-Daniel Michaudf
** Last update Tue Oct 23 21:25:34 2001 Jean-Daniel Michaudf
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "defines.h"
#include <stdio.h>
#include "libstream.h"

int	my_fsetpos(my_file *stream, const fpos_t *pos)
{
  errno = 0;
  /*stream->offset = */lseek(stream->fd, *pos, SEEK_SET);
  return (0);
}

