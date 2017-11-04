/*
** display_exit.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Fri Jan 11 18:31:25 2002 julien gein
** Last update Sat Jan 12 16:14:17 2002 julien gein
*/

#include <stdlib.h>

#include "display.h"

void		display_coders(t_win *w)
{
  int		yoffset;
  unsigned int	i;
  const char	*str[] =
  {
    "BOTTIER  Romain",
    "GEIN     Julien ",
    "GRIMAULT Francois-Joseph",
    "MICHAUD  Jean Daniel",
    0
  };
  
  win_printf(190, 324, "Made By :");
  for (yoffset = 330, i = 0; str[i]; i++)
    {
      yoffset += 2 * VSIZE_CHAR - 4;
      win_printf(190, yoffset, "- %s", str[i]);
    }
}

void	init_win_exit(t_win *w, t_list *winners, int victory)
{
  int	yoffset;
  
  set_color(DARKGREY);
  XFillRectangle(w->dpy, w->win, w->gc, 167, 210, 500, 200);
  set_color(WHITE);  
  XDrawRectangle(w->dpy, w->win, w->gc, 167, 210, 500, 200);  
  if (victory)
    {
      win_printf(190, 240, "The winner%s %s :",
		 list_size(winners) == 1 ? "" : "s",
		 list_size(winners) == 1 ? "is" : "are");
      for (yoffset = 0; winners; winners = winners->next)
	{
	  win_printf(360, 240 + yoffset, "- \'%s\'", winners->elem);
	  yoffset += 2 * VSIZE_CHAR - 4;
	}      
    }
  else
    win_printf(200, 240, "No winner... (They were de Gros Boulets)");
  display_coders(w);
  set_color(SOFTGREY);
  XFillRectangle(w->dpy, w->win, w->gc, 562, 380, 100, 25);
  set_color(WHITE);  
  XDrawRectangle(w->dpy, w->win, w->gc, 562, 380, 100, 25);
  win_printf(573, 397, "<< EXIT >>");
}

void	dpy_exit(t_win *w)
{
  free(w);
  exit(0); 
}

void	test_mouse(int x, int y)
{
  if (x >= 562 && x <= 662 && y >= 380 && y <= 405)
    dpy_exit(0);
}

void	display_win_exit(t_list *winners, int victory)
{
  t_win	*w;
  
  w = update_stwin(0);
  XClearWindow(w->dpy, w->win);
  init_win_exit(w, winners, victory);
  get_events(w, winners, victory);
}
  
