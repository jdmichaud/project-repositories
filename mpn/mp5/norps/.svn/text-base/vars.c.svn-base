/*
** vars.c for norps in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Dec  1 08:24:31 2001 jean-daniel michaud
** Last update Tue Dec  4 16:40:15 2001 jean-daniel michaud
*/

#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "vars.h"
#include "my_xmalloc.h"

void		add_vars(t_vars **vars, char *name, t_vars *var)
{
  t_vars	*tmp;

  if (var)
    {
      if (!*vars)
	{
	  *vars = xmalloc(sizeof (t_vars));
	  (*vars)->next = NULL;
	}
      else
	{
	  tmp = xmalloc(sizeof (t_vars));
	  tmp->next = *vars;
	  *vars = tmp;
	}
      (*vars)->name = name;
      (*vars)->type = var->type;
      (*vars)->value = var->value;
    }
}

int		del_vars(t_vars **vars, char *name)
{
  t_vars	*tmp;
  t_vars	*prec;

  if (vars && *vars)
    {
      tmp = (*vars);
      if (!strcmp((*vars)->name, name))
	(*vars) = (*vars)->next;
      else
	{
	  for (; tmp && strcmp(tmp->name, name); tmp = tmp->next)
	    prec = tmp;
	  if (tmp)
	    prec->next = tmp->next;
	}
      if (tmp)
	{
	  free(tmp->name);
	  free(tmp);
	  return (1);
	}
    }
  return (0);
}

t_vars		*get_value(t_vars *vars, char *name)
{
  while (vars && strcmp(vars->name, name))
    vars = vars->next;
  if (vars)
    return (vars);
  return (NULL);
}

int		show_vars(t_libs **libs, t_vars **vars, char **cmd)
{
  t_vars	*var;

  var = *vars;
  while (var)
    {
      if (var->type == VOID)
	printf("%s = %p\n", var->name, var->value.ptr);
      if (var->type == CHAR)
	printf("%s = %c\n", var->name, var->value.c);
      if (var->type == SHORT)
	printf("%s = %i\n", var->name, var->value.s);
      if (var->type == INT)
	printf("%s = %i\n", var->name, var->value.i);
      if (var->type == UCHAR)
	printf("%s = %c\n", var->name, var->value.uc);
      if (var->type == USHORT)
	printf("%s = %u\n", var->name, var->value.us);
      if (var->type == UINT)
	printf("%s = %u\n", var->name, var->value.ui);
      var = var->next;
    }
  return(1);
}
