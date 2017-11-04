/*
** lp.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Nov 29 15:43:44 2001 GIZMO
** Last update Thu Jan 10 13:50:17 2002 GIZMO
*/

#include "my.h"
#include "my_struct.h"
#include "my_print_error.h"
#include "op.h"
#include "process.h"
#include "register.h"

/*
** lc rx, n
** load constant : Charge n dans les 2 quartets de poids faible de rx
** et propage le bit de signe de ces 2 quartets dans les 2 quartets de poids
** fort de rx. Le fonctionnement est indépedendant de P et n'affecte pas Z.
*/

void			lc(t_vm			*v,
			   unsigned int		prid,
			   unsigned short	rx,
			   short		n)
{
  t_process		*pr;
  unsigned short	sign_bit;
  unsigned short	mask;
  
  pr = get_process(v, prid);
  if (v->verbose)
    my_print_error("[%i]\t--> LC r%i, %i <--\n", prid, rx, n);
  sign_bit = ((n & 128) == 128 ? 1 : 0);
  mask = my_power(2, 2 * QSIZE) - 1;
  if (sign_bit == 1)
    n |= ~mask;
  else
    n &= mask;
  _write_register(v, pr, rx, n);
}
