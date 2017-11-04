/*
** display_refresh.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Tue Jan  8 17:44:45 2002 julien gein
** Last update Sat Jan 12 15:35:24 2002 julien gein
*/

#include "display.h"
#include "process.h"
#include "player.h"

void		test_rgarrow(t_vm *vm, int x, int y)
{
  int		vx;
  int		vy;
  t_win		*w;
  int		save;
  
  w = update_stwin(0);
  vx = 10 + 20 + 4 * 5 + 19 * ((HSIZE_CHAR * 5) + 4);
  vy = 512 + 30 + 2 * VSIZE_CHAR;
  if (x >= vx + 5 && x <= vx + 20 &&
      y >= vy - VSIZE_CHAR - 1 && y <= vy + VSIZE_CHAR + 8)
    {
      save = vm->follow_prid;
      if ((vm->follow_prid = next_process(vm, vm->follow_prid)) != save)
	change_regsowner(vm, get_name_from_prid(vm, vm->follow_prid),
			 vm->follow_id, vm->follow_prid);
      set_color(WHITE);
    }  
}

void		test_lfarrow(t_vm *vm, int x, int y)
{
  int		vx;
  int		vy;
  t_win		*w;
  int		save;
  
  w = update_stwin(0);
  vx = 10;
  vy = 512 + 30 + 2 * VSIZE_CHAR;
  set_color(BLACK);
  XFillRectangle(w->dpy, w->win, w->gc, 11, 640, 600, 200);  
  if (x >= vx && x <= vx + 15 &&
      y >= vy - VSIZE_CHAR - 1 && y <= vy + VSIZE_CHAR + 8)
    {
      save = vm->follow_prid;
      if ((vm->follow_prid = prev_process(vm, vm->follow_prid)) != save)
	change_regsowner(vm, get_name_from_prid(vm, vm->follow_prid),
			 vm->follow_id, vm->follow_prid);
      set_color(WHITE);
    }
}

void		test_select_player(t_vm *vm, int x, int y)
{
  unsigned int	nb;
  int		*pid;
  char		**names;
  int		py;
  
  names = get_pname(vm, &nb, 0);
  pid = get_pid(vm, &nb, 0);
  if (x >= 528 && x <= 528 + 300 &&
      y >= 170 - 13 && y <= 170 - 13 + 4 + 2 * VSIZE_CHAR * (nb + 1))
    {
      py = (y - (170 - 13 + 4) + VSIZE_CHAR) / (2 * VSIZE_CHAR);
      if (py > 0 && py <= nb)
	{
	  if (py != vm->follow_rg)
	    draw_hlplayer(BLACK, vm->follow_rg, names, pid);
	  draw_hlplayer(BLUE, py, names, pid);
	  vm->follow_rg = py;
	  vm->follow_id = pid[py - 1];
	  vm->follow_prid = next_alive_from_player(vm, pid[py - 1]);
	  change_regsowner(vm, names[py - 1], pid[py - 1], vm->follow_prid);
	}
    }
}

void		test_keypress(t_vm *vm, unsigned int key)
{
  t_win		*w;
  
  w = update_stwin(0);
  if (key == KEY_ESCAPE)
    dpy_exit(update_stwin(0));
  if (key == KEY_UP)
    {
      w->offset -= w->offset > 0 ? 1 : 0;
      display_grid(w);
      init_memdpy(vm->mem.size, MD_FLUSH);      
    }
  if (key == KEY_DOWN)
    {
      w->offset += w->offset < w->max ? 1 : 0;
      display_grid(w);
      init_memdpy(vm->mem.size, MD_FLUSH);      
    }
}

void		refresh_if_exposed(t_vm *vm)
{
  int		must_refresh;
  t_win		*w;
  
  w = update_stwin(0);
  must_refresh = test_events(vm, w,
			     ExposureMask | ButtonPressMask | KeyPressMask);
  if (must_refresh)
    {
      init_memdpy(vm->mem.size, MD_FLUSH);
      init_regdpy(vm);
      init_infodpy(vm);
      init_infoinsdpy();
      display_players(vm);
    }
}

