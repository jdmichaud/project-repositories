/*
** display_update.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Sat Jan 12 12:06:38 2002 julien gein
** Last update Sat Jan 12 12:10:08 2002 julien gein
*/

#include "display.h"
#include "my_struct.h"
#include "player.h"
#include "process.h"
#include "op.h"

unsigned int	update_disp_zombies(t_vm *v, t_player *player)
{
  t_dlist	*lp;
  t_player	*pl;
  
  if (is_virtualy_alive(player))
    v->follow_prid = next_alive_from_player(v, player->id);
  else
    for (v->follow_rg = 1, lp = v->list_player; lp; lp = lp->next)
      {
	pl = lp->elem;
	if (isalive(pl) && pl->id != player->id)
	  {
	    v->follow_id = player->id;
	    v->follow_prid = next_alive_from_player(v, pl->id);
	    change_regsowner(v, pl->name, pl->id, v->follow_prid);
	    return (1);
	  }
      }
  return (0);
}

unsigned int	update_zombies(t_vm *v, unsigned int prid)
{
  t_player	*player;
  
  player = get_player_from_prid(v, prid);
  if (prid == v->follow_prid)
    return (update_disp_zombies(v, player));
  else
    {
      if (dlist_size(player->process) == 1)
	{
	  if (player->id > v->follow_id)
	    v->follow_rg--;
	  return (1);
	}
    }
  return (0);
}
