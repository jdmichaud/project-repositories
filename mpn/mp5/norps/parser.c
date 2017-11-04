/*
** parser.c for lddump in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Nov 29 21:19:54 2001 jean-daniel michaud
** Last update Tue Dec  4 05:21:04 2001 jean-daniel michaud
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>

#include "struct.h"
#include "vars.h"
#include "libs.h"
#include "list.h"
#include "parse_func.h"
#include "parse_error.h"
#include "cmd_func.h"
#include "utils.h"
#include "my_ctype.h"
#include "my_ctype2.h"
#include "parser.h"
#include "libs_error.h"
#include "my_xmalloc.h"
#include "sub_parsing.h"
#include "format_params.h"

static t_func	tab_func[] =
{
  {open_libs},
  {close_libs},
  {show_libs},
  {show_vars},
  {unset_vars},
  {print},
  {stop}
};

int		get_first_word(char **cmd, char **word)
{
  char		c;

  c = *(*cmd)++;
  if (c == '(')
    {
      *word = get_to_next_parenthsis(cmd);
      if (get_id(*word) >= MAX_KW)
	parse_error(5);
    }
  else
    {
      c = *(*cmd)--;
      *word = get_next_word(cmd);
    }
  return (get_id(*word) + 1);
}

int		parse(t_libs **libs, t_vars **vars, char *cmd)
{
  char		*token;
  char		*v;
  int		i;
  
  if (!cmd)
    return (1);
  while (*cmd == 32)
    ++cmd;
  get_first_word(&cmd, &token);
  if (get_id(token) < MAX_FN)
    return (tab_func[get_id(token)].f(libs, vars, &cmd));
  cmd -= strlen(token) + 1;
  if ((v = is_affectation(cmd)) != NULL && is_func(*libs, cmd) > 0)
    add_vars(vars, v, function(*libs, *vars, cmd, is_func(*libs, cmd)));
  else
    if (is_func(*libs, cmd) > 0)
      (function(*libs, *vars, cmd, is_func(*libs, cmd)));
    else
      if (i == -1)
	libs_error(1);
      else
	printf("gni ?\n");
  return (1);
}

t_vars		*function(t_libs *libs, t_vars *vars, char *cmd, int type)
{
  char		*token;
  char		*sym;
  t_list	*list;

  list = NULL;
  if (*cmd == '(')
    get_to_next_parenthsis(&cmd);
  else
    {
      get_next_word(&cmd);
      get_to_next_parenthsis(&cmd);
    }
  token = get_next_word(&cmd);
  while (*cmd == ':')
    ++cmd;
  while (*cmd != '(')
    push(&list, *cmd++);
  sym = collapse(list);
  list = NULL;
  while ((*cmd != ')') && (*cmd != 0))
    push(&list, *cmd++);
  push(&list, 0);
  push(&list, 0);
  return (callf(libs, token, sym, format_params(vars, collapse(list), type)));
}

t_params	*format_params(t_vars *vars, char *cmd, int type)
{
  t_params	*params;
  char		*token;
  unsigned int	ui;
  
  params = xmalloc(sizeof (t_params));
  params->rtype = type;
  for (params->nbparams = 0, ui = 0; ui < MAX_PARAMS; ++ui)
    params->value[ui].ptr = NULL;
  while (*cmd != '(')
    ++cmd;
  ++cmd;
  for (token = gnw(&cmd); token; ++(params->nbparams), token = gnw(&cmd))
    {
      if (isnumber(token))
	get_number(params, token);
      else
	if ((token[0] == '0' && (token[1] == 'x')))
	  get_hexa(params, token);
	else
	  if (token[0] == '\"')
	    get_string(params, token);
	  else
	    get_variable(params, vars, token);
    }
  return (params);
}
