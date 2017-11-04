/*
** display_mem.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Fri Jan  4 18:09:26 2002 julien gein
** Last update Sat Jan 12 16:11:27 2002 julien gein
*/

#include "display.h"

void		update_display_mem(int mem_size, int player, int idx, int mode)
{
  unsigned int	i;
  unsigned int	line;
  unsigned int	col;
  t_win		*w;
  
  w = update_stwin(0);
  set_color(player);
  for (i = 0; i < HSIZE_Q; i++)
    {
      line = ((HSIZE_Q * idx + i) / HSIZE_MEM) * VSIZE_Q + VOFFSET;
      col = (HSIZE_Q * idx + i) % HSIZE_MEM + HOFFSET;
      XDrawLine(w->dpy, w->win, w->gc, col, line, col, line + VSIZE_Q);
      if (mode == MD_PC)
	{
	  set_color(BLACK);
	  XDrawPoint(w->dpy, w->win, w->gc, col, line + 1);
	} 
    }
}

void	make_init(t_point **backbuff, t_point **p, int mem_size, int mode)
{
  if (*backbuff == 0)
    {
      *p = init_backbuff(16, 0);
      *backbuff = init_backbuff(mem_size, 1);
    }
  if (mode == MD_FLUSH)
    redisplay_mem(mem_size, *backbuff, *p);
}

void			update_display_mem_grid(int	mem_size,
						int	player,
						int	idx,
						int	mode) 
{ 
  static t_point	*p = 0;
  static t_point	*backbuff = 0;
  
  make_init(&backbuff, &p, mem_size, mode);
  if (player <= 15)
    {
      if (mode == MD_PC)
	p[player].clr = backbuff[idx].mode;
      else
	backbuff[idx].mode = player;
      if (p[player].mode == 2 && p[player].col != 0 && p[player].line != 0)
	display_case(p[player].col, p[player].line, p[player].clr, MD_UNPC);
      p[player].col = (4 * idx) % HSIZE_MEM + HOFFSET + 1;
      p[player].line = ((4 * idx) / HSIZE_MEM) * 4 + VOFFSET + 1;
      p[player].mode = mode == MD_PC ? 2 : 0;
      display_case(p[player].col, p[player].line, player, mode);
    }
  else
    {
      display_case((4 * idx) % HSIZE_MEM + HOFFSET + 1,
		   ((4 * idx) / HSIZE_MEM) * 4 + VOFFSET + 1, player, MD_MEM);
      backbuff[idx].mode = player;
    }
} 

void		update_memdpy(int mem_size, int player, int idx, int mode)
{
  t_dicl	*dico;
  t_list	*list;
  t_win		*w;  
  
  w = update_stwin(0);
  dico = update_dcdpy(0, 0, DV_GET);
  if (truc_is_def("Env", "MemArea"))
    {      
      list = df_get_elt(dico, "Grid");
      if (list && !strcmp(list->elem, "True"))
	update_display_mem_grid(mem_size, player, idx, mode);
      else
	update_display_mem(mem_size, player, idx, mode);
    }
  XFlush(w->dpy);
}

void		init_memdpy(int mem_size, int mode)
{
  t_dicl	*dico;
  t_list	*list;
  
  dico = update_dcdpy(0, 0, DV_GET);
  if (truc_is_def("Env", "MemArea"))
    {      
      list = df_get_elt(dico, "Grid");
      if (list && !strcmp(list->elem, "True"))
	{
	  if (mode == MD_FLUSH)	  
	    update_display_mem_grid(mem_size, 0, 0, MD_FLUSH);
	  else
	    init_display_mem_grid(mem_size);
	}
      else
	init_display_mem(mem_size);
    }
}
