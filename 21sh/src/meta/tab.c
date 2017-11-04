/*
** tab.c
** 
** Made by (Florent Monbillard)
** Login   <monbil_f@epita.fr>
** 
** Started on  Mon Dec 31 02:43:47 2001 Florent Monbillard
** Last update Mon Dec 31 04:39:03 2001 Florent Monbillard
*/

#include <stdlib.h>
#include <string.h>
#include "meta.h"
#include "xmalloc.h"
#include "tab.h"

void	build_tab(char *tab, char **pattern)
{
  int	i;
  char	c;

  for (i = 0; pattern && (*pattern) && (**pattern != ']'); ++(*pattern))
    if (**pattern == '-')
      {
	++(*pattern);
	for (c = *(*pattern - 2) + 1; c <= **pattern; ++c)
	  tab[i++] = c;
      }
    else
      tab[i++] = **pattern;
}

void	init_tab(char **tab, char **pattern, int tabsize)
{
  char	*start;
  int	i;

  if (pattern)
    for (i = 0, start = *pattern; i < tabsize; ++(*pattern))
      if ((**pattern == ',') || (**pattern == '}'))
	{
	  tab[i] = xmalloc((*pattern - start + 1) * sizeof (char));
	  bcopy(start, tab[i], *pattern - start);
	  tab[i++][*pattern - start] = '\0';
	  start = *pattern + 1;
	}
}

void	destroy_tab(char **tab)
{
  int	i;

  for (i = 0; tab[i]; ++i)
    free(tab[i]);
  free(tab);
}

int	end_tab(char **tab, char *new)
{
  destroy_tab(tab);
  return (return_clean(1, new));
}
