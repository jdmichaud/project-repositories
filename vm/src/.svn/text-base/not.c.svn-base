/*
** not.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Nov 29 15:21:20 2001 GIZMO
** Last update Fri Jan 11 09:14:47 2002 jean-daniel michaud
*/

#include "my.h"
#include "my_struct.h"
#include "my_print_error.h"
#include "op.h"
#include "register.h"
#include "process.h"

/*
** not rx, ry
** not : Calcule la négation logique (complément à 1) des quartets 0 à P de ry
** et stocke le résultat dans les quartets 0 à P de rx.
*/

void			not(t_vm		*v,
			    unsigned int	prid,
			    unsigned short	rx,
			    unsigned short	ry)
{
  t_process		*pr;
  unsigned short	reg_p;
  unsigned short	reg_rx;
  unsigned short	reg_ry;
  unsigned short	mask;
  unsigned short	tmp;
  
  pr = get_process(v, prid);
  _read_register(v, pr, VAL_P, &reg_p);
  _read_register(v, pr, rx, &reg_rx);
  _read_register(v, pr, ry, &reg_ry);
  if (v->verbose)
    my_print_error("[%i]\t--> NOT r%i, r%i <-- P=%d\n",
		   prid, rx, ry, reg_p);
  mask = my_power(2, (reg_p + 1) * QSIZE) - 1;
  tmp = reg_ry & mask;
  tmp = ~tmp;
  tmp &= mask;
  update_reg_z(v, pr, tmp);
  reg_rx &= ~mask;
  reg_rx |= tmp;
  _write_register(v, pr, rx, reg_rx);
}
