/*
** my_fread.c for libstream in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Oct 11 14:52:05 2001 jean-daniel michaud
** Last update Tue Oct 23 23:05:32 2001 Jean-Daniel Michaudf
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "defines.h"
#include <stdio.h>
#include "libstream.h"

size_t	do_my_fread(void *ptr, size_t size, size_t nmemb, my_file *stream)
{
  int	i;
  int	j;
  char	*buf;
  char	*delamort;
  
  errno = 0;
  my_fflush(stream);
  buf = stream->inbuf;
  delamort = ptr;
  i = 0;
  j = 0;
  while ((i < (size * nmemb)) && (buf[stream->inbuf_pos] != MY_EOF))
    {
      if (stream->inbuf_pos >= MY_READ_SIZE)
	j += reload(stream);
      for (; ((stream->inbuf_pos < MY_READ_SIZE) && (i < (size * nmemb))
	      && (buf[stream->inbuf_pos] != MY_EOF));
	   ++stream->inbuf_pos, ++i/*, ++stream->offset*/)
	delamort[i] = buf[stream->inbuf_pos];
    }
  if (buf[stream->inbuf_pos] == MY_EOF)
    return (-1);
  else
    return (nmemb);
}

size_t	my_fread(void *ptr, size_t size, size_t nmemb, my_file *stream)
{
  if (!(stream->right & O_WRONLY) || (stream->right & O_RDWR))
    return (do_my_fread(ptr, size, nmemb, stream));
  errno = EBADF;
  return (MY_EOF);
}




