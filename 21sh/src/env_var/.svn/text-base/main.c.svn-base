/*
** main.c for  in 
** 
** Made by Actarus Acta
** Login   <Actarus@epita.fr>
** 
** Started on  Fri Nov 30 19:08:33 2001 Actarus Acta
** Last update Mon Dec 31 10:51:16 2001 jonathan mimouni
*/

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "env_var_parser.h"
#include "env_var_parser_2.h"

void		simple_set_export()
{
  t_command	*cmd;

  cmd = malloc(sizeof (t_command));
  cmd->argc = 1;
  cmd->argv = malloc(1 * sizeof(char*));
  cmd->argv[0] = "set";
  printf("---------------- set OK --------------\n");
  fgetc(stdin);
  parser_env_var_set(cmd);
  cmd = malloc(sizeof (t_command));
  cmd->argc = 1;
  cmd->argv = malloc(1 * sizeof(char*));
  cmd->argv[0] = "export";
  parser_env_var_export(cmd);
  free(cmd);
  printf("---------------- export OK --------------\n");
  fgetc(stdin);
}

int	main()
{
  int	i;
  t_command		*cmd;

  simple_set_export();
  cmd = malloc(sizeof(t_command));
  cmd->argc = 5;
  cmd->argv = malloc(5 * sizeof(char*));
  cmd->argv[0] = "export";
  cmd->argv[1] = "x=10"; 
  cmd->argv[2] = "y="; 
  cmd->argv[3] = "z=zzz"; 
  cmd->argv[4] = "zz"; 
  parser_env_var_export(cmd); 
  printf("---------- print list after export x, y, z, zz -------\n");
  fgetc(stdin);
  list_env_var_print(0);
  /*
  cmd = malloc(sizeof(t_command));
  cmd->argc = 4;
  cmd->argv = malloc(4 * sizeof(char*));
  cmd->argv[0] = "unset";
  cmd->argv[1] = "x";
  cmd->argv[2] = "y";
  cmd->argv[3] = "z";
  parser_env_var_unset(&list, cmd);
  printf("---------- print list after unset x, y, z-------\n");*/
  fgetc(stdin);
  printf("---------- set -------\n");
  list_env_var_print(0);
  fgetc(stdin);
  printf("---------- export-------\n");
  list_env_var_print(1);
  return (0);
}




