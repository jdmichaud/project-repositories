/*
** parser_env_var_2.c for  in 
** 
** Made by Actarus Acta
** Login   <Actarus@epita.fr>
** 
** Started on  Sun Dec 30 17:10:45 2001 Actarus Acta
** Last update Mon Dec 31 13:29:44 2001 jonathan mimouni
*/

#include <ctype.h>
#include <stdlib.h>  
#include <stdio.h>  
#include <string.h>
#include "struct.h"
#include "env_var_parser.h"
#include "env_var_parser_2.h"
#include "meta.h"
#include "my_malloc.h"

extern char	**environ;

int	isaffectation(char *str)
{
  int	i;

  if (str == NULL)
    return (0);
  if ((isalpha(*str)) || (*str == '_'))
    {
      for (i = 1; ((str[i] != '\0') && 
		   ((isalnum(str[i])) || (str[i] == '_'))); ++i)
	;
      if (str[i] != '=')
	return (0);
      return (1);
    }
  return (0);
}

int	isid(char *str)
{
  if (str == NULL)
    return (0);
  if ((*str != '\0') && ((isalpha(*str)) || (*str == '_')))
    {
      for (++str; (*str != '\0') && ((isalnum(*str)) || (*str == '_')); ++str)
	;
      if (*str == '\0')
	return (1);
    }
  return (0);
}

int	environ_export(char *aff)
{
  char	*value;

  if (!isaffectation(aff))
    {
      if (isid(aff))
	{
#ifdef __NetBSD__
	  value = NULL;
	  return (setenv(aff, "", 1));
#else
	  value = malloc((strlen(aff) + 2) * sizeof (char));
	  sprintf(value, "%s=", aff);
	  return (return_clean(putenv(value), value));
#endif
	}
      else
	return (-1);
    }
  return (environ_export_non_affect(aff));
}

int		environ_export_non_affect(char *aff)
{
  char		*id;
  char		*value;
  int		i;
  int		j;

  id = my_malloc(strlen(aff));
  for (i = 0; (aff[i] != '\0') && (aff[i] != '=') ; ++i)
    id[i] = aff[i]; 
  id[i] = '\0';
  ++i;
  value = my_malloc(strlen(aff));
  for (j = 0; (aff[i] != '\0') ; ++i, ++j)
    value[j] = aff[i]; 
  value[j] = '\0';
#ifdef __NetBSD__
  setenv(id, value, 1);
#else
  value = malloc((strlen(aff) + 2) * sizeof (char));
  sprintf(value, "%s=", aff);
  return (return_clean(putenv(value), value));
#endif
  free(id);
  free(value);
  return (0);
}

void		 list_env_var_print(int export)
{
  int		i;
  int		j;

  for (i = 0; (environ[i] != '\0'); ++i)
    if (export)
      {
	for (j = 0; (environ[i][j] != '='); ++j)
	  printf("%c", environ[i][j]);
	printf("\n");
      }
    else
      printf("%s\n", environ[i]);
}



