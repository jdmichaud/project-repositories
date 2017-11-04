/*
** my_fgetc.c for libstream.h in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Oct 11 14:29:41 2001 jean-daniel michaud
** Last update Tue Oct 23 23:05:43 2001 Jean-Daniel Michaudf
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "defines.h"
#include <stdio.h>
#include "libstream.h"

int	my_fgetc(my_file *stream)
{
  char	*buf;
  
  if (!(stream->right & O_WRONLY) || (stream->right & O_RDWR))
    {
      errno = 0;
      if (stream->outbuf_pos > 0)
	my_fflush(stream);
      if (stream->inbuf_pos >= MY_READ_SIZE)
	reload(stream);
      buf = stream->inbuf;
      //stream->offset += 1;
      return (buf[stream->inbuf_pos++]);
    }
  errno = EBADF;
  return (MY_EOF);
}
