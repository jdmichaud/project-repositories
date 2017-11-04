/*
** get_option.c for mini-ls in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Oct 18 15:08:41 2001 jean-daniel michaud
** Last update Tue Nov 20 00:43:29 2001 jean-daniel michaud
*/

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

#include "get_option.h"
#include "mini-ls.h"
#include "error.h"

int	which_option(char c)
{
  if (c == 'l')
    return(LONG_FORMAT);
  else
    if (c == 'a')
      return (HIDE_FILE);
    else
      if (c == 'A')
	return (NO_SPEC_DIR);
      else
	if (c == 'R')
	  return (RECUR_LS);
  IllOptn(c);
  return (error(1));
}

int	get_option(char **cmd)
{
  int	i;
  int	j;
  int	option;

  option = 0;
  for (i = 1; cmd[i] != NULL; ++i)
    if (cmd[i][0] == '-')
      for (j = 1; cmd[i][j] != '\0'; j++)
	option |= which_option(cmd[i][j]);
  return (option);
}

DIR	*get_name(char **cmd)
{
  int	i;
  char	*filename;

  filename = NULL;
  for (i = 1; ((cmd[i] != NULL) && (!filename)); ++i)
    {
      if (cmd[i][0] != '-')
	filename = cmd[i];
    }
  return (open_dir(filename));
 }

DIR	*open_dir(char *filename)
{
  DIR	*dir;

  if (filename)
    { 
      dir = opendir(filename);
      if (!dir)
	{
	  if (errno == ENOENT)
	    NoFile(filename);
	  if (errno == EACCES)
	    NoPerm(filename);
	}
      return (dir);  
    } 
  else
    { 
      dir = opendir("./");
      return (dir);  
    } 
}
