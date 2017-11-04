/*
** my_ctype.c for norps in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Dec  1 19:00:00 2001 jean-daniel michaud
** Last update Tue Dec  4 03:49:28 2001 jean-daniel michaud
*/

#include <ctype.h>
#include <stdio.h>

#include "struct.h"
#include "my_ctype.h"
#include "parser.h"
#include "parse_func.h"
#include "is_func.h"

int	is_libs(t_libs *libs, char *name)
{
  if (!name)
    return (0);
  while (libs && strcmp(libs->aliasname, name))
    libs = libs->next;
  if (libs)
    return (1);
  return (0);
}

int	is_vars(t_vars *vars, char *name)
{
  if (!name)
    return (0);
  while (vars && strcmp(vars->name, name))
    vars = vars->next;
  if (vars)
    return (1);
  return (0);
}

int	is_id(char *id)
{
  int	i;

  if (id)
    if (isalpha(*id) || (*id == '_'))
      {
	for (i = 1; id[i] && (isalnum(id[i]) || (id[i] == '_')); ++i)
	  ;
	if (!id[i])
	  return (1);
      }
  return (0);
}

int	is_func(t_libs *libs, char *cmd)
{
  char	*token;

  if (*cmd == '(')
    return (is_func_with_type(libs, cmd));
  token = get_next_word(&cmd);
  if (!token)
    return (0);
  if (token && is_id(token) && !is_libs(libs, token))
    return (is_func_with_var(libs, cmd));
  cmd -= strlen(token) + 1;
  if (token && is_libs(libs, token))
    return (is_func_with_libs(libs, cmd));
  return (-1);
}

int	is_type(char *id)
{
  int	i;
   
  if (!id)
    return (0);
  if (*id == '(')
    ++id;
  i = get_id(id);
  if ((i > 6) && (i < MAX_KW))
    return (i - 6);
  return (0);
}
