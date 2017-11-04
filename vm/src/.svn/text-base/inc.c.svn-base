/*
** inc.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Nov 29 15:40:53 2001 GIZMO
** Last update Fri Jan 11 09:15:39 2002 jean-daniel michaud
*/

#include "my.h"
#include "my_struct.h"
#include "my_print_error.h"
#include "op.h"
#include "process.h"
#include "register.h"

/*
** inc rx, n
** inc : Incrémente de n les quartets 0 à P de rx (rx = rx + n).
*/

void			inc(t_vm		*v,
			    unsigned int	prid,
			    unsigned short	rx,
			    unsigned short	n)
{
  t_process		*pr;
  unsigned short	reg_p;
  unsigned short	reg_rx;
  unsigned short	mask;
  unsigned short	tmp;
  
  pr = get_process(v, prid);
  _read_register(v, pr, VAL_P, &reg_p);
  _read_register(v, pr, rx, &reg_rx);
  if (v->verbose)
    my_print_error("[%i]\t--> INC r%i, %i <-- P=%d\n", prid, rx, n, reg_p);
  mask = my_power(2, (reg_p + 1) * QSIZE) - 1;
  tmp = reg_rx & mask;
  tmp += n;
  tmp &= mask;
  update_reg_z(v, pr, tmp);
  reg_rx &= ~mask;
  reg_rx |= tmp;
  _write_register(v, pr, rx, reg_rx);
}
