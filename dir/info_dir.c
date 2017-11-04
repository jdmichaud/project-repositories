/*
** info_dir.c for dir in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Oct 17 13:06:24 2001 jean-daniel michaud
** Last update Wed Oct 17 13:36:52 2001 jean-daniel michaud
*/

#include <sys/types.h>
#include <sys/dir.h>
#include <dirent.h>
#include "info_dir.h"
#include "my_printstr.h"
#include "my_printnbr.h"


int		info_dir(char *path)
{
  DIR		*d;
  dirent	*info;

  d = opendir(path);
  info = readdir(DIR);
  my_printstr("file number of entry: ");
  my_printnbr(info->d_fileno);
  my_printstr("length of this record: ");
  my_printnbr(info->d_reclen);
  my_printstr("length of string in d_name: ");
  my_printnbr(info->d_namlen);
  my_printstr("maximum name length: ");
  my_printstr(info->d_name);
  close(DIR);
}
