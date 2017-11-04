/*
** lp.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Nov 29 15:43:44 2001 GIZMO
** Last update Wed Jan  9 12:11:39 2002 GIZMO
*/

#include "my.h"
#include "my_struct.h"
#include "my_print_error.h"
#include "op.h"
#include "process.h"
#include "register.h"

/*
** lp n
** load P : Charge les 2 bits de poids faible de n dans P (P = n).
** Le fonctionnement est indépedendant de P et n'affecte pas Z.
*/

void			lp(t_vm			*v,
			   unsigned int		prid,
			   unsigned short	n)
{
  t_process		*pr;
  unsigned short	reg_p;
  unsigned short	mask;
  
  pr = get_process(v, prid);
  _read_register(v, pr, VAL_P, &reg_p);
  if (v->verbose)
    my_print_error("[%i]\t--> LP %i <-- P=%i\n", prid, n, reg_p);
  mask = my_power(2, 2) - 1;
  n &= mask;
  _write_register(v, pr, VAL_P, n);
}
