/*
** fl.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Jan  3 14:39:14 2002 GIZMO
** Last update Thu Jan 10 15:27:16 2002 GIZMO
*/

#include "my.h"
#include "my_struct.h"
#include "mem.h"
#include "my_print_error.h"
#include "op.h"
#include "process.h"
#include "register.h"

/*
** fl rx, [ry]
** far load : Charge les P + 1 quartets stockés à l'adresse PC + ry dans les
** quartets 0 à P de rx. ry est signé et utilisé en entier.
** Le fonctionnement n'affecte pas Z.
*/

void			fl(t_vm			*v,
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
  fl_print_debug(v, prid, rx, ry);
  mask = (my_power(2, QSIZE) - 1) << (QSIZE * (reg_p + 1 - pr->nb_call));
  if ((sign_bit = ((reg_rx & 32768) == 32768 ? 1 : 0)) == 1)
    _read_(v, pr, (reg_pc - (jmp = (~reg_ry + 1)) + reg_p + 1 - pr->nb_call)
	   % v->mem.size, &quad);
  else
    _read_(v, pr, (reg_pc + reg_ry + reg_p + 1 - pr->nb_call) %
	   v->mem.size, &quad);
  quad = quad << (QSIZE * (reg_p + 1 - pr->nb_call));
  reg_rx |= quad;
  _write_register(v, pr, rx, reg_rx);
}

void	fl_print_debug(t_vm		*v,
		       unsigned int	prid,
		       unsigned short	rx,
		       unsigned short	ry)
{
  if (v->verbose)
    my_print_error("[%i]\t--> FL r%i, [r%i] <--\n", prid, rx, ry);
}
