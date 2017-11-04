/*
** my_fpurge.c for libstream in 
** 
** Made by Jean-Daniel Michaudf
** Login   <jedi@epita.fr>
** 
** Started on  Mon Oct 15 23:01:49 2001 Jean-Daniel Michaudf
** Last update Tue Oct 23 21:23:48 2001 Jean-Daniel Michaudf
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "defines.h"
#include <stdio.h>
#include "libstream.h"

int	my_fpurge(my_file *stream)
{
  errno = 0;
  if (!stream)
    {
      errno = EBADF;
      return (MY_EOF);
    }
  free(stream->outbuf);
  free(stream->inbuf);
  stream->outbuf = malloc(MY_WRITE_SIZE);
  stream->outbuf = malloc(MY_READ_SIZE);
  /*stream->offset = lseek(stream->fd, 0, SEEK_CUR);*/
  return (0);
}
