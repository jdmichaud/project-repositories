/*
** debug.c for vm in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Mon Jan  7 20:41:54 2002 jean-daniel michaud
** Last update Thu Jan 10 22:19:30 2002 jean-daniel michaud
*/

#include <stdio.h>

#include "my_struct.h"
#include "my_printf.h"
#include "stream.h"
#include "debug.h"

void	show_vm(t_vm *vm)
{
  if (vm)
    {
      my_printf("mem size: %i\nmax proc: %i\nidx mod: %i\ncycle to die: %i\n",
		vm->mem.size, vm->max_proc, vm->idx_mod, vm->ctd);
      my_printf("nbr live: %i\ncycle delta: %i\ntrace: %s\nverbose: %s\n"
		"interface: %s\nfollowing id: %i\ndelay: %i\n", 
		vm->nbr_live, vm->cycle_delta, vm->is_trace ? "OK" : "OFF",
		vm->verbose ? "OK" : "OFF", vm->interface ? "OK" : "OFF",
		vm->dbg_lvl, vm->delay);
    }
}

void	show_file(t_list *file)
{
  my_printf("Liste des fichiers .cor\n");
  while (file)
    {
      my_printf("%s\n", file->elem);
      file = file->next;
    }
}

void			show_buffwrite(t_dlist *list)
{
  t_write_op		*write_op;

  my_printf("buffer d'ecriture ----\n");
  while (list)
    {
      write_op = list->elem;
      my_printf("ptr: %p\naddr: %i\nquartet: %i\n", list, write_op->addr,
	     write_op->quartet);
      fflush(stdout);
      list = list->next;
    }
  my_printf("fin ------------------\n");
  fflush(stdout);
}


int		still_alive(t_vm *vm)
{
  t_dlist	*lplayer;
  t_player	*player;
  t_dlist	*lprocess;
  t_process	*process;
  short		livin;
  
  if (!vm)
    return (NULL);
  lplayer = vm->list_player;
  if (vm->verbose)
    my_printf("[ ");
  for (livin = 0; lplayer; lplayer = lplayer->next)
    {
      player = lplayer->elem;
      for (lprocess = player->process; lprocess; lprocess = lprocess->next)
	{
	  process = lprocess->elem;
	  if (!process->is_die && ++livin && vm->verbose)
	    my_printf("%i ", process->prid);
	}
    }
  if (vm->verbose)
    my_printf("] %i still living\n", livin);
  return (livin);
}


void	usage(void)
{
  my_printf(USAGE);
  exit(1);
}
