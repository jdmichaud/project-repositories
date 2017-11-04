/*
** libs.c for norps in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Dec  1 08:16:30 2001 jean-daniel michaud
** Last update Tue Dec  4 05:12:08 2001 jean-daniel michaud
*/

#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "vars.h"
#include "libs.h"
#include "libs_error.h"
#include "my_xmalloc.h"
#include "utils.h"

void		add(t_libs **libs, char *name, char *aliasname)
{
  t_libs	*tmp;
  void		*handle;
  char		*str;

  str = make_filename(name);
  if ((handle = dlopen(str, RTLD_LAZY)) == NULL)
    libs_error(1);
  else
    {
      if (!*libs)
	{
	  *libs = xmalloc(sizeof (t_libs));
	  (*libs)->next = NULL;
	}
      else
	{
	  tmp = xmalloc(sizeof (t_libs));
	  tmp->next = *libs;
	  *libs = tmp;
	}
      (*libs)->name = name;
      (*libs)->aliasname = aliasname;
      (*libs)->handle = handle;
    }
}

void		del(t_libs **libs, char *aliasname)
{
  t_libs	*tmp;
  t_libs	*prec;

  if (libs && *libs)
    {
      tmp = (*libs);
      if (!strcmp((*libs)->aliasname, aliasname))
	(*libs) = (*libs)->next;
      else
	{
	  for (; tmp && strcmp(tmp->aliasname, aliasname); tmp = tmp->next)
	    prec = tmp;
	  if (tmp)
	    prec->next = tmp->next;
	}
      if (tmp)
	{
	  dlclose(tmp->handle);
	  if (tmp->name != tmp->aliasname)
	    free(tmp->name);
	  free(tmp->aliasname);
	  free(tmp);
	}
    }
}

t_vars		*callf(t_libs	*libs, 
		       char	*aliasname, 
		       char	*funcname, 
		       t_params	*params)
{
  t_libs	*tmp;
  long int	(*f)();
  long int	ret;

  if (libs)
    {
      for (tmp = libs; tmp && strcmp(tmp->aliasname, aliasname); )
	tmp = tmp->next;
      if ((tmp) && (f = dlsym(tmp->handle, funcname)))
	{
	  ret = f(params->value[0], params->value[1], params->value[2],
		  params->value[3]);
	  if (params->rtype == RIEN)
	    return (NULL);
	  if (params->rtype == VOID)
	    printf("0x%x\n", ret);
	  else
	    printf("%i\n", ret);
	  return (affect(params, ret));
	}    
    }
  return (NULL);
}

int		show_libs(t_libs **libs, t_vars **vars, char **cmd)
{
  t_libs	*lib;

  lib = *libs;
  while (lib)
    {
      printf("%s is open as \"%s\"\n", lib->name, lib->aliasname);
      lib = lib->next;
    }
  return (1);
}

void	free_libs(t_libs *lib)
{
  while (lib)
    del(&lib, lib->aliasname);
}
