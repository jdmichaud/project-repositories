/*
** my_fopen.c for libstream in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Oct 11 08:59:44 2001 jean-daniel michaud
** Last update Tue Oct 23 21:36:08 2001 Jean-Daniel Michaudf
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "defines.h"
#include <stdio.h>
#include "libstream.h"

my_file		*create_file(int fd, int right)
{
  my_file	*file;
  
  file = malloc(sizeof (my_file));
  file->fd = fd;
  file->inbuf = malloc(MY_READ_SIZE * sizeof (char));
  file->inbuf_pos = MY_READ_SIZE;
  file->outbuf = malloc(MY_WRITE_SIZE * sizeof (char));
  file->outbuf_pos = 0;
  file->eof = 0;
  file->right = right;
  file->offset = 0;
  if (right & O_APPEND)
    /*file->offset = */lseek(file->fd, 0, SEEK_END);
  return (file);
}

my_file	*my_fopen(const char *path, const char *mode)
{
  int	fd;
  int	right;
  
  errno = right = fd = 0;
  if (mode[0] == 'r')
    right = O_RDONLY;
  if (mode[0] == 'r' && mode[my_strlen(mode) - 1] == '+')
    right = O_RDWR;
  if (mode[0] == 'w')
    right = O_WRONLY | O_CREAT;
  if (mode[0] == 'w' && mode[my_strlen(mode) - 1] == '+')
    right = O_RDWR|O_CREAT;
  if (mode[0] == 'a')
    right = O_WRONLY|O_APPEND|O_CREAT;
  if (mode[0] == 'a' && mode[my_strlen(mode) - 1] == '+')
    right = O_RDWR|O_APPEND|O_CREAT;
  fd = open(path, right, 0666);
  if (fd == -1)
    {
      errno = EINVAL;
      return (NULL);
    }
  return (create_file(fd, right));
}
