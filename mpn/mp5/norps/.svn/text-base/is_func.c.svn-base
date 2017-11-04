/*
** is_func.c for norps in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Mon Dec  3 22:27:52 2001 jean-daniel michaud
** Last update Tue Dec  4 02:52:21 2001 jean-daniel michaud
*/

#include <ctype.h>
#include <stdio.h>

#include "struct.h"
#include "my_ctype.h"
#include "parser.h"
#include "parse_func.h"
#include "is_func.h"
#include "parse_error.h"

int	is_func_with_var(t_libs *libs, char *cmd)
{
  char	*token;

  token = get_next_word(&cmd);
  if (!token)
    return (0);
  if (token && strcmp(token, "="))
    return (0);
  return (is_func_with_type(libs, cmd));
}

int	is_func_with_libs(t_libs *libs, char *cmd)
{
  char	*token;

  token = get_next_word(&cmd);
  if (!token)
    return (0);
  if (token && is_libs(libs, token) && !strcmp(get_next_word(&cmd), ":"))
    return (1);
  return (0);
}

int	is_func_with_type(t_libs *libs, char *cmd)
{
  char	*token;
  int	type;

  token = get_to_next_parenthsis(&cmd);
  if (!token)
    return (0);
  type = 9;
  if (*token == '(')
    {
      if (token && !is_type(token))
	{
	  parse_error(11);
	  return (-2);
	}
      type = is_type(token);
      if (is_func_with_libs(libs, cmd))
	return (type);
      return (0);
    }
  else 
    return (0);
}
