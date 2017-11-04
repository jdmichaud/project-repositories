/*
** my_freopen.c for libstream in 
** 
** Made by Jean-Daniel Michaudf
** Login   <jedi@epita.fr>
** 
** Started on  Thu Oct 11 20:24:13 2001 Jean-Daniel Michaudf
** Last update Mon Oct 22 15:46:39 2001 jean-daniel michaud
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "defines.h"
#include <stdio.h>
#include "libstream.h"


my_file	*my_freopen(const char *path, const char *mode, my_file *stream)
{
  errno = 0;
  if (my_fclose(stream) == MY_EOF)
    return (NULL);
  return (my_fopen(path, mode));
}
