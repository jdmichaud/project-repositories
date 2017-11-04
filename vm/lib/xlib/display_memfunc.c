/*
** display_memfunc.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Fri Jan 11 10:48:12 2002 julien gein
** Last update Sat Jan 12 16:44:32 2002 julien gein
*/

#include "display.h"

void	display_case(int x, int y, int clr, int mode)
{
  t_win	*w;
  int	yoffset;
  
  w = update_stwin(0);
  yoffset = w->offset * 4;
  if (y <= 10 + yoffset || y >= 512 + yoffset)
    return ;
  set_color(clr);  
  XFillRectangle(w->dpy, w->win, w->gc, x, y - yoffset, 3, 3);
  if (mode == MD_PC)
    {
      set_color(WHITE);
      XDrawRectangle(w->dpy, w->win, w->gc, x - 1, y - 1 - yoffset, 4, 4);
    }
  if (mode == MD_UNPC)
    {
      set_color(BLACK);
      XDrawRectangle(w->dpy, w->win, w->gc, x - 1, y - 1 - yoffset, 4, 4);
    }  
}

void		redisplay_mem(int mem_size, t_point *backbuff, t_point *p)
{
  t_win		*w;  
  unsigned int	i;
  unsigned int	col;
  unsigned int	line;
  
  w = update_stwin(0);
  for (i = w->offset * (512 / 4);
       i < mem_size && i < 16384 + w->offset * (512 / 4); i++)
    {
      set_color(backbuff[i].mode);
      XFillRectangle(w->dpy, w->win, w->gc,
		     backbuff[i].col,
		     backbuff[i].line - w->offset * 4,
		     3, 3);
    }
  for (; i < 16384 + w->offset * (512 / 4); i++)
    {
      col = (4 * i) % HSIZE_MEM + HOFFSET + 1;
      line = ((4 * i) / HSIZE_MEM) * 4 + VOFFSET + 1 - w->offset * 4;
      set_color(WHITE);
      XDrawPoint(w->dpy, w->win, w->gc, col + 1, line + 1);
    }
}


t_point		*init_backbuff(int size, int val)
{
  t_point	*res;
  unsigned int	i;
  
  res = xmalloc(sizeof (t_point) * (size + 1));
  for (i = 0; i < size; i++)
    {
      res[i].col = val ? (4 * i) % HSIZE_MEM + HOFFSET + 1 : 0;
      res[i].line = val ? ((4 * i) / HSIZE_MEM) * 4 + VOFFSET + 1 : 0;
      res[i].mode = val ? SOFTGREY : 0;
      res[i].clr = 0;
    }
  return (res);
}


void		init_display_mem(int mem_size)
{
  t_win		*w;
  
  w = update_stwin(0);
  set_color(GREY);
  XFillRectangle(w->dpy, w->win, w->gc,
		 HOFFSET, VOFFSET, HSIZE_MEM, VSIZE_MEM);
}

void		init_display_mem_grid(int mem_size)
{
  t_win		*w;
  int		line;
  int		col;
  
  w = update_stwin(0);
  set_color(GREY);
  XFillRectangle(w->dpy, w->win, w->gc,
		 HOFFSET, VOFFSET, HSIZE_MEM, VSIZE_MEM);
  set_color(SOFTGREY);
  line = mem_size / (512 / (3 + 1));
  col = mem_size % (512 / (3 + 1));;
  XFillRectangle(w->dpy, w->win, w->gc,
		 HOFFSET, VOFFSET, HSIZE_MEM, line * 4);
  XFillRectangle(w->dpy, w->win, w->gc,
		 HOFFSET, VOFFSET + line * 4 + 1, HOFFSET + col * 4, 3);
  display_grid(w);
}
