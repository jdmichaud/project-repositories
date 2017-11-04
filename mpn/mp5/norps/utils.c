/*
** utils.c for norps in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Dec  1 12:28:46 2001 jean-daniel michaud
** Last update Mon Dec  3 21:36:14 2001 jean-daniel michaud
*/

#include <string.h>
#include <ctype.h>

#include "struct.h"
#include "my_xmalloc.h"
#include "utils.h"

char	*make_filename(char *name)
{
  char	*str;

  str = xmalloc(sizeof (char) * (strlen(name) + 3));
  strcat(str, name);
  return (str);
}

int	stop(t_libs **libs, t_vars **vars, char **cmd)
{
  return (0);
}

int	isnumber(char *str)
{
  while (*str && isdigit(*str++))
    ;
  if (!*str)
    return (1);
  return (0);
}

t_vars		*affect(t_params *params, long int r)
{
  t_vars	*var;

  var = xmalloc(sizeof (t_vars));
  var->type = params->rtype;
  if (var->type == VOID)
    {
      var->value.ptr = 0;
      var->value.ptr += r;
    }
  else
    {
      if (var->type == INT)
	var->value.i = r;
      if (var->type == CHAR)
	var->value.c = r;
      if (var->type == SHORT)
	var->value.s = r;
      if (var->type == UINT)
	var->value.ui = r;
      if (var->type == UCHAR)
	var->value.uc = r;
      if (var->type == USHORT)
	var->value.us = r;
    }
  return (var);
}
