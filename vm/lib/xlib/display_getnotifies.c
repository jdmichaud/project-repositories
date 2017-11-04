/*
** display_getnotifies.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Fri Jan 11 11:14:55 2002 julien gein
** Last update Fri Jan 11 19:41:51 2002 julien gein
*/

#include "display.h"

void		get_events(t_win *w, t_list *winners, int victory)
{
  XEvent	event;
  
  for (; ; )
    {
      XNextEvent(w->dpy, &event);
      if (event.type == Expose)
	init_win_exit(w, winners, victory);
      if (event.type == ButtonPress)
	test_mouse(event.xbutton.x, event.xbutton.y);
      if (event.type == KeyPress)
	{
	  if (event.xkey.keycode == KEY_ESCAPE)
	    dpy_exit(w);
	}	    
    }
}

void		get_map_notify(t_win *window)
{
  XEvent	e;
  
  for (; ; )
    {
      XNextEvent(window->dpy, &e);
      if (e.type == MapNotify)
	break;
    }
  
}

int		test_events(t_vm *vm, t_win *w, long event_mask)
{
  int		must_refresh;
  XEvent	event;
  
  for (must_refresh = 0; XCheckMaskEvent(w->dpy, event_mask, &event); )
    {
      if (event.type == Expose)
	must_refresh = 1;
      if (event.type == ButtonPress)
	{
	  test_lfarrow(vm, event.xbutton.x, event.xbutton.y);
	  test_rgarrow(vm, event.xbutton.x, event.xbutton.y);
	  test_select_player(vm, event.xbutton.x, event.xbutton.y);
	}
      if (event.type == KeyPress)	
	test_keypress(vm, event.xkey.keycode);
    }
  return (must_refresh);
}
