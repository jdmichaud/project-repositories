/*
** lsl.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Nov 29 15:42:11 2001 GIZMO
** Last update Thu Jan 10 15:34:07 2002 GIZMO
*/

#include "my.h"
#include "my_struct.h"
#include "my_print_error.h"
#include "op.h"
#include "process.h"
#include "register.h"

/*
** lsl rx, n
** logical shift left : Effectue un décalage à gauche de n bits des quartets
** 0 à P de rx. Les bits entrants sont nuls.
*/

void			lsl(t_vm		*v,
			    unsigned int	prid,
			    unsigned short	rx,
			    unsigned int	n)
{
  t_process		*pr;
  unsigned short	reg_p;
  unsigned short	reg_rx;
  unsigned short	mask;
  unsigned short	tmp;
  unsigned int		i;
  
  pr = get_process(v, prid);
  _read_register(v, pr, VAL_P, &reg_p);
  _read_register(v, pr, rx, &reg_rx);
  if (v->verbose)
    my_print_error("[%i]\t--> LSL r%i, %i <-- P=%d\n", prid, rx, n, reg_p);
  mask = my_power(2, (reg_p + 1) * QSIZE) - 1;
  tmp = reg_rx & mask;
  for (i = 0; i < n; i++)
    tmp *= 2;
  tmp &= mask;
  update_reg_z(v, pr, tmp);
  reg_rx &= ~mask;
  reg_rx |= tmp;
  _write_register(v, pr, rx, reg_rx);
}
