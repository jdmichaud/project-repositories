/*
** run.c for vm in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** Started on  Sun Jan  6 09:26:32 2002 jean-daniel michaud
** Last update Sat Jan 12 16:38:45 2002 julien gein
*/

#include <stdio.h>

#include "my_struct.h"
#include "my_printf.h"
#include "decode.h"
#include "display.h"
#include "stream.h"
#include "boot.h"
#include "run.h"
#include "my.h"
#include "op.h"

void		run_vm(t_vm *vm)
{
  t_dlist	*lplayer;
  t_dlist	*lprocess;
  t_player	*player;
  t_process	*process;

  while (the_mower(vm)) 
    {
      lplayer = vm->list_player;
      for (player = lplayer->elem; lplayer; lplayer = lplayer->next)
	{
	  player = lplayer->elem;
	  for (lprocess = player->process; lprocess; lprocess = lprocess->next)
	    {
	      process = lprocess->elem;
	      process_cycle(vm, process);
	    }
	}
      end_cycle(vm);
    }
  winner(vm);
}

int		age_process(t_vm *vm)
{
  t_dlist	*lplayer;
  t_player	*player;
  t_dlist	*lprocess;
  t_process	*process;

  if (!vm)
    return (0);
  for (lplayer = vm->list_player; lplayer; lplayer = lplayer->next)
    {
      player = lplayer->elem;
      for (lprocess = player->process; lprocess; lprocess = lprocess->next)
	{
	  process = lprocess->elem;
	  if (process->is_die == LIVING)
	    --(process->ctd);
	}
    }
  return (0);
}

int		the_mower(t_vm *vm)
{
  t_dlist	*lplayer;
  t_player	*player;
  t_dlist	*lprocess;
  t_process	*process;
  short		livin;
  
  for (lplayer = vm->list_player, livin = 0; lplayer; lplayer = lplayer->next)
    {
      player = lplayer->elem;
      for (lprocess = player->process; lprocess; lprocess = lprocess->next)
	{
	  process = lprocess->elem;
	  if (process->is_die == LIVING && process->ctd <= 0)
	    {
	      if (vm->verbose)
		my_printf(EPITAPHE, process->prid);
	      process->is_die = DIED;
	      if (vm->interface)
		update_zombies(vm, process->prid);		
	    }
	  if (process->is_die == LIVING)
	    ++livin;
	}
    }
  return (livin);
}

void		end_cycle(t_vm *vm)
{
  _flush(vm);
  flush_fork(vm);
  age_process(vm);
  if (vm->dec_ctd)
    {
      if (vm->ctd < vm->cycle_delta)
	vm->ctd = 0;
      else
	vm->ctd -= vm->cycle_delta;
      vm->dec_ctd = DONT_DEC_DELTA;
    }
  flush_die(vm);
  if (vm->interface)
    {
      if ((vm->cpt_cycles % 2) == 0)
	refresh_infodpy(vm);
      refresh_if_exposed(vm);
    }
  ++(vm->cpt_cycles);
}

void		process_cycle(t_vm *vm, t_process *process)
{
  unsigned int	i;

  if (!process->is_die)
    {
      if (process->state == DECODE || process->state == EXECUTE)
	cycle_instr(vm, process);
      else
	if (process->state == DELAY)
	  {
	    if (process->ctw == 1)
	      {
		for (i = 0; i < vm->delay; ++i)
		  ;
		process->state = EXECUTE;
		cycle_instr(vm, process);
	      }
	    else
	      --(process->ctw);
	  }
    }
}
