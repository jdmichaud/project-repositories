/*
** format_eat.c
**
** Made by (Adrien Pestel)
** Login   <pestel_a@epita.fr>
** 
** Started on  Mon Dec 31 11:39:24 2001 Adrien Pestel
** Last update Mon Dec 31 11:46:53 2001 Adrien Pestel
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "format.h"
#include "format_eat.h"
#include "xmalloc.h"

char	*format_eat_quotes(char **str)
{
  char		*start;
  char		*res;
  
  for (start = ++(*str); (*str) && (**str) && (**str != '\"'); ++(*str))
    if (**str == '$')
      	{
	  res = format_append_chars(res, &start);
	  res = strconcat(res, format_eat_dollar(str));
	  start = *str;
	  if (!**str)
	    break;
	}
  res = format_append_chars(res, &start);
  if (**str)
    ++(*str);	
  return (res);
}


char	*format_eat_backslash(char **str)
{
  str = NULL;
  return (NULL);
}

char	*format_eat_dollar(char **str)
{
  char		*start;
  char		*res;
  char		save;

  for (start = ++(*str); (*str) && (**str) && 
      (**str != ' ') && (**str != '\"'); ++(*str))
    ;
  save = **str;
  **str = '\0';
  if ((res = getenv(start)))
    res = strdup(res);
  **str = save;
  return (res);
}

int	xstrlen(char *str)
{
  if (!str)
    return (0);
  else
    return (strlen(str));
}

char	*strconcat(char *left, char *right)
{
  int		i;
  char		*res;
  char		*tmp;
  char		*savel;
  char		*saver;

  savel = left;
  saver = right;
  i = xstrlen(left) + xstrlen(right) + 1;
  res = xmalloc(i * sizeof (char));
  tmp = res;
  for (; (left) && (*left);)
    *tmp++ = *left++;
  for (; (right) && (*right);)
    *tmp++ = *right++;
  *tmp = '\0';
  if (savel)
    free(savel);
  if (saver)
    free(saver);
  return (res);
}


