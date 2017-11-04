/*
** stat.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Jan  3 14:41:31 2002 GIZMO
** Last update Thu Jan 10 17:10:08 2002 GIZMO
*/

#include "my.h"
#include "my_struct.h"
#include "my_print_error.h"
#include "op.h"
#include "player.h"
#include "process.h"
#include "register.h"

/*
** stat rx, n
** statistic : Charge dans rx entier la valeur du compteur n.
** Le fonctionnement est indépedendant de P et n'affecte pas Z.
*/

/*
** 0     Renvoie la constante NBR_LIVE
** 1     Renvoie la constante CYCLE_DELTA
** 2     Renvoie la valeur actuelle de CYCLE_TO_DIE
** 3     Renvoie la taille de la memoire
** 4     Renvoie IDX_MOD
** 5     Renvoie les 16 bits de poids faible du compteur de cycle
** 6     Renvoie les 16 bits de poids fort du compteur de cycle
** 7     Renvoie 42
** 8     Renvoie le nombre de joueurs de la partie
** 9     Renvoie le numéro du joueur qui possède le processeur qui fait le stat
** 10    Renvoie le nombre maximum de processeurs par joueur
** 11    Renvoie le nombre de processeurs courant pour le joueur
**       qui possède le processeur qui fait le stat
** autre Indéterminé, peut renvoyer n'importe quoi
*/

void			my_stat(t_vm		*v,
				unsigned int	prid,
				unsigned short	rx,
				unsigned short	n)
{
  t_process		*pr;
  unsigned short	reg_rx;
  unsigned int		mask;
  
  pr = get_process(v, prid);
  _read_register(v, pr, rx, &reg_rx);
  if (v->verbose)
    my_print_error("[%i]\t--> STAT r%i, %i <--\n", prid, rx, n);
  put_info(v, prid, rx, n);
  mask = my_power(2, 4 * QSIZE) - 1;
  if (n == 5)
    _write_register(v, pr, rx, v->cpt_cycles & mask);
  if (n == 6)
    _write_register(v, pr, rx, v->cpt_cycles & ~mask);
}

void		put_info(t_vm		*v,
			 unsigned int	prid,
			 unsigned short	rx,
			 unsigned short	n)			 
{
  t_player	*p;
  t_process	*pr;

  pr = get_process(v, prid);
  if (n == 0)
    _write_register(v, pr, rx, v->cst_nbr_live);
  if (n == 1)
    _write_register(v, pr, rx, v->cycle_delta);
  if (n == 2)
    _write_register(v, pr, rx, v->ctd);
  if (n == 3)
    _write_register(v, pr, rx, v->mem.size);
  if (n == 4)
    _write_register(v, pr, rx, v->idx_mod);
  if (n == 7)
    _write_register(v, pr, rx, 42);
  if (n == 8)
    _write_register(v, pr, rx, dlist_size(v->list_player));
  if (n == 9)
    _write_register(v, pr, rx, get_id_from_prid(v, prid));
  if (n == 10)
    _write_register(v, pr, rx, v->max_proc);
  if (n == 11)
    _write_register(v, pr, rx,
		    dlist_size((p = get_player_from_prid(v, prid))->process));
}
