/*
** my_fputs.c for libstream in 
** 
** Made by Jean-Daniel Michaudf
** Login   <jedi@epita.fr>
** 
** Started on  Thu Oct 11 23:24:40 2001 Jean-Daniel Michaudf
** Last update Tue Oct 23 23:04:32 2001 Jean-Daniel Michaudf
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "defines.h"
#include <stdio.h>
#include "libstream.h"

int	my_fputs(const char *str, my_file *stream)
{
  int	i;
  char	*buf;

  if ((stream->right & O_WRONLY) || (stream->right & O_RDWR))
    {
      errno = 0;
      buf = stream->outbuf;
      i = 0;
      while (str[i] != '\0')
	{
	  if (stream->outbuf_pos >= MY_WRITE_SIZE)
	    my_fflush(stream);
	  for (; ((str[i] != '\0') && (stream->outbuf_pos < MY_WRITE_SIZE));
	       ++i, ++stream->outbuf_pos/*, ++stream->offset*/)
	    buf[stream->outbuf_pos] = str[i];
	}
      return (0);
    }
  errno = EBADF;
  return (MY_EOF);
}
