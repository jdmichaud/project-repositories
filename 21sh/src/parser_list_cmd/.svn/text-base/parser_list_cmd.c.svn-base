/*
** parser.c for  in 
** 
** Made by Jonathan APELBAUM
** Login   <apelba_j@epita.fr>
** 
** Started on  Fri Dec  7 00:22:31 2001 Jonathan APELBAUM
** Last update Mon Dec 31 14:02:18 2001 jean-daniel michaud
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
#include "redo_line.h"
#include "cmdline.h"
#include "list_cmd.h"
#include "do_struct_process.h"
#include "parser_list_cmd.h"
#include "process.h"
#include "pbuiltins.h"
#include "exec_fc.h"
#include "insert_meta.h"
#include "builtins.h"
#include "env_var_parser.h"
#include "env_var_parser_2.h"
#include "format.h"
#include "insert_meta.h"
#include "xmalloc.h"

static t_execute	non_process[NB_NON_PROCESS] =
{
  {"echo", built_echo},
  {"cd", built_cd},
  {"set", parser_env_var_set},
  {"export", parser_env_var_export},
  {"unset", parser_env_var_unset},
  {"jobs", jobs},
  {"fg", fg},
  {"bg", bg},
  {"exit", exec_exit}
};

int	is_meta(char *string)
{
  char	quote;

  for (quote = 0; string && *string; ++string)
    {
      if ((*string == '\"') || (*string == '\''))
	{
	  for (quote = *(string++); (*string) && (*string != quote); ++string)
	    ;
	  if (!*string)
	    return (-1);
	}
      if ((*string == '[') || (*string == ']'))
	return (1);
      if ((*string == '{') || (*string == '}'))
	return (1);
      if ((*string == '*') || (*string == '?'))
	return (1);
      if (*string == '\\')
	++string;
    }
  return (0);
}

void	treat_quote(t_command *cmd)
{
  int	i;
  int	j;
  int	k;
  int	len;
  char	*tmp;

  for (i = 0; i < cmd->argc; ++i)
    {
      len = strlen(cmd->argv[i]);
      if (((cmd->argv[i][0] == '"') && (cmd->argv[i][len - 1] == '"')) || 
	  ((cmd->argv[i][0] == '\'') && (cmd->argv[i][len - 1] == '\'')))
	{
	  tmp = xmalloc(sizeof (char) * (len + 1));
	  for (j = 0, k = 1; (cmd->argv[i][k] != '\0'); ++j, ++k)
	    tmp[j] = cmd->argv[i][k];
	  tmp[j - 1] = '\0';
	  free(cmd->argv[i]);
	  cmd->argv[i] = tmp;
	}
    }
}

int		exec(t_command *cmd)
{
  int		i;
  char		*frm_str;

  for (i = 1; i < cmd->argc; ++i)
    if (is_meta(cmd->argv[i]))
      i = insert_meta_in_cmd(cmd, i);
    else
      {
	frm_str = format(cmd->argv[i]);
	free(cmd->argv[i]);
	cmd->argv[i] = frm_str;
      }
  for (i = 0; (i < NB_NON_PROCESS) && 
	 (strcmp(cmd->argv[0], non_process[i].id)); ++i)
    ;
  if (i == NB_NON_PROCESS)
    if (isaffectation(cmd->argv[0]))
      return (format_env_var(cmd));
    else
      return (exec_list(cmd));
  else
    return (non_process[i].f(cmd));
}	

t_list_cmd	*get_next_list_cmd(t_list_cmd *list_cmd, int err)
{
  if (list_cmd->separator == 0)
    return (list_cmd->next); 
  if ((err != 0) && (list_cmd->separator == 1))
    for (list_cmd = list_cmd->next; (list_cmd != NULL) && 
	   (list_cmd->separator == 1);
	 list_cmd = list_cmd->next)
      ;
  else
    if ((err != 0) && (list_cmd->separator == 2))
      return (list_cmd->next);
    else    
      if (list_cmd->separator == 2)
	for (list_cmd = list_cmd->next; (list_cmd != NULL) && 
	       (list_cmd->separator == 2); 
	     list_cmd = list_cmd->next)
      ;
      else
	return (list_cmd->next);
  if (list_cmd == NULL)
    return (NULL);
  return (list_cmd->next);
}

int		parser_list_cmd(t_list_cmd *list_cmd)
{
  t_line	*line;
  char		*tmp;
  t_command	*command;
  int		err;

  for (err = 0; ((list_cmd != NULL) && (err != -1)); 
       list_cmd = get_next_list_cmd(list_cmd, err))
    {
      tmp = redo_line(list_cmd->cmd);
      line = do_list_cmd(tmp);
      command = do_struct(line);
      err = exec(command);
      free_t_line(&line);
      free(tmp);
    }
  if (err == -1)
    return (1);
  else
    return (0);
}
