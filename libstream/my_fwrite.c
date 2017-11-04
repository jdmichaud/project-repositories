/*
** my_fwrite.c for libstream in 
** 
** Made by Jean-Daniel Michaudf
** Login   <jedi@epita.fr>
** 
** Started on  Mon Oct 15 23:02:28 2001 Jean-Daniel Michaudf
** Last update Tue Oct 23 23:05:04 2001 Jean-Daniel Michaudf
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "defines.h"
#include <stdio.h>
#include "libstream.h"

size_t		my_fwrite(const void	*ptr, 
			  size_t	size, 
			  size_t	nmemb, 
			  my_file	*stream)
{
  int		i;
  char		*buf;
  const char	*buf2;
  
  if ((stream->right & O_WRONLY) || (stream->right & O_RDWR))
    {
      errno = 0;
      buf = stream->outbuf;
      buf2 = ptr;
      i = 0;
      while (i < (size * nmemb))
	{
	  if (stream->outbuf_pos >= MY_WRITE_SIZE)
	    my_fflush(stream);
	  for (; ((i < (size * nmemb)) && (stream->outbuf_pos < MY_WRITE_SIZE)
		  && (stream->outbuf_pos < MY_WRITE_SIZE));
	       ++i, ++stream->outbuf_pos/*, ++stream->offset*/)
	    buf[stream->outbuf_pos] = buf2[i]; 
	}
      return (nmemb);
    }
  errno = EBADF;
  return (MY_EOF);
}





