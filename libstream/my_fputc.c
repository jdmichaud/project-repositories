/*
** my_fputc.c for libstream in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Oct 11 11:36:30 2001 jean-daniel michaud
** Last update Tue Oct 23 23:04:39 2001 Jean-Daniel Michaudf
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "defines.h"
#include <stdio.h>
#include "libstream.h"

int	my_fputc(int c, my_file *stream)
{
  char	*buf;
  
  if ((stream->right & O_WRONLY) || (stream->right & O_RDWR))
    {
      errno = 0;
      if (!stream->outbuf)
	{
	  stream->outbuf_pos = 0;
	  stream->outbuf = malloc(MY_WRITE_SIZE * sizeof (char));
	}    
      buf = stream->outbuf;
      if (stream->outbuf_pos >= MY_WRITE_SIZE)
	my_fflush(stream);
      buf[stream->outbuf_pos++] = c;
      /*++stream->offset;*/
      return (c);
    }
  errno = EBADF;
  return (MY_EOF);
}
