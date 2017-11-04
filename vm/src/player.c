/*
** player.c for vm in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Jan  5 07:48:15 2002 jean-daniel michaud
** Last update Sat Jan 12 11:56:33 2002 julien gein
*/

#include <stdio.h>

#include "my_struct.h"
#include "process.h"
#include "player.h"
#include "my.h"

t_player	*new_player(t_vm *vm, short id, unsigned char *name)
{
  t_player	*player;
  
  player = my_xmalloc(sizeof (t_player));
  player->id = id;
  player->name = name;
  player->die = 0;
  player->forks = 0;
  player->process = 0;
  player->live_cycle = 0;
  dlist_put(&(vm->list_player), player);
  return (player);
}

int		del_player(t_vm *vm, short id)
{
  t_dlist	*lplayer;
  t_player	*player;
  
  lplayer = vm->list_player;
  player = lplayer->elem;
  for (; lplayer; lplayer = lplayer->next)
    if (player->id == id)
      {
	dlist_free(&(player->process));
	return (0);
      }
  return (1);
}

int		isalive(t_player *player)
{
  return (player->process ? 1 : 0);
}

int		get_id_from_prid(t_vm *vm, unsigned int prid)
{
  t_dlist	*lplayer;
  t_player	*player;
  t_dlist	*lprocess;
  t_process	*process;
  
  if (!vm)
    return (0);
  lplayer = vm->list_player;
  while (lplayer)
    {
      player = lplayer->elem;
      lprocess = player->process;
      while (lprocess)
	{
	  process = lprocess->elem;
	  if (process->prid == prid)
	    return (player->id);
	  lprocess = lprocess->next;
	}
      lplayer = lplayer->next;
    }
  return (0);
}

unsigned char	*get_name_from_prid(t_vm *vm, unsigned int prid)
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
	    return (player->name);
	  lprocess = lprocess->next;
	}
      lplayer = lplayer->next;
    }
  return (0);
}
