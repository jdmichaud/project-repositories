/*
** my_ftell.c for libstream in 
** 
** Made by Jean-Daniel Michaudf
** Login   <jedi@epita.fr>
** 
** Started on  Mon Oct 15 23:02:18 2001 Jean-Daniel Michaudf
** Last update Tue Oct 23 21:27:29 2001 Jean-Daniel Michaudf
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include "defines.h"
#include "libstream.h"

long	my_ftell(my_file *stream)
{
  errno = 0;
  /*stream->offset = lseek(stream->fd, 0, SEEK_CUR);*/
  return (lseek(stream->fd, 0, SEEK_CUR));
}
