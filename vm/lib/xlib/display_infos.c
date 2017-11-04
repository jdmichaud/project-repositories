/*
** display_infos.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Sat Jan  5 14:05:44 2002 julien gein
** Last update Sat Jan 12 16:37:15 2002 julien gein
*/

#include <stdlib.h>
#include "display.h"
#include "my_struct.h"
#include "debug.h"

void		init_infodpy(t_vm *vm)
{
  int		offset;
  t_win		*w;
  
  if (!truc_is_def("Env", "Infos"))
    return ;
  w = update_stwin(0);
  offset = VSIZE_CHAR + 5;
  set_color(WHITE);
  win_printf(532, 47, " Memory Size : %d", vm->mem.size);
  win_printf(532, 47 + offset, " Current Cycle : %d", vm->cpt_cycles);
  win_printf(532, 47 + 2 * offset, " Cycle To Die : %d", vm->ctd);
  win_printf(532, 47 + 3 * offset, " MAX Process : %d", vm->max_proc);
  if (truc_is_def("Infos_Nb_Process", "True"))
    win_printf(532, 47 + 4 * offset, " Nb Process : %d", still_alive(vm));  
  XDrawRectangle(w->dpy, w->win, w->gc,
		 528, 16, 300, 125);
  display_title("Game's Infos", 29);
}

void		refresh_infodpy(t_vm *vm)
{
  int		offset;
  t_win		*w;
  
  if (!truc_is_def("Env", "Infos"))
    return ;
  w = update_stwin(0);
  offset = VSIZE_CHAR + 5;
  set_color(BLACK);
  XFillRectangle(w->dpy, w->win, w->gc, 652, 37, 100, VSIZE_CHAR);
  XFillRectangle(w->dpy, w->win, w->gc, 668, 37 + offset, 100, VSIZE_CHAR);
  XFillRectangle(w->dpy, w->win, w->gc, 660, 37 + offset * 2, 100, VSIZE_CHAR);
  XFillRectangle(w->dpy, w->win, w->gc, 652, 37 + offset * 3, 100, VSIZE_CHAR);
  XFillRectangle(w->dpy, w->win, w->gc, 644, 37 + offset * 4, 100, VSIZE_CHAR);
  set_color(WHITE);  
  win_printf(532, 47, " Memory Size : %d", vm->mem.size);
  win_printf(532, 47 + offset, " Current Cycle : %d", vm->cpt_cycles);
  win_printf(532, 47 + 2 * offset, " Cycle To Die : %d", vm->ctd);
  win_printf(532, 47 + 3 * offset, " MAX Process : %d", vm->max_proc);
  if (truc_is_def("Infos_Nb_Process", "True"))
    win_printf(532, 47 + 4 * offset, " Nb Process : %d", still_alive(vm));
}

void		init_infoinsdpy(void)
{
  t_win		*w;
  
  if (!truc_is_def("Env", "Infos"))
    return ;
  w = update_stwin(0);
  set_color(DARKGREY);
  XFillRectangle(w->dpy, w->win, w->gc,
		 10, 600 - VSIZE_CHAR - 2, 796, VSIZE_CHAR + 6);
  set_color(WHITE);
  XDrawRectangle(w->dpy, w->win, w->gc,
		 10, 600 - VSIZE_CHAR - 3, 796, VSIZE_CHAR + 6);
  win_printf(16, 600, "kvm v1.01 on %s (%s : %s)",
	     getenv("HOSTTYPE"), __DATE__, __TIME__);
}

