/*
** display_players.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Sat Jan  5 15:05:51 2002 julien gein
** Last update Sat Jan 12 17:14:14 2002 julien gein
*/

#include <stdlib.h>
#include "display.h"
#include "my_struct.h"
#include "player.h"

void	display_current_player(t_vm *vm, int id, int prid)
{
  t_win	*w;
  
  w = update_stwin(0);
  set_color(DARKGREY);
  XFillRectangle(w->dpy, w->win, w->gc,
		 10, 512 + 30 - VSIZE_CHAR - 2, 796, VSIZE_CHAR + 6);
  set_color(WHITE);
  XDrawRectangle(w->dpy, w->win, w->gc,
		 10, 512 + 30 - VSIZE_CHAR - 3, 796, VSIZE_CHAR + 6);
  win_printf(11, 512 + 30, "Player \'%s\' (%d) [ Process #%d ] ::",
	     get_name_from_prid(vm, prid),
	     id,
	     prid);
}

void		display_player(int x, int y, char *name, int id)
{
  t_win		*w;
  char		*res;
  unsigned int	nb_char;
  
  w = update_stwin(0);
  set_color(id);
  XFillRectangle(w->dpy, w->win, w->gc, x, y, 18, VSIZE_CHAR);
  set_color(GREY);  
  XDrawRectangle(w->dpy, w->win, w->gc, x, y, 18, VSIZE_CHAR);
  set_color(WHITE);
  if (name)
    {
      res = my_strdup(name);
      if (my_strlen(name) > (nb_char = (300 - (18 + 40)) / HSIZE_CHAR - 6))
	{
	  res[nb_char - 3] = '.';
	  res[nb_char - 2] = '.';
	  res[nb_char - 1] = '.';
	  res[nb_char] = '\0';
	}
      win_printf(x + 22, y + VSIZE_CHAR, "%s (%d).", res, id);
      free(res);
    }
  else
    win_printf(x + 22, y + VSIZE_CHAR, "No Name (%d).", id);
}

void	display_title(char *str, int save)
{
  t_win	*w;
  
  w = update_stwin(0);
  set_color(DARKGREY);
  XFillRectangle(w->dpy, w->win, w->gc,
		 528 + 55, save - 2 * VSIZE_CHAR, 190, 16);
  
  set_color(WHITE);
  XDrawRectangle(w->dpy, w->win, w->gc,
		 528 + 55, save - 2 * VSIZE_CHAR, 190, 16);
  win_printf(528 + 65, save - VSIZE_CHAR + 2, str);
}

void		players_dpy(char **players, int *ids, unsigned int nb, int *y)
{
  unsigned int	i;
  t_win		*w;
  int		save;
  
  save = *y;
  w = update_stwin(0);
  *y += 4;
  for (i = 0; i < nb; i++, *y += 2 * VSIZE_CHAR)
    display_player(532, *y, players[i], ids[i]);
  XDrawRectangle(w->dpy, w->win, w->gc,
		 528, save - 13, 300, *y - save + 2 * VSIZE_CHAR);
}

void		display_players(t_vm *vm)
{
  char		**s;
  int		*id;
  unsigned int	nb;
  t_win		*w;
  int		y;
  int		save;
  
  if (!truc_is_def("Env", "ListPlayers"))
    return ;
  w = update_stwin(0);
  set_color(BLACK);
  XFillRectangle(w->dpy, w->win, w->gc, 525, 144, 350, 380);
  s = get_pname(vm, &nb, 0);
  id = get_pid(vm, &nb, 0);
  save = y = 170;
  players_dpy(s, id, nb, &y);
  draw_hlplayer(BLUE, vm->follow_rg, s, id);
  display_title("Champions Still Alive", save);
  save = (y += 35);
  s = get_pname(vm, &nb, 1);
  id = get_pid(vm, &nb, 1);  
  players_dpy(s, id, nb, &y);
  display_title("Dead Champions", save);
  XFlush(w->dpy);
}
