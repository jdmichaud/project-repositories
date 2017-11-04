/*
** meta.c
** 
** Made by (Florent Monbillard)
** Login   <monbil_f@epita.fr>
** 
** Started on  Thu Dec  6 14:09:50 2001 Florent Monbillard
** Last update Mon Dec 31 08:07:52 2001 Florent Monbillard
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>
#include "size.h"
#include "match.h"
#include "completion.h"
#include "xmalloc.h"
#include "meta.h"

unsigned int	is_equal(char *str1, char *str2)
{
  if ((*str2 == '\\') && *(str2 + 1) == *str1)
    return (2);
  if ((*str1 == *str2) && (*str2 != '\\'))
    return (1);
  return (0);
}

int	return_clean(int value, char *str_to_free)
{
  if (str_to_free)
    free(str_to_free);
  return (value);
}

int	check_syntax(char **string, char end)
{
  int	i;

  for (i = 0; string && (*string) && (**string) && (**string != end); ++(*string))
    {
      if ((**string == '-') && (end == ']'))
	if ((*(*string - 1) == '[') || (*(*string + 1) == ']'))
	  return (1);
      if ((**string == ',') && (end == '}'))
	if ((*(*string - 1) == '{') || (*(*string + 1) == '}'))
	  return (1);
      if ((**string != '[' ) && (**string != '{'))
	++i;
    }
  return ((i ? 0 : 1));
}

int	check_pattern(char *pattern)
{
  for (; pattern && *pattern; ++pattern)
    {
      if (*pattern == '[')
	if (check_syntax(&pattern, ']'))
	  return (1);
      if (*pattern == '{')
	if (check_syntax(&pattern, '}'))
	  return (-1);
      if (*pattern == '\\')
	++pattern;
    }
  return (0);
}

char	**metachar(char *pattern)
{
  char	**result;
  char	**list;
  int	i;
  int	j;
  int	size;

  result = NULL;
  if (check_pattern(pattern))
    {
      fprintf(stderr, "21sh: bad pattern: %s\n", pattern);
      return (NULL);
    }
  for (i = 0, j = 0, list = get_filelist(); list && list[i]; ++i)
    if (match(list[i], pattern))
      {
	if (!result)
	  result = xmalloc((get_tabsize(list) + 1) * sizeof (char *));
	size = strlen(list[i]);
	result[j] = xmalloc((size + 1) * sizeof (char));
	bcopy(list[i], result[j], size);
	result[j++][size] = '\0';
      }
  if (result)
    result[j] = NULL;
  return (result);
}
