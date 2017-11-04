/*
** get_type.c for mini-ls in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Nov 14 15:47:35 2001 jean-daniel michaud
** Last update Sun Nov 25 20:11:58 2001 jean-daniel michaud
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

#include "get_type.h"

int		is_file(char *path)
{
  struct stat	*sb; 
  char		*tmp;
  int		ret;

  sb = malloc(sizeof (struct stat));
  tmp = strdup(path);
  lstat(tmp, sb);
  free(tmp);
  ret = ((sb->st_mode & S_IFMT) == S_IFREG);
  free(sb);
  return (ret);
}

int		is_directory(char *path)
{
  struct stat	*sb; 
  char		*tmp;
  int		ret;

  sb = malloc(sizeof (struct stat));
  tmp = strdup(path);
  lstat(tmp, sb);
  free(tmp);
  ret = ((sb->st_mode & S_IFMT) == S_IFDIR);
  free(sb);
  return (ret);
}

int		is_link(char *path)
{
  struct stat	*sb; 
  char		*tmp;
  int		ret;

  sb = malloc(sizeof (struct stat));
  tmp = strdup(path);
  lstat(tmp, sb);
  free(tmp);
  ret = ((sb->st_mode & S_IFMT) == S_IFLNK);
  free(sb);
  return (ret);
}
