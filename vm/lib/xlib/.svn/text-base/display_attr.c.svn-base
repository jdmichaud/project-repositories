/*
** display_color.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Sat Jan  5 13:48:20 2002 julien gein
** Last update Fri Jan 11 10:06:22 2002 julien gein
*/

#include "display.h"

void	set_color(int color)
{
  t_win	*w;
  
  w = update_stwin(0);
  XSetForeground(w->dpy, w->gc, w->cl[color % NB_COLORS].pixel);
}

int		get_hsize(void)
{
  t_win		*w;

  return (7);
  w = update_stwin(0);
  return (w->font.h_size + 2);
}

int		get_vsize(void)
{
  t_win		*w;

  return (10);
  w = update_stwin(0);
  return (w->font.v_size + 2);
}
