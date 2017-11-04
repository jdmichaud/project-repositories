/*
** format.c
**
** Made by (Adrien Pestel)
** Login   <pestel_a@epita.fr>
** 
** Started on  Sun Dec 30 21:37:06 2001 Adrien Pestel
** Last update Mon Dec 31 12:43:43 2001 Florent Monbillard
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "format.h"
#include "format_eat.h"
#include "xmalloc.h"

int	is_special(char c)
{
  if ((c == '$') || (c == '\'') || (c == '\"') || (c == '\\'))
    return (1);
  return (0);
}

char	*format_append_chars(char *res, char **str)
{
 int		i;
 char		*tmp;

 for (i = 0; (*str) && (str[0][i]) && !is_special(str[0][i]); ++i)
   ;
 if (i)
 {
   res = my_realloc(res, xstrlen(res) + i + 1);
   tmp = res + xstrlen(res);
   bcopy(*str, tmp, i);
   tmp[i] = '\0';
   *str = &(str[0][i]);
 }
 return (res);
}

static t_format	format_tab[] = 
{
  {'\'', format_eat_quotes},
  {'\"', format_eat_quotes},
  {'\\', format_eat_backslash},
  {'$', format_eat_dollar},
  {0, NULL}
};

char		*format(char *str)
{
  char		*res;
  int		i;

  res = xmalloc(sizeof (char));
  *res = '\0';
  while (*str)
  {
    res = format_append_chars(res, &str);
    for (i = 0; (*str) && (format_tab[i].c); ++i)
      if (*str == format_tab[i].c)
	res = strconcat(res, format_tab[i].funky(&str));
  }
  return (res);
}
