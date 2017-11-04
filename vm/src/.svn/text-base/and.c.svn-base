/*
** and.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Nov 29 15:26:12 2001 GIZMO
** Last update Thu Jan 10 15:13:42 2002 GIZMO
*/

#include "my.h"
#include "my_struct.h"
#include "my_print_error.h"
#include "op.h"
#include "process.h"
#include "register.h"

/*
** and rx, ry
** and : Calcule le ET logique bit à bit entre les quartets 0 à P de rx
** et de ry et stocke le résultat dans les quartets 0 à P de rx.
*/

void			and(t_vm		*v,
			    unsigned int	prid,
			    unsigned short	rx,
			    unsigned short	ry)
{
  t_process		*pr;
  unsigned short	reg_p;
  unsigned short	reg_rx;
  unsigned short	reg_ry;
  unsigned short	mask;
  unsigned short	tmpx;
  unsigned short	tmpy;
  
  pr = get_process(v, prid);
  _read_register(v, pr, VAL_P, &reg_p);
  _read_register(v, pr, rx, &reg_rx);
  _read_register(v, pr, ry, &reg_ry);
  if (v->verbose)
    my_print_error("[%i]\t--> AND r%i, r%i <-- P=%d\n", prid, rx, ry, reg_p);
  mask = my_power(2, (reg_p + 1) * QSIZE) - 1;
  tmpy = reg_ry & mask;
  tmpy |= ~mask;
  tmpx = reg_rx & mask;
  update_reg_z(v, pr, tmpx & tmpy);
  reg_rx &= tmpy;
  _write_register(v, pr, rx, reg_rx);
}
