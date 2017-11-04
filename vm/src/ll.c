/*
** ll.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Jan  3 14:33:19 2002 GIZMO
** Last update Thu Jan 10 18:52:37 2002 jean-daniel michaud
*/

#include "my_struct.h"
#include "my_print_error.h"
#include "op.h"
#include "process.h"
#include "register.h"

/*
** ll rx, n
** load long : Charge n dans le registre rx entier.
** Le fonctionnement est indépedendant de P et n'affecte pas Z.
*/

void		ll(t_vm			*v,
		   unsigned int		prid,
		   unsigned short	rx,
		   unsigned short	n)
{
  t_process	*pr;
  
  pr = get_process(v, prid);
  if (v->verbose)
    my_print_error("[%i]\t--> LL r%i, %i <--\n", prid, rx, n);
  _write_register(v, pr, rx, n);
}
