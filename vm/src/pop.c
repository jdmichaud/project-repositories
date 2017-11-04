/*
** pop.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Jan  3 14:36:53 2002 GIZMO
** Last update Thu Jan 10 15:49:26 2002 GIZMO
*/

#include "my_struct.h"
#include "my_print_error.h"
#include "op.h"
#include "process.h"
#include "register.h"
#include "stack.h"

/*
** pop rx
** pop : Dépile une valeur de la pile du processeur et la stocke dans rx.
** Le fonctionnement est indepedendant de P et n'affecte pas Z.
*/

void			pop(t_vm		*v,
			    unsigned int	prid,
			    unsigned short	rx)
{
  t_process		*pr;
  unsigned short	reg_rx;
  
  pr = get_process(v, prid);
  if (v->verbose)
    my_print_error("[%i]\t--> POP r%i <--\n", prid, rx);
  _pop_(pr, &reg_rx);
  _write_register(v, pr, rx, reg_rx);
}
