/*
** my_fgets.c for libstream in 
** 
** Made by Jean-Daniel Michaudf
** Login   <jedi@epita.fr>
** 
** Started on  Thu Oct 11 21:05:03 2001 Jean-Daniel Michaudf
** Last update Tue Oct 23 23:00:37 2001 Jean-Daniel Michaudf
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "defines.h"
#include <stdio.h>
#include "libstream.h"

int	reload(my_file *stream)
{
  int	j;
  char	*buf;

  if (stream->outbuf_pos > 0)
    my_fflush(stream);
  j = read(stream->fd, stream->inbuf, MY_READ_SIZE);
  stream->inbuf_pos = 0;
  if (j < MY_READ_SIZE)
    {
      buf = stream->inbuf;
      buf[j] = MY_EOF;
      stream->eof = 1;
      fflush(stdout);
    }
  stream->eof = 0;
  return (j);
}

void	tabcpy(char *dst, char *src, int size)
{
  int	i;

  for (i = 0; i < size; ++i)
    dst[i] = src[i];
  src[i] = '\0';
  free(src);
}

char	*do_my_fgets(char *str, int size, my_file *stream)
{
  int	i;
  int	j;
  char	*buf;
  char	*tmp;
  
  tmp = malloc(size * sizeof (char));
  buf = stream->inbuf;
  i = 0;
  while ((i < size - 1) && (!stream->eof) && (buf[stream->inbuf_pos] != '\n')
	 && (buf[stream->inbuf_pos] != MY_EOF))
    {
      if (stream->inbuf_pos >= MY_READ_SIZE)
	j += reload(stream);
      for (errno = 0; ((i < size - 1) && (stream->inbuf_pos < MY_READ_SIZE) 
		       && (buf[stream->inbuf_pos] != '\n')
		       && (buf[stream->inbuf_pos] != MY_EOF)); 
	   ++i, ++stream->inbuf_pos/*, ++stream->offset*/)
	tmp[i] = buf[stream->inbuf_pos];
    }
  if (i < (size - 1))
    free(tmp);
  if (i < (size - 1))
    return (NULL);
  tabcpy (str, tmp, size - 1);
  return (str);
}

char	*my_fgets(char *str, int size, my_file *stream)
{
  if (!(stream->right & O_WRONLY) || (stream->right & O_RDWR))
    {
      if (stream->outbuf_pos > 0)
	my_fflush(stream);
      return(do_my_fgets(str, size, stream));
    }
  errno = EBADF;
  return (NULL);
}




