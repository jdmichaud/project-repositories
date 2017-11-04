/*
** vm_op1.c for  in 
** 
** Made by romain bottier
** Login   <bottie_r@epita.fr>
** 
** Started on  Sat Jan  5 17:45:20 2002 romain bottier
** Last update Thu Jan 10 16:06:45 2002 jean-daniel michaud
*/

#include "my_struct.h"
#include "decode.h"
#include "my_printf.h"
#include "op.h"


int			dc_op1_d1(t_vm *vm, t_process *process,
				  unsigned short reg[2])
{
  unsigned short	offset;
  
  offset = process->instr[1];
  if (offset == 0)
    return (dc_mov(vm, process, reg));
  if (offset == 1)
    return (dc_swp(vm, process, reg));
  if (offset == 2)
    return (dc_not(vm, process, reg));
  if (offset == 3)
    return (dc_and(vm, process, reg));
  if (offset == 4)
    return (dc_or(vm, process, reg));
  if (offset == 5)
    return (dc_xor(vm, process, reg));
  if (offset == 6)
    return (dc_rol(vm, process, reg));
  if (offset == 7)
    return (dc_asr(vm, process, reg));
  if (offset == 8)
    return (dc_add(vm, process, reg));
  if (offset == 9)
    return (dc_sub(vm, process, reg));
  return (dc_op1_d2(vm, process, reg));
}

int			dc_op1_d2(t_vm *vm, t_process *process,
				  unsigned short reg[2])
{
  unsigned short	offset;
  
  offset = process->instr[1];
  if (offset == 10)
    return (dc_rsb(vm, process, reg));
  if (offset == 11)
    return (dc_neg(vm, process, reg));
  if (offset == 12)
    return (dc_inc(vm, process, reg));
  if (offset == 13)
    return ( dc_dec(vm, process, reg));
  if (offset == 14)
    return ( dc_lsl(vm, process, reg));
  if (offset == 15)
    return (dc_lsr(vm, process, reg));
  return (-1);
}

int			dc_op1(t_vm *vm, t_process *process)
{
  unsigned short		reg[2];
  
  if (process->cpt == 4)
    {
      reg[0] = process->instr[2];
      reg[1] = process->instr[3];
      return (dc_op1_d1(vm, process, reg));
    }
  return (0);
}
