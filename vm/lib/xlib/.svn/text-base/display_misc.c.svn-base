/*
** display_misc.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Fri Jan 11 14:24:43 2002 julien gein
** Last update Fri Jan 11 17:01:34 2002 jean-daniel michaud
*/

#include "display.h"
#include "my_struct.h"
#include "process.h"
#include "player.h"

void	reinit_ondie(t_vm *vm, t_player *p)
{
  t_player	*player;
  t_dlist	*lp;

  if (!isalive(get_player_from_prid(vm, vm->follow_prid)))
    for (vm->follow_rg = 1, lp = vm->list_player; lp; lp = lp->next)
      {
	player = lp->elem;
	if (isalive(player))
	  {
	    vm->follow_id = player->id;
	    vm->follow_prid = next_alive_from_player(vm, player->id);
	    change_regsowner(vm, player->name, player->id, vm->follow_prid);
	    return ;	      
	  }
      }
  else
    if (p->id > vm->follow_id)
      vm->follow_rg--;
}
