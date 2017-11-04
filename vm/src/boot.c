/*
** boot.c for vm in ~/c/rendu/proj/corewar/vm
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Nov 28 17:19:19 2001 jean-daniel michaud
** Last update Sat Jan 12 12:22:51 2002 julien gein
*/

#include <stdlib.h>

#include "my_defs_err.h"
#include "my_struct.h"
#include "my_printf.h"
#include "display.h"
#include "player.h"
#include "decode.h"
#include "debug.h"
#include "boot.h"
#include "mem.h"
#include "my.h"


/*
** Ici, initialisation de la memoire
** et malloc des structures de joueurs
** et des structures de process (uniquement)
*/
int			boot(t_vm *vm, t_list *file)
{
  unsigned int		i;
  unsigned short	*area;
  
  if (vm->verbose)
    show_file(file);
  if (vm->interface)
    init_interface(vm);
  vm->mem.area = my_xmalloc(((vm->mem.size / 4) + 1) * sizeof (short));
  for (i = 0, area = vm->mem.area; i < vm->mem.size; ++i)
    _write_(vm, NULL, i, 0);
  load_cor_file(vm, file);
  vm->follow_id = vm->follow_prid = dlist_size(vm->list_player);  
  if (vm->interface && vm->list_player)
    {
      init_regdpy(vm);
      display_players(vm);
    }
  return (0);
}

int			shutdown_vm(t_vm *vm)
{
  t_dlist		*lplayer;
  t_player		*player;

  if (vm->verbose)
    my_printf("vm shutdown after %i cycle%s\n", vm->cpt_cycles,
	      vm->cpt_cycles > 1 ? "s" : "");
  free(vm->mem.area);
  lplayer = vm->list_player;
  while (lplayer)
    {
      player = lplayer->elem;
      del_player(vm, player->id);
      lplayer = lplayer->next;
    }
  dlist_free(&(vm->list_player));
  free(vm);  
  return (0);
}

void			winner(t_vm *vm)
{
  t_list		*winners;
  t_dlist		*lp;
  t_player		*player;
  int			win;
  unsigned long		max;
  
  for (winners = NULL, max = 1, lp = vm->list_player; lp; lp = lp->next)
    {
      player = lp->elem;
      if (player->live_cycle > max)
	max = player->live_cycle;
    }
  for (win = 0, lp = vm->list_player; lp; lp = lp->next)
    {
      player = lp->elem;
      if (player->live_cycle == max)
	{
	  my_printf("%s(%i) ", player->name, player->id);
	  list_append(&winners, player->name);
	  win = 1;
	}
    }
  if (vm->interface)
    display_win_exit(winners, win);
  win ? my_printf("wins\n") : my_printf("no winner\n");
}
