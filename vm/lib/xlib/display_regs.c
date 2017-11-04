/*
** display_regs.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Fri Jan  4 15:55:30 2002 julien gein
** Last update Fri Jan 11 17:02:38 2002 jean-daniel michaud
*/

#include "display.h"
#include "register.h"
#include "process.h"

void	display_tab(int *vx, int *vy, int nb, const char *idx)
{
  unsigned int	i;
  unsigned int	x;
  int		offset;
  
  for (x = *vx, i = 0; i < nb; i++)
    {
      draw_line(x, *vy - VSIZE_CHAR, x, *vy + VSIZE_CHAR + 8 );
      offset = (5 * HSIZE_CHAR - (get_nbchars(idx, i) * (HSIZE_CHAR + 1))) / 2;
      win_printf(x + offset + 2, *vy + 2 - 1, idx, i);
      x += (HSIZE_CHAR * 5) + 4;
    }
  draw_line(*vx, *vy + 4, x, *vy + 4);
  draw_rectangle(*vx, *vy - VSIZE_CHAR - 1, x, *vy + VSIZE_CHAR + 8);
  *vx = x;  
}

void		init_display_reg(t_vm *vm, int vx, int vy)
{
  t_win		*w;
  
  w = update_stwin(0);
  display_current_player(vm, vm->follow_id, vm->follow_prid);
  vy += 2 * VSIZE_CHAR;
  display_rtrg(vx, vy);
  vx += 20;
  display_tab(&vx, &vy, 16, "R%d");
  vx += 5;
  display_tab(&vx, &vy, 1, "PC");
  vx += 5;  
  display_tab(&vx, &vy, 1, "Z");
  vx += 5;  
  display_tab(&vx, &vy, 1, "P");
  display_ltrg(vx, vy);  
}

void		init_regdpy(t_vm *vm)
{
  unsigned int	i;
  
  if (!truc_is_def("Env", "Register"))
    return ;
  set_color(WHITE);
  init_display_reg(vm, 10, 512 + 30);
  for (i = 0; i < 19; i++)
    update_reg(10, 512 + 30, i, 0);
}

void	update_reg(int vx, int vy, unsigned int pos, unsigned short value)
{
  int	offset;
  int	delta;
  t_win	*w;
  
  vx += 20;
  vy += 2 * VSIZE_CHAR;  
  if (!truc_is_def("Env", "Register"))
    return ;
  w = update_stwin(0);
  offset =  pos * (5 * HSIZE_CHAR + 4);
  if (pos > 15)
    offset += (pos - 15) * 5;
  set_color(BLACK);
  XFillRectangle(w->dpy, w->win, w->gc,
		 vx + offset + 1, vy + 6, 5 * HSIZE_CHAR, VSIZE_CHAR + 1);
  set_color(WHITE);
  delta = 5 * HSIZE_CHAR - (get_nbchars("%x", value) * (HSIZE_CHAR + 1));
  offset += (delta / 2 + 2);
  win_printf(vx + offset,
	     vy + VSIZE_CHAR + 6,
	     "%x",
	     value);
  XFlush(w->dpy);
}

void			change_regsowner(t_vm		*vm,
					 unsigned char	*name,
					 unsigned int	id,
					 unsigned int	prid)
{
  unsigned int		i;
  t_win			*w;
  unsigned short	regs;
  
  w = update_stwin(0);
  display_current_player(vm, id, prid);
  for (i = 0; i < 19; i++)
    {
      _read_register_(vm, get_process(vm, prid), i, &regs);
      update_reg(10, 512 + 30, i, regs);
    }
  XFlush(w->dpy);
}
