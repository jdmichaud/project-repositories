/*
** my_fseek.c for libstream in 
** 
** Made by Jean-Daniel Michaudf
** Login   <jedi@epita.fr>
** 
** Started on  Mon Oct 15 23:02:03 2001 Jean-Daniel Michaudf
** Last update Tue Oct 23 21:25:18 2001 Jean-Daniel Michaudf
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "defines.h"
#include <stdio.h>
#include "libstream.h"

int	my_fseek(my_file *stream, long offset, int whence)
{
  errno = 0;
  if (stream->outbuf_pos > 0)
    my_fflush(stream);
  if (!(whence == SEEK_SET) && !(whence == SEEK_END) && !(whence == SEEK_CUR))
    {
      errno = EINVAL;
      return (-1);
    }
  /*stream->offset = */lseek(stream->fd, offset, whence);
  stream->eof = 0;
  stream->inbuf_pos = MY_WRITE_SIZE;
  return (0);
}
