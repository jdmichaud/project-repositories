/*
** fork.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Jan  3 14:34:07 2002 GIZMO
** Last update Thu Jan 10 19:23:36 2002 jean-daniel michaud
*/

#include "my.h"
#include "my_struct.h"
#include "my_print_error.h"
#include "op.h"
#include "process.h"
#include "register.h"

/*
** fork
** fork : Créé un nouveau processeur en tout point identique à celui qui
** exécute le fork à l'exception du registre Z qui vaudra 0 dans l'un et
** 1 dans l'autre. Le fonctionnement est indépedendant de P.
*/

void		my_fork(t_vm		*v,
			unsigned int	prid)
{
  t_player	*p;
  unsigned int	*pprid;
  
  p = get_player_from_prid(v, prid);
  pprid = my_xmalloc(sizeof (int));
  *pprid = prid;
  list_put(&(p->forks), pprid);
  if (v->verbose)
    my_print_error("[%i]\t--> FORK <--\n", prid);
}

void		flush_fork(t_vm *v)
{
  t_player	*p;
  t_dlist	*tmp;
  t_list	*tmp_forks;
  t_process	*pr;
  int		nbprocess;
  unsigned int	*pprid;	
  
  for (tmp = v->list_player; tmp; tmp = tmp->next)
    {
      p = tmp->elem;
      nbprocess = dlist_size(p->process) + list_size(p->forks);
      if (nbprocess <= v->max_proc)
	do_fork(v, p);
      else
	{
	  for (tmp_forks = p->forks; tmp_forks; tmp_forks = tmp_forks->next)
	    {
	      pr = get_process(v, *(pprid = tmp_forks->elem));
	      _write_register(v, pr, VAL_Z, 0);
	    }
	}
      list_free(&(p->forks));
    }
}

void		do_fork(t_vm *v, t_player *p)
{
  t_list	*tmp_forks;
  t_process	*pr;
  t_process	*new;
  unsigned int	*pprid;
  
  for (tmp_forks = p->forks; tmp_forks; tmp_forks = tmp_forks->next)
    {
      pr = get_process(v, *(pprid = tmp_forks->elem));
      new = fork_process(v, p, pr);
      _write_register(v, new, VAL_Z, 0);
      _write_register(v, pr, VAL_Z, 1);
    }
}
