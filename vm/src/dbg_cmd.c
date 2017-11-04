/*
** dbg_cmd.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Wed Jan  9 21:38:43 2002 GIZMO
** Last update Fri Jan 11 21:17:51 2002 jean-daniel michaud
*/

#include "data_struct.h"
#include "my_struct.h"
#include "dbg.h"
#include "my_printf.h"
#include "process.h"
#include "dbg_cmd.h"
#include "boot.h"
#include "debug.h"
#include "my.h"

void	dbg_help(t_vm *v, t_list *args)
{
  my_printf("--> CDB COMMANDS <--\n"); 
  my_printf(DUMP_MSG);
  my_printf(H_MSG);
  my_printf(I_MSG);
  my_printf(LC_MSG);
  my_printf(N_MSG);
  my_printf(P_MSG);
  my_printf(PRC_MSG);
  my_printf(Q_MSG);
  my_printf(SH_MSG);
}

void		dbg_list_child(t_vm *v, t_list *args)
{
  t_dlist	*list_pr;
  t_player	*p;
  t_process	*pr;
  
  p = get_player_from_prid(v, v->dbg_lvl);
  my_printf("--> Childs process of player %i, [%s] <--\n", p->id, p->name);
  for (list_pr = p->process; list_pr; list_pr = list_pr->next)
    {
      pr = list_pr->elem;
      if (pr->is_die == LIVING)
	{
	  if (pr->state == DECODE)
	    my_printf("\tprid=%i\t%s\n", pr->prid, "living and DECODE");
	  if (pr->state == DELAY)
	    my_printf("\tprid=%i\t%s\n", pr->prid, "living and DELAY");
	  if (pr->state == EXECUTE)
	    my_printf("\tprid=%i\t%s\n", pr->prid, "living and EXECUTE");
	}
      else
	my_printf("\tprid=%i\t%s\n", pr->prid, "died");
    }
}

void	dbg_quit(t_vm *v, t_list *args)
{
  shutdown_vm(v);
  exit(0);
}

void	dbg_info(t_vm *v, t_list *args)
{
  show_vm(v);
}

void	dbg_next(t_vm *v, t_list *args)
{
  int	nb_cycle;
  
  if (args && args->elem)
    nb_cycle = my_atoi(args->elem) + 1;
  else
    nb_cycle = 2;
  v->in_debug = CDB_OFF;
  v->dbg_cycle = nb_cycle;
}
