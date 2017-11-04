/*
** my_fdopen.c for libstream in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Oct 11 16:24:09 2001 jean-daniel michaud
** Last update Mon Oct 22 14:56:10 2001 jean-daniel michaud
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "defines.h"
#include <stdio.h>
#include "libstream.h"

my_file	*my_fdopen(int fildes, const char *mode)
{
  int	right;

  errno = 0;
  right = -1;
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
  if (right == -1)
  {
    errno = EINVAL;
    return (NULL);
  }
  return (create_file(fildes, right));
}
