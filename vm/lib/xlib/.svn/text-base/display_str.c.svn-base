/*
** display_str.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Fri Jan  4 15:08:48 2002 julien gein
** Last update Sat Jan 12 13:17:00 2002 julien gein
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "display.h"

void	display_str(int x, int y, char *str)
{
  t_win	*w;
  
  w = update_stwin(0);
  XDrawString(w->dpy, w->win, w->gc, x, y, str, my_strlen(str));
}

unsigned int	get_nbchars(const char *str, ...)
{
  va_list	list_args;
  char		result[1024];
  
  va_start(list_args, str);
  vsprintf(result, str, list_args);
  va_end(list_args);
  return (my_strlen(result));
}

void		win_printf(int x, int y, const char *str, ...)
{
  va_list	list_args;
  char		result[1024];
  
  va_start(list_args, str);
  vsprintf(result, str, list_args);
  va_end(list_args);
  display_str(x, y, result);
}
