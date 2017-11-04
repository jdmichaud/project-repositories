/*
** bz.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Nov 29 15:45:09 2001 GIZMO
** Last update Fri Jan 11 09:14:16 2002 jean-daniel michaud
*/

#include "my.h"
#include "my_struct.h"
#include "my_print_error.h"
#include "op.h"
#include "process.h"
#include "register.h"

/*
** bz rx
** branch if Z : Effectue un saut relatif de rx modulo IDX_MOD quartets
** si Z = 1 (PC = PC + (rx % IDX_MOD)). rx est signé et utilisé en entier.
** Le fonctionnement est indépedendant de P et n'affecte pas Z.
*/

void			bz(t_vm			*v,
			   unsigned int		prid,
			   unsigned short	rx)
{
  t_process		*pr;
  unsigned short	reg_rx;
  unsigned short	reg_z;
  unsigned short	reg_pc;
  unsigned short	jmp;
  unsigned short	sign_bit;
  
  pr = get_process(v, prid);
  _read_register(v, pr, rx, &reg_rx);
  _read_register(v, pr, VAL_PC, &reg_pc);
  _read_register(v, pr, VAL_Z, &reg_z);
  if (v->verbose)
    my_print_error("[%i]\t--> BZ r%i <-- Z=%i\n", prid, rx, reg_z);
  if (reg_z == 1)
    {
      if ((sign_bit = ((reg_rx & 32768) == 32768 ? 1 : 0)) == 1)
	reg_pc = (reg_pc - ((jmp = (~reg_rx + 1)) % v->idx_mod))
	  % v->mem.size;
      else
	reg_pc = (reg_pc + (reg_rx % v->idx_mod)) % v->mem.size;
      _write_register(v, pr, VAL_PC, reg_pc);
    }
}
