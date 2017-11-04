/*
** echo.c
**
** Made by (Adrien Pestel)
** Login   <pestel_a@epita.fr>
** 
** Started on  Wed Dec  5 01:03:35 2001 Adrien Pestel
** Last update Mon Dec 31 05:04:21 2001 Adrien Pestel
*/

#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "builtins.h"

int		built_echo(t_command *cmd)
{
  int		i;
  char		**argv;

  argv = cmd->argv;
  if (argv && argv[1])
    {
      if (!strcmp(argv[1], "-n"))
	i = 2;
      else
	i = 1;
      for (; argv[i]; ++i)
	{
	  fprintf(stdout, "%s", argv[i]);
	  if (argv[i + 1])
	    fprintf(stdout, " ");
	}
    }
  if (!argv[1] || ((argv[1]) && (strcmp(argv[1], "-n"))))
  {
    fprintf(stdout, "\n");
    return (1);
  }
  return (0);
}
