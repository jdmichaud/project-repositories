/*
** push.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Jan  3 14:35:00 2002 GIZMO
** Last update Thu Jan 10 15:49:30 2002 GIZMO
*/

#include "my_struct.h"
#include "my_print_error.h"
#include "op.h"
#include "process.h"
#include "register.h"
#include "stack.h"

/*
** push rx
** push : Empile rx entier dans la pile du processeur.
** Le fonctionnement est indépedendant de P et n'affecte pas Z.
*/

void			push(t_vm		*v,
			     unsigned int	prid,
			     unsigned short	rx)
{
  t_process		*pr;
  unsigned short	reg_rx;
  
  pr = get_process(v, prid);
  _read_register(v, pr, rx, &reg_rx);
  if (v->verbose)
    my_print_error("[%i]\t--> PUSH r%i <--\n", prid, rx);
  _push_(pr, reg_rx);
}
