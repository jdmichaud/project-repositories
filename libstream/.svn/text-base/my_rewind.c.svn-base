/*
** my_rewind.c for libstream in 
** 
** Made by Jean-Daniel Michaudf
** Login   <jedi@epita.fr>
** 
** Started on  Mon Oct 15 23:02:40 2001 Jean-Daniel Michaudf
** Last update Tue Oct 23 21:28:08 2001 Jean-Daniel Michaudf
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "defines.h"
#include <stdio.h>
#include "libstream.h"

void	my_rewind(my_file *stream)
{
  errno = 0;
  if (stream->outbuf_pos > 0)
    my_fflush(stream);
  stream->inbuf_pos = MY_READ_SIZE;
  stream->offset = lseek(stream->fd, 0, SEEK_SET);
}
