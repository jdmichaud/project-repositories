/*
** match.c
** 
** Made by (Florent Monbillard)
** Login   <monbil_f@epita.fr>
** 
** Started on  Fri Dec 21 18:48:10 2001 Florent Monbillard
** Last update Mon Dec 31 05:02:06 2001 Florent Monbillard
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "meta.h"
#include "size.h"
#include "tab.h"
#include "xmalloc.h"
#include "match.h"

int	got_a_star(char *string, char *pattern, int (*fct)(char *, char *))
{
  if (*string)
    return (fct(string, pattern + 1) || fct(string + 1, pattern));
  return (fct(string, pattern + 1));
}

int	got_an_ip(char *string, char *pattern, int (*fct)(char *, char *))
{
  if (*string)
    return (fct(string + 1, pattern + 1));
  return (0);
}

int	got_a_bracket(char *string, char *pattern, int (*fct)(char *, char *))
{
  char	*tab;
  char	*new;
  int	tabsize;
  int	size;
  int	i;
  int	j;
  
  tabsize = get_tab1size(pattern);
  tab = xmalloc((tabsize + 1) * sizeof (char));
  tab[tabsize] = '\0';
  build_tab(tab, &pattern);
  size = strlen(++pattern);
  new = xmalloc((size + 2) * sizeof (char));
  new[size + 1] = '\0';
  for (i = 0; i < tabsize; ++i)
    {
      new[0] = tab[i];
      for (j = 0; j < size; ++j)
	new[j + 1] = pattern[j];
	  if (fct(string, new) > 0)
	    return (return_clean(1, new));
    }
  return (return_clean(0, new));
}

/*
  size[0] = size 1
  size[1] = size 2
  size[2] = tabsize
  size[3] = i
  size[4] = j
 */
int	got_a_braces(char *string, char *pattern, int (*fct)(char *, char *))
{
  char	**tab;
  char	*new;
  int	size[5];
  
  size[2] = get_tab2size(pattern);
  tab = xmalloc((size[2] + 1) * sizeof (char *));
  tab[size[2]] = NULL;
  init_tab(tab, &pattern, size[2]);
  for (size[3] = 0; size[3] < size[2]; ++size[3])
    {
      size[0] = strlen(tab[size[3]]);
      size[1] = strlen(pattern);
      new = xmalloc((size[0] + size[1] + 1) * sizeof (char));
      new[size[0] + size[1]] = '\0';	  
      for (size[4] = 0; size[4] < size[0]; ++size[4])
	new[size[4]] = tab[size[3]][size[4]];
      for (; size[4] < size[0] + size[1]; ++size[4])
	new[size[4]] = pattern[size[4] - size[0]];
      if (fct(string, new) > 0)
	return (end_tab(tab, new));
      free(new);
    }
  destroy_tab(tab);
  return (0);
}

int	match(char *string, char *pattern)
{
  int	test;

  while (*string && *pattern && (test = is_equal(string, pattern)))
    {
      if (test == 2)
	++pattern;
      ++pattern;
      ++string;
    }
  if (!(*pattern + *string))
    return (1);
  if (*pattern == '*')
    return (got_a_star(string, pattern, match));
  if (*pattern == '?')
    return (got_an_ip(string, pattern, match));
  if (*pattern == '[')
    return (got_a_bracket(string, pattern + 1, match));
  if (*pattern == '{')
    return (got_a_braces(string, pattern + 1, match));
  return (0);
}
