/*
** display_primitives.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Fri Jan  4 17:04:26 2002 julien gein
** Last update Sat Jan 12 16:22:08 2002 julien gein
*/

#include "display.h"

void	draw_line(int x1, int y1, int x2, int y2)
{
  t_win	*w;

  w = update_stwin(0);
  XDrawLine(w->dpy, w->win, w->gc, x1, y1, x2, y2);
}

void	draw_rectangle(int x1, int y1, int x2, int y2)
{
  t_win	*w;
  
  w = update_stwin(0);
  XDrawRectangle(w->dpy, w->win, w->gc, x1, y1, x2 - x1, y2 - y1);
}

void		display_rtrg(int vx, int vy)
{
  XPoint	trg[5];
  t_win		*w;

  w = update_stwin(0);
  set_color(WHITE);
  trg[0].x = vx + 10;
  trg[0].y = vy - 4;
  trg[1].x = vx + 3;
  trg[1].y = vy + 3;
  trg[2].x = vx + 10;
  trg[2].y = vy + 11;
  trg[3].x = vx + 13;
  trg[3].y = vy + 11;
  trg[4].x = vx + 13;
  trg[4].y = vy - 4;
  draw_rectangle(vx, vy - VSIZE_CHAR - 1, vx + 15, vy + VSIZE_CHAR + 8);
  XFillPolygon(w->dpy, w->win, w->gc, trg, 5, Complex, CoordModeOrigin);
}

void	display_ltrg(int vx, int vy)
{
  XPoint	trg[5];
  t_win		*w;
  
  w = update_stwin(0);
  set_color(WHITE);
  trg[0].x = vx + 11;
  trg[0].y = vy - 4;
  trg[1].x = vx + 18;
  trg[1].y = vy + 3;
  trg[2].x = vx + 11;
  trg[2].y = vy + 11;
  trg[3].x = vx + 8;
  trg[3].y = vy + 11;
  trg[4].x = vx + 8;
  trg[4].y = vy - 4;  
  draw_rectangle(vx + 5, vy - VSIZE_CHAR - 1, vx + 20, vy + VSIZE_CHAR + 8);
  XFillPolygon(w->dpy, w->win, w->gc, trg, 5, Complex, CoordModeOrigin);
}

void		display_grid(t_win *w)
{
  unsigned int	i;
  
  set_color(BLACK);
  for (i = 0; i < 512 / 4; i++)
    {
      XDrawLine(w->dpy, w->win, w->gc,
		4 * i + HOFFSET, VOFFSET, 4 * i + HOFFSET, VOFFSET + 512);
      XDrawLine(w->dpy, w->win, w->gc,
		HOFFSET, 4 * i + VOFFSET, HOFFSET + 512, 4 * i + VOFFSET);
    }
}
