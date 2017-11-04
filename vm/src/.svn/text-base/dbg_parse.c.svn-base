/*
** parse_cmd.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Wed Jan  9 18:37:12 2002 julien gein
** Last update Fri Jan 11 16:17:39 2002 romain bottier
*/

#include <stdlib.h>
#include "data_struct.h"
#include "my_struct.h"
#include "my.h"
#include "dbg.h"
#include "dbg_cmd.h"
#include "my_print_error.h"
#include "dbg_parse.h"

const t_cmd	commands[] =
{
  {"dump", "dump", {1, 1, 1}, DUMP_MSG, dbg_dump},
  {"help", "h", {0, 0, 0}, H_MSG, dbg_help},
  {"info", "i", {0, 0, 0}, I_MSG, dbg_info},
  {"listchilds", "lc", {0, 0, 0}, LC_MSG, dbg_list_child},
  {"next", "n", {0, 1, 1}, N_MSG, dbg_next},
  {"player", "pl", {1, 1, 1}, PLAYER_MSG, dbg_player},
  {"print", "p", {0, 1, 2}, P_MSG, dbg_print},
  {"purchase", "prc", {0, 0, 0}, PRC_MSG, dbg_purchase},
  {"quit", "q", {0, 0, 0}, Q_MSG, dbg_quit},
  {"showmem", "sh", {0, 2, 2}, SH_MSG, dbg_sm},
  {0, 0, {0, 0, 0}, 0, 0}
};

static void	spcjump(char **s)
{
  while (**s && (**s == ' ' || **s == '\t' || **s == '\n'))
    (*s)++;
}

char		*cmd_gettk(char **s)
{
  char		*save;
  char		*res;
  
  spcjump(s);
  for (save = *s; **s &&
	 !(**s == ' ' || **s == '\t' || **s == '\n');
       (*s)++)
    ;
  if (*s == save)
    return (0);
  res = xmalloc(sizeof (char) * (*s - save + 1));
  my_strncpy(res, save, *s - save);
  res[*s - save] = '\0';
  spcjump(s);
  return (res);
}

unsigned int	test_cmd(char *cmd, unsigned int i)
{
  return (!my_strcmp(cmd, commands[i].name) ||
	  !my_strcmp(cmd, commands[i].alias));
}

unsigned int	test_args(char *cmd, t_list *list, unsigned int *idx)
{
  for (*idx = 0; commands[*idx].name && !test_cmd(cmd, *idx); (*idx)++)
    ;
  if (!commands[*idx].name)
    {
      my_print_error("Unknown Command \'%s\'\n", cmd);
      return (ERR_UNKCMD);
    }
  if (commands[*idx].nb_args[0] != list_size(list) &&
      commands[*idx].nb_args[1] != list_size(list) &&
      commands[*idx].nb_args[2] != list_size(list))
    {      
      my_print_error("Invalid number of arguments in function \'%s\'\n", cmd);
      my_print_error("Usage: %s\n", commands[*idx].help);
      return (ERR_NBARGS);
    }
  return (0);
}

void		cmd_parseline(t_vm *v, char *s)
{
  char		*save;
  t_list	*res;
  char		*ntk;
  unsigned int	idx;
  
  if (!s || !*s)
    return ;
  for (res = 0, save = s; (ntk = cmd_gettk(&s)); )
    list_append(&res, ntk);
  free(save);
  if (!test_args(res->elem, res->next, &idx))
    commands[idx].cmd(v, res->next);
  free(res->elem);
  list_free(&res);
}
     
