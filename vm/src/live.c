/*
** live.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Nov 29 14:50:29 2001 GIZMO
** Last update Thu Jan 10 08:07:46 2002 jean-daniel michaud
*/

#include "my.h"
#include "my_struct.h"
#include "my_print_error.h"
#include "my_printf.h"
#include "op.h"
#include "process.h"

/*
** live n
** live : Emet un signe de vie pour le joueur n.
** Le fonctionnement est indépedendant de P et n'affecte pas Z.
*/

void			live(t_vm *v, unsigned int prid, unsigned short n)
{
  t_dlist		*tmp;
  t_process		*pr;
  t_player		*p;
  unsigned short	mask;
  
  pr = get_process(v, prid);
  pr->ctd = v->ctd;
  pr->is_die = LIVING;
  if (v->nbr_live-- == 0)
    {
      v->dec_ctd = DO_DEC_DELTA;
      v->nbr_live = v->cst_nbr_live;
    }
  mask = my_power(2, 1 * QSIZE) - 1;
  n &= mask;
  if (v->verbose)
    my_print_error("[%i]\t--> LIVE %i <--\n", pr->prid, n);
  for (tmp = v->list_player; tmp && (p = tmp->elem)->id != n; tmp = tmp->next)
    ;
  if (tmp)
    {
      p = tmp->elem;
      p->live_cycle = v->cpt_cycles;
    }
}
