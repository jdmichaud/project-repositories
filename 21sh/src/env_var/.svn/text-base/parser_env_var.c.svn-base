/*
** env_var.c for  in 
** 
** Made by Actarus Acta
** Login   <Actarus@epita.fr>
** 
** Started on  Fri Dec  7 22:59:39 2001 Actarus Acta
** Last update Mon Dec 31 13:59:46 2001 jean-daniel michaud
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "struct.h"
#include "env_var_parser.h"
#include "env_var_parser_2.h"
#include "my_malloc.h"

extern char	**environ;

int	parser_env_var_set(t_command *cmd)
{
  int	i;
  int	err;

  if (cmd->argc == 1)
    list_env_var_print(0);
  else
    {
      for (i = 1; (i < cmd->argc) && (err = putenv(cmd->argv[i]) != -1); ++i)
	;
      if (err == -1)
	fprintf(stderr, "Invalid operation: %s\n", cmd->argv[i]);
    }
  return (0);
}

int	parser_env_var_export(t_command *cmd)
{
  int	i;
  int	err;

  if (cmd->argc == 1)
    list_env_var_print(1);
  else
    {
      for (i = 1, err = 0; (i < cmd->argc) && (err != -1); ++i)
	err = environ_export(cmd->argv[i]);
      if (err == -1)
	fprintf(stderr, "Invalid operation: %s\n", cmd->argv[i]);
    }
  return (0);
}


int	parser_env_var_unset(t_command *cmd)
{
  int	i;
#ifndef __NetBSD
  int	len;
  char	*tmp;
#endif

  for (i = 1; (i < cmd->argc); ++i)
    {
#ifdef __NetBSD
      unsetenv(cmd->argv[i]);
#else
      len = strlen(cmd->argv[i]);
      tmp = my_malloc(len + 2);
      tmp = strcpy(tmp, cmd->argv[i]);
      tmp[len] = '=';
      tmp[len + 1] = '\0';
      putenv(tmp);
      free(tmp);
#endif
    }
  return (0);
}

int	format_env_var(t_command *cmd)
{
  char	**argv;

  argv = my_malloc(3 * sizeof (char *));
  argv[0] = strdup("export");
  argv[1] = strdup(cmd->argv[0]);
  argv[2] = NULL;
  free(cmd->argv[0]);
  free(cmd->argv);
  cmd->argv = argv;
  cmd->argc = 2;
  return (parser_env_var_export(cmd));
}





