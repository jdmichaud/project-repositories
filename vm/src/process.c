/*
** process.c for vm in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Fri Jan  4 16:04:27 2002 jean-daniel michaud
** Last update Thu Jan 10 19:23:59 2002 jean-daniel michaud
*/

#include <stdio.h>
#include <stdlib.h>

#include "my_struct.h"
#include "register.h"
#include "process.h"
#include "stack.h"
#include "mem.h"
#include "my.h"

t_process	*get_process(t_vm *vm, unsigned int prid)
{
  t_dlist	*lplayer;
  t_player	*player;
  t_dlist	*lprocess;
  t_process	*process;

  if (!vm)
    return (NULL);
  lplayer = vm->list_player;
  while (lplayer)
    {
      player = lplayer->elem;
      lprocess = player->process;
      while (lprocess)
	{
	  process = lprocess->elem;
	  if (process->prid == prid)
	    return (process);
	  lprocess = lprocess->next;
	}
      lplayer = lplayer->next;
    }
  return (NULL);
}

t_player	*get_player_from_prid(t_vm *vm, unsigned int prid)
{
  t_dlist	*lplayer;
  t_player	*player;
  t_dlist	*lprocess;
  t_process	*process;

  if (!vm)
    return (NULL);
  lplayer = vm->list_player;
  while (lplayer)
    {
      player = lplayer->elem;
      lprocess = player->process;
      while (lprocess)
	{
	  process = lprocess->elem;
	  if (process->prid == prid)
	    return (player);
	  lprocess = lprocess->next;
	}
      lplayer = lplayer->next;
    }
  return (NULL);
}

int		del_process(t_dlist *process)
{
  free(process->elem);
  return (0);
}

t_process	*new_process(t_vm *vm, t_player *player)
{
  t_process	*process;
  unsigned int	i;

  process = my_xmalloc(sizeof (t_process));
  for (i = 0; i < 16; ++i)
    {
      _write_register_(vm, process, i, 0);
      _push_(process, 0);
    }
  process->is_die = LIVING;
  process->ctw = READY;
  for (i = 1; get_process(vm, i); ++i)
    ;
  process->prid = i;
  process->cpt = 0;
  process->ctd = vm->ctd;
  process->state = DECODE;
  _write_register_(vm, process, 0, player->id);
  process->regs[REG_Z] = 0;
  _write_register_(vm, process, VAL_P, 0);
  _write_register_(vm, process, VAL_Z, 1);
  dlist_put(&(player->process), process);
  return (process);
}

t_process		*fork_process(t_vm	*vm, 
				      t_player	*player, 
				      t_process	*process)
{
  t_process		*son;
  unsigned int		i;
  unsigned short	val;
  
  for (son = my_xmalloc(sizeof (t_process)), i = 0; i < 16; ++i)
    {
      _read_register_(vm, process, i, &val);
      _write_register_(vm, son, i, val);
      _pop_(process, &val);
      _push_(son, val);
    }
  son->regs[REG_Z] = 0;
  _read_register_(vm, process, VAL_PC, &val);
  _write_register_(vm, son, VAL_PC, val);
  _read_register_(vm, process, VAL_P, &val);
  _write_register_(vm, son, VAL_P, val);
  son->is_die = process->is_die;
  son->ctw = process->ctw;
  son->ctd = process->ctd;
  for (son->state = process->state, i = 1; get_process(vm, i); ++i)
    ;
  son->prid = i;
  son->cpt = process->cpt;
  dlist_put(&(player->process), son);
  return (son);
}
