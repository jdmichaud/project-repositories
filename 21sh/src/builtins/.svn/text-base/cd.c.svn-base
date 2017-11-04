/*
** cd.c
**
** Made by (Adrien Pestel)
** Login   <pestel_a@epita.fr>
** 
** Started on  Wed Dec  5 01:23:10 2001 Adrien Pestel
** Last update Mon Dec 31 12:19:32 2001 Adrien Pestel
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "builtins.h"

int	built_cd(t_command *cmd)
{
  static char	last_p[255];
  char		*save;
  char		**argv;
  
  argv = cmd->argv;
  save = malloc(255 * sizeof (char));
  save = getcwd(save, 255);
  if (argv)
  {
    if (argv[1])
    {
      if (!strcmp(argv[1], "-"))
      {
	chdir(last_p);
	fprintf(stdout, "%s\n", last_p);
      }
      else
	if (chdir(argv[1]))
	{
	  fprintf(stderr, "cd: no such file or directory: %s\n", argv[1]);
	  return (1);
	}
	else
	  memcpy(last_p, save, 255);
    }
    else
      chdir(getenv("HOME"));
  }
  free(save);
  return (0);
}
