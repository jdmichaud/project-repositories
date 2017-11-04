/*
** proc_access.c for vm in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Jan  9 16:25:22 2002 jean-daniel michaud
** Last update Sat Jan 12 12:26:44 2002 julien gein
*/

#include <stdio.h>
#include "my_struct.h"
#include "process.h"

unsigned short	next_process(t_vm *vm, unsigned int prid)
{
  t_dlist	*lplayer;
  t_player	*player;
  t_dlist	*lprocess;
  t_process	*process;
  
  if (!vm)
    return (NULL);
  for (lplayer = vm->list_player; lplayer; lplayer = lplayer->next)
    {
      player = lplayer->elem;
      for (lprocess = player->process; lprocess; lprocess = lprocess->next)
	{
	  process = lprocess->elem;
	  if (process->prid == prid)
	    {
	      if (lprocess->prev)
		return ((process = lprocess->prev->elem)->prid);
	      else
		return (prid);
	    }
	} 
    }
  return (NULL);
}

unsigned short	prev_process(t_vm *vm, unsigned int prid)
{
  t_dlist	*lplayer;
  t_player	*player;
  t_dlist	*lprocess;
  t_process	*process;
  
  if (!vm)
    return (NULL);
  for (lplayer = vm->list_player; lplayer; lplayer = lplayer->next)
    {
      player = lplayer->elem;
      for (lprocess = player->process; lprocess; lprocess = lprocess->next)
	{
	  process = lprocess->elem;
	  if (process->prid == prid)
	    {
	      if (lprocess->next)
		return ((process = lprocess->next->elem)->prid);
	      else
		return (prid);
	    }
	} 
    }
  return (NULL);
}

unsigned short	next_alive_from_player(t_vm *vm, int id)
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
      if (player->id == id)
	{
	  if (player->process)
	    {
	      lprocess = player->process;
	      process = lprocess->elem;
	      return (process->prid);
	    }
	  else
	    return (0);
	}
    }
  return (0);
}
