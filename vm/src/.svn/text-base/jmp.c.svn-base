/*
** jmp.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Jan  3 14:38:17 2002 GIZMO
** Last update Wed Jan  9 12:10:01 2002 GIZMO
*/

#include "my_struct.h"
#include "my_print_error.h"
#include "op.h"
#include "process.h"
#include "register.h"

/*
** jmp rx
** jmp : Effectue un saut relatif long et inconditionnel de rx quartets
** (PC = PC + rx). rx est signé et utilisé en entier. Le fonctionnement
** est indépedendant de P et n'affecte pas Z.
*/

void			jmp(t_vm		*v,
			    unsigned int	prid,
			    unsigned short	rx)
{
  t_process		*pr;
  unsigned short	reg_rx;
  unsigned short	reg_pc;
  unsigned short	sign_bit;
  unsigned short	tmp;
  
  pr = get_process(v, prid);
  _read_register(v, pr, rx, &reg_rx);
  _read_register(v, pr, VAL_PC, &reg_pc);
  if (v->verbose)
    my_print_error("[%i]\t--> JMP r%i <--\n", prid, rx);
  if ((sign_bit = ((reg_rx & 32768) == 32768 ? 1 : 0)) == 1)
    reg_pc = (reg_pc - (tmp = (~reg_rx + 1))) % v->mem.size;
  else
    reg_pc = (reg_pc + reg_rx) % v->mem.size;
  _write_register(v, pr, VAL_PC, reg_pc);
}
