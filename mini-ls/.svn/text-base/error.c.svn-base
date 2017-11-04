/*
** error.c for mini-ls in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Nov 20 00:10:55 2001 jean-daniel michaud
** Last update Tue Nov 20 00:25:16 2001 jean-daniel michaud
*/

#include <unistd.h>

#include "my_strcmp.h"
#include "error.h"

void	NoPerm(char *file)
{
  write(2, "mini-ls: ", 9);
  write(2, file, my_strlen(file));
  write(2, ": Permission denied\n", 20);
}

void	NoFile(char *file)
{
  write(2, "mini-ls: ", 9);
  write(2, file, my_strlen(file));
  write(2, ": No such file or directory\n", 28);
}

void	IllOptn(char c)
{
  write(2, "mini-ls: illegal option -- ", 27);
  write(2, &c, 1);
  write(2, "\n", 2);  
}

void	Usage(void)
{
  write(2, "usage: mini-ls [-laRA] [file ...]\n", 34);
}
