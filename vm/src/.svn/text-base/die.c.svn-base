/*
** die.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Nov 29 14:47:18 2001 GIZMO
** Last update Sat Jan 12 12:48:47 2002 julien gein
*/

#include <stdlib.h>
#include "my_struct.h"
#include "my_print_error.h"
#include "my_printf.h"
#include "process.h"
#include "debug.h"
#include "display.h"
#include "player.h"
#include "register.h"
#include "op.h"

unsigned short	is_virtualy_alive(t_player *player)
{
  t_dlist	*lprocess;
  t_process	*process;
  
  for (lprocess = player->process; lprocess; lprocess = lprocess->next)
    {
      process = lprocess->elem;
      if (process->is_die == LIVING)
	return (1);
    }
  return (0);
}

/*
** die : Tout processeur qui exécute cette instruction est
** détruit instantanément.
*/

void			die(t_vm *v, unsigned int prid)
{
  t_process		*pr;
  t_player		*p;
  unsigned int		*pprid;
  
  pr = get_process(v, prid);
  pr->ctw = 2;
  pr->is_die = DIED;
  if (v->verbose)
    {
      my_print_error("[%i]\t--> DIE <--\n", pr->prid);
      still_alive(v);
    }
  p = get_player_from_prid(v, prid);
  pprid = my_xmalloc(sizeof (int));
  *pprid = prid;
  dlist_put(&(p->die), pprid);
  if (v->dbg_lvl == prid)
    {
      v->dbg_lvl = 0;
      my_printf("The player is dead, debug is going down.\n");
    }
}

void		flush_die(t_vm *v)
{
  t_player	*p;
  t_dlist	*tmp;
  t_dlist	*tmp_pr;
  unsigned int	*prid;
  unsigned int	val;  
  
  for (val = 0, tmp = v->list_player; tmp; tmp = tmp->next)
    {
      p = tmp->elem;
      for (tmp_pr = p->die; tmp_pr; tmp_pr = tmp_pr->next)
	{
	  prid = tmp_pr->elem;
	  if (v->interface)
	    val |= update_zombies(v, *prid);
	  dlist_rm_process(v, *prid);
	}
      dlist_free(&(p->die));
      p->die = 0;
    }
  if (val)
    display_players(v);
}

unsigned int		process_free(t_process **process, t_dlist **tmp)
{
  free(*process);
  free(*tmp);
  *process = 0;
  *tmp = 0;
  return (0);
}

unsigned int		dlist_rm_process(t_vm *v, unsigned int prid)
{
  t_player		*pl;
  t_dlist		*tmp;
  t_process		*process;
  
  pl = get_player_from_prid(v, prid);
  for (tmp = pl->process; tmp; tmp = tmp->next)
    {
      process = tmp->elem;
      if (prid == process->prid)
	{
	  if (tmp == pl->process)
	    {
	      if (!pl->process->next)
		{
		  pl->process = 0;
		  return (process_free(&process, &tmp));
		}
	      pl->process = pl->process->next;
	      pl->process->prev = 0;
	    }
	  else
	    {	  
	      tmp->prev->next = tmp->next;
	      if (tmp->next)
		tmp->next->prev = tmp->prev;
	    }
	  return (process_free(&process, &tmp));
	}
    }
  return (0);
}





