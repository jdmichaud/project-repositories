/*
** sub.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Nov 29 15:35:40 2001 GIZMO
** Last update Thu Jan 10 17:15:53 2002 GIZMO
*/

#include "my.h"
#include "my_struct.h"
#include "my_print_error.h"
#include "op.h"
#include "process.h"
#include "register.h"

/*
** sub rx, ry
** sub : Soustrait les quartets 0 à P de ry de ceux de rx et stocke le
** résultat dans les quartets 0 à P de rx (rx = rx - ry).
*/

void			sub(t_vm		*v,
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
    my_print_error("[%i]\t--> SUB r%i, r%i <-- P=%d\n", prid, rx, ry, reg_p);
  mask = my_power(2, QSIZE * (reg_p + 1)) - 1;
  tmpx = reg_rx & mask;
  tmpy = reg_ry & mask;
  tmpx -= tmpy;
  tmpx &= mask;
  update_reg_z(v, pr, tmpx);
  reg_rx &= ~mask;
  reg_rx |= tmpx;
  _write_register(v, pr, rx, reg_rx);
}
