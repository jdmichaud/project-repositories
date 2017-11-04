/*
** display_playersfunc.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Fri Jan 11 10:50:18 2002 julien gein
** Last update Sat Jan 12 11:59:43 2002 julien gein
*/

#include <stdlib.h>
#include "display.h"
#include "my_struct.h"
#include "player.h"

void		draw_hlplayer(int color, int rg, char **names, int *pid)
{
  t_win		*w;
  
  w = update_stwin(0);
  set_color(color);
  XFillRectangle(w->dpy, w->win, w->gc,
		 529,
		 170 - 13 + 5 + VSIZE_CHAR * (2 * rg - 1),
		 298,
		 VSIZE_CHAR + 4);
  display_player(532,
		 170 - 13 + 4 + VSIZE_CHAR * (2 * rg - 1) + 3,
		 names[rg - 1],
		 pid[rg - 1]);
}

char		**get_pname(t_vm *vm, unsigned int *nb, int dead)
{
  t_dlist	*lp;
  unsigned int	i;
  static char	*vpname[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  t_player	*player;

  *nb = dlist_size(vm->list_player);
  for (i = 0, lp = vm->list_player; lp; lp = lp->next)
    {
      player = lp->elem;
      if ((dead && !isalive(player)) || (!dead && player->process))
	vpname[i++] = player->name;
    }
  *nb = i;
  return (vpname);
}

int		*get_pid(t_vm *vm, unsigned int *nb, int dead)
{
  t_dlist	*lp;
  unsigned int	i;
  static int	vpid[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  t_player	*player;
  
  *nb = dlist_size(vm->list_player);
  for (i = 0, lp = vm->list_player; lp; lp = lp->next)
    {
      player = lp->elem;
      if ((dead && !isalive(player)) || (!dead && isalive(player)))
	vpid[i++] = player->id;
    }
  *nb = i;
  return (vpid);
}
