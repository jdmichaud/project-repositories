/*
** mov.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Nov 29 14:53:05 2001 GIZMO
** Last update Thu Jan 10 15:36:46 2002 GIZMO
*/

#include "my_struct.h"
#include "my_print_error.h"
#include "op.h"
#include "process.h"
#include "register.h"

/*
** mov rx, ry
** move : Copie les quartets 0 à P de ry dans rx.
** Le fonctionnement n'affecte pas Z.
*/

void			mov(t_vm		*v,
			    unsigned int	prid,
			    unsigned short	rx,
			    unsigned short	ry)
{
  t_process		*pr;
  unsigned short	reg_p;
  unsigned short	reg_rx;
  unsigned short	reg_ry;
  
  pr = get_process(v, prid);
  _read_register(v, pr, VAL_P, &reg_p);
  _read_register(v, pr, rx, &reg_rx);
  _read_register(v, pr, ry, &reg_ry);
  if (v->verbose)
    my_print_error("[%i]\t--> MOV r%i, r%i <-- P=%d\n", prid, rx, ry, reg_p);
  reg_rx = copy_reg(reg_ry, reg_rx, reg_p);
  _write_register(v, pr, rx, reg_rx);
}
