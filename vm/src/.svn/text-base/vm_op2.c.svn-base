/*
** vm_op2.c for  in 
** 
** Made by romain bottier
** Login   <bottie_r@epita.fr>
** 
** Started on  Sat Jan  5 18:41:26 2002 romain bottier
** Last update Thu Jan 10 16:09:11 2002 jean-daniel michaud
*/

#include "my_struct.h"
#include "decode.h"
#include "my_printf.h"
#include "op.h"


int			dc_type1(t_vm *vm, t_process *process, unsigned short id)
{
  unsigned short	value;
  
  if (process->cpt == 3)
    {
      value = process->instr[2];
      if (id == 1 || id == 9)
	return (dc_push(vm, process, value));
      if (id == 2 || id == 10)
	return (dc_pop(vm, process, value));
      if (id == 3 || id == 11)
	return (dc_jmp(vm, process, value));
      if (id == 5 || id == 13)
	return (dc_write(vm, process, value));
    }
  return (0);
}

int			dc_type2(t_vm *vm, t_process *process, unsigned short id)
{
  unsigned short	value[2];
  
  if (process->cpt == 4)
    {
      value[0] = process->instr[2];
      value[1] = process->instr[3];
      if (id == 4 || id == 12)
	return (dc_fl(vm, process, value));
      if (id == 6 || id == 14)
	return (dc_stat(vm, process, value));
      return (-1);
    }
  return (0);
}

int			dc_op2_d1(t_vm *vm, t_process *process)
{
  unsigned short	reg;
  
  if (process->cpt >= 3)
    {
      reg = process->instr[1];
      if (reg == 1 || reg == 2 || reg == 3 || reg == 5 ||
	  reg == 9 || reg == 10 || reg == 11 || reg == 13)
	return (dc_type1(vm, process, reg));
      else
	return (dc_type2(vm, process, reg));
    }
  return (0);
}

int			dc_op2(t_vm *vm, t_process *process)
{
  unsigned short	reg;
  
  if (process->cpt >= 2)
    {
      reg = process->instr[1];
      if (reg == 0 || reg == 8)
	return (dc_fork(vm, process));
      else
	return (dc_op2_d1(vm, process));
    }
  return (0);
}
