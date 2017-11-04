/*
** my_fclose.c for libstream in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Oct 11 10:23:43 2001 jean-daniel michaud
** Last update Tue Oct 23 23:11:27 2001 Jean-Daniel Michaudf
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "defines.h"
#include <stdio.h>
#include "libstream.h"

int	my_fclose(my_file *stream)
{
  int	i;

  errno = 0;
  if (stream->outbuf_pos > 0) 
    my_fflush(stream);
  i = close(stream->fd);
  if (stream->outbuf)
    free(stream->outbuf);
  if (stream->inbuf)
    free(stream->inbuf);
  stream->outbuf = stream->inbuf = NULL;
  if (stream)
    free(stream);
  stream = NULL;
  return (0);
}
