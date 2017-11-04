/*
** my_fflush.c for libstream in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Oct 11 10:33:32 2001 jean-daniel michaud
** Last update Tue Oct 23 23:02:24 2001 Jean-Daniel Michaudf
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "defines.h"
#include <stdio.h>
#include "libstream.h"

int	my_fflush(my_file *stream)
{
  int	i;
  char *buf;

  errno = 0;
  buf = stream->outbuf;
  if (stream->outbuf)
    {
      i = write(stream->fd, stream->outbuf, stream->outbuf_pos);
      stream->outbuf_pos = 0;
    }
  return (NULL);
}
