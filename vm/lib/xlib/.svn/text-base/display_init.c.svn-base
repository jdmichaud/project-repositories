/*
** display_init.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Fri Jan  4 14:00:53 2002 julien gein
** Last update Sat Jan 12 15:56:17 2002 julien gein
*/

#include <stdlib.h>
#include <stdio.h>
#include "display.h"
#include "data_struct.h"
#include "my_print_error.h"
#include "my_printf.h"

const static char	*color_names[NB_COLORS] =
{
  "black",
  "red",
  "green",
  "yellow",
  "blue",
  "magenta",
  "cyan",
  "white",
  "plum1",
  "PaleVioletRed",
  "DarkOrchid",
  "SteelBlue1",
  "SeaGreen1",
  "khaki1",
  "RosyBrown1",
  "grey90",
  "grey30",
  "grey60"
};

t_win		*update_stwin(t_win *in)
{
  static t_win	*window = 0;
  
  if (in)
    window = in;  
  return (window);  
}

unsigned int	init_stwin_colors(t_win *w)
{
  unsigned int	i;
  XColor	exact;
  
  w->cmap = DefaultColormap(w->dpy, DefaultScreen(w->dpy));
  for (i = 0; i < NB_COLORS; i++)
    {
      if (!XAllocNamedColor(w->dpy, w->cmap,
			    color_names[i], &(w->cl[i]), &exact))
	{
	  my_print_error("Cant't alloc color %s\n", color_names[i]);
	  exit(1);
	}
    }
  return (0);
}

Display		*open_display(void)
{
  Display	*dpy;
  
  dpy = XOpenDisplay(NULL);
  if (!dpy)
    {
      my_print_error("... Fail to open Display\n");
      exit(1);
    }
  my_printf("Open Display on %s\n", DisplayString(dpy));
  return (dpy);
}

void		init_GC(t_win *win, int bcl, int wcl)
{
  t_list	*listfont;
  XFontStruct	*font;
  char		*font_name;
  
  win->gc = XCreateGC(win->dpy, win->win, 0, NULL);
  XSetForeground(win->dpy, win->gc, wcl);
  listfont = df_get_elt(update_dcdpy(0, 0, DV_GET), "FontName");
  font_name = listfont->elem;
  if (!(font = XLoadQueryFont(win->dpy, font_name)))
    {
      my_print_error("Can't Allocate Font \'%s\'\n", font_name);
      exit(1);
    }
  XSetFont (win->dpy, win->gc, font->fid);
  win->font.name = font_name;
  win->font.h_size = font->max_bounds.rbearing - font->min_bounds.lbearing;
  win->font.v_size = font->max_bounds.ascent - font->max_bounds.descent;
}

void		init_window(void)
{
  int		blackColor;
  int		whiteColor;
  t_win		*window;
  
  window = xmalloc(sizeof (t_win));
  window->dpy = open_display();
  blackColor = BlackPixel(window->dpy, DefaultScreen(window->dpy));
  whiteColor = WhitePixel(window->dpy, DefaultScreen(window->dpy));
  window->win = XCreateSimpleWindow(window->dpy,
				    DefaultRootWindow(window->dpy),
				    0, 0, 835, 620, 0,
				    blackColor,
				    blackColor);
  XSelectInput(window->dpy, window->win, StructureNotifyMask |
	       ExposureMask |
	       ButtonPressMask |
	       KeyPressMask);
  XMapWindow(window->dpy, window->win);
  
  get_map_notify(window);
  init_GC(window, blackColor, whiteColor);  
  init_stwin_colors(window);
  update_stwin(window);
}
