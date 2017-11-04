/*
** st.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Mon Jan  7 14:41:46 2002 GIZMO
** Last update Thu Jan 10 17:45:04 2002 GIZMO
*/

#include "my.h"
#include "my_struct.h"
#include "my_print_error.h"
#include "op.h"
#include "process.h"
#include "register.h"
#include "stream.h"

/*
** st [rx], ry
** store : Stocke les quartets 0 à P de ry dans les P + 1 quartets stockés
** à l'adresse PC + (rx % IDX_MOD). rx est signé et utilisé en entier.
** Le fonctionnement n'affecte pas Z.
*/

void			st(t_vm			*v,
			   unsigned int		prid,
			   unsigned short	rx,
			   unsigned short	ry)
{
  t_process		*pr;
  unsigned short	reg_rx;
  unsigned short	reg_ry;
  unsigned short	reg_p;
  unsigned short	reg_pc;
  unsigned short	mask;
  unsigned short	quad;
  unsigned short	sign_bit;
  unsigned short	jmp;
  
  pr = get_process(v, prid);
  _read_register(v, pr, rx, &reg_rx);
  _read_register(v, pr, ry, &reg_ry);
  _read_register(v, pr, VAL_P, &reg_p);
  _read_register(v, pr, VAL_PC, &reg_pc);
  st_print_debug(v, prid, rx, ry);
  mask = (my_power(2, QSIZE) - 1) << (QSIZE * (reg_p + 1 - pr->nb_call));
  quad = reg_ry & mask;
  quad = quad >> (QSIZE * (reg_p + 1 - pr->nb_call));
  if ((sign_bit = ((reg_rx & 32768) == 32768 ? 1 : 0)) == 1)
    bwrite(v, pr, (reg_pc + ((-(jmp = (~reg_rx + 1)) + reg_p + 1 -
			      pr->nb_call) % v->idx_mod)) % v->mem.size, quad);
  else
    bwrite(v, pr, (reg_pc + ((reg_rx + reg_p + 1 - pr->nb_call) %
			     v->idx_mod)) % v->mem.size, quad);
}

void			st_print_debug(t_vm		*v,
				       unsigned int	prid,
				       unsigned short	rx,
				       unsigned short	ry)
{
  t_process		*pr;
  unsigned short	reg_p;

  pr = get_process(v, prid);
  _read_register(v, pr, VAL_P, &reg_p);
  if (v->verbose)
    my_print_error("[%i]\t--> ST [r%i], r%i <-- P=%i\n", prid, rx, ry, reg_p);
}
