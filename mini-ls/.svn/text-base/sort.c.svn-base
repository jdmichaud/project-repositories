/*
** sort.c for mini-ls in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Nov 14 16:06:00 2001 jean-daniel michaud
** Last update Tue Nov 20 01:22:30 2001 jean-daniel michaud
*/

#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

#include "list_file.h"
#include "list_args.h"
#include "sort.h"
#include "my_strcmp.h"

void	sort_tab(char **t)
{
  int	flag;
  int	i = 0;
  char	*tmp;

  flag = 1;
  while (flag)
    {
      flag = 0;
      for (i = 0; t[i + 1]; ++i)
	if (my_strcmp(t[i], t[i + 1]) > 0)
	  {
	    flag = 1;
	    tmp = t[i];
	    t[i] = t[i + 1];
	    t[i + 1] = tmp;
	  }
    }
}

void	purge(char *str)
{
  char	*tmp;

  while (*str)
    {
      while (*str && !(*str == '/' && *(str + 1) == '/'))
	++str;
      if (*str)
	for (tmp = str; *tmp; ++tmp)
	  *tmp = *(tmp + 1);
    }
}
