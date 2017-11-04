/*
** size.c
** 
** Made by (Florent Monbillard)
** Login   <monbil_f@epita.fr>
** 
** Started on  Sun Dec 30 21:40:34 2001 Florent Monbillard
** Last update Sun Dec 30 23:04:49 2001 Florent Monbillard
*/

#include "size.h"

unsigned int	get_tabsize(char **list)
{
  unsigned int	size;
  int		i;
  
  for (size = 0, i = 0; list[i]; ++i)
    ++size;
  return (size);
}

unsigned int	get_tab1size(char *str)
{
  unsigned int	size;

  for (size = 0; *str != ']'; ++str)
    if (*str == '-')
      {
	if (*(str + 1) - *(str - 1) > 0)
	  size += *(str + 1) - *(str - 1);
	++str;
      }
    else
      ++size;
  return (size);
}

unsigned int	get_tab2size(char *str)
{
  unsigned int	size;
  unsigned int	test;

  for (size = 1, test = 0; (*str != '\0') && (*str != '}'); ++str)
    if (*str == ',')
      {
	if (test)
	  {
	    ++size;
	    test = 0;
	  }
	else
	  return (0);
      }
    else
      ++test;
  if (*str == '\0')
    return (0);
  else
    return (size);      
}
