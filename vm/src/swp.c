/*
** swp.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Nov 29 14:54:03 2001 GIZMO
** Last update Thu Jan 10 17:25:08 2002 GIZMO
*/

#include "my_struct.h"
#include "my_print_error.h"
#include "op.h"
#include "process.h"
#include "register.h"

/*
** swp rx, ry
** swap : Echange les quartets 0 � P de rx et ry.
** Le fonctionnement n'affecte pas Z.
*/

void		swp(t_vm		*v,
		    unsigned int	prid,
		    unsigned short	rx,
		    unsigned short	ry)
{
  t_process		*pr;
  unsigned short	reg_p;
  unsigned short	reg_rx;
  unsigned short	reg_ry;
  unsigned short	tmp;
  
  pr = get_process(v, prid);
  _read_register(v, pr, VAL_P, &reg_p);
  _read_register(v, pr, rx, &reg_rx);
  _read_register(v, pr, ry, &reg_ry);
  if (v->verbose)
    my_print_error("[%i]\t--> SWP r%i, r%i <-- P=%i\n", prid, rx, ry, reg_p);
  tmp = copy_reg(reg_ry, reg_rx, reg_p);
  _write_register(v, pr, rx, tmp);
  tmp = copy_reg(reg_rx, reg_ry, reg_p);
  _write_register(v, pr, ry, tmp);
}

