/*
** vm_op5.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Mon Jan  7 16:33:38 2002 GIZMO
** Last update Sat Jan 12 22:13:02 2002 julien gein
*/

#include "my_struct.h"
#include "decode.h"
#include "my_printf.h"
#include "op.h"
#include "register.h"


int		dc_and(t_vm *vm, t_process *process, unsigned short reg[2])
{
  unsigned short	regp;
  
  _read_register_(vm, process, VAL_P, &regp);
  if (process->state == DECODE)
    make_delay(process, DELAY_AND + 1);
  else
    {
      process->state = EXECUTE;
      if (vm->is_trace || have_to_debug(vm, process->prid))
	my_printf("[process %i] and\t r%i, r%i\n", 
		  process->prid, reg[0], reg[1]);
      debug_call(vm, process);
      and(vm, process->prid, reg[0], reg[1]);
      process->cpt = 0;
    }
  return (0);
}

int		dc_or(t_vm *vm, t_process *process, unsigned short reg[2])
{
  unsigned short	regp;
  
  _read_register_(vm, process, VAL_P, &regp);
  if (process->state == DECODE)
    make_delay(process, DELAY_OR + 1);
  else
    {
      process->state = EXECUTE;
      if (vm->is_trace || have_to_debug(vm, process->prid))
	my_printf("[process %i] or\t r%i, r%i\n", 
		  process->prid, reg[0], reg[1]);
      debug_call(vm, process);
      or(vm, process->prid, reg[0], reg[1]);
      process->cpt = 0;
    }
  return (0);
}

int		dc_xor(t_vm *vm, t_process *process, unsigned short reg[2])
{
  unsigned short	regp;
  
  _read_register_(vm, process, VAL_P, &regp);
  if (process->state == DECODE)
    make_delay(process, DELAY_XOR + 1);
  else
    {
      process->state = EXECUTE;
      if (vm->is_trace || have_to_debug(vm, process->prid))
	my_printf("[process %i] xor\t r%i, r%i\n", 
		  process->prid, reg[0], reg[1]);
      debug_call(vm, process);
      xor(vm, process->prid, reg[0], reg[1]);
      process->cpt = 0;
    }
  return (0);
}

int		dc_rol(t_vm *vm, t_process *process, unsigned short reg[2])
{
  unsigned short	regp;
  
  _read_register_(vm, process, VAL_P, &regp);
  if (process->state == DECODE)
    make_delay(process, DELAY_ROL + 1);
  else
    {
      process->state = EXECUTE;
      if (vm->is_trace || have_to_debug(vm, process->prid))
	my_printf("[process %i] rol\t r%i, %i\n", 
		  process->prid, reg[0], reg[1]);
      debug_call(vm, process);
      rol(vm, process->prid, reg[0], reg[1]);
      process->cpt = 0;
    }
  return (0);
}


int		dc_add(t_vm *vm, t_process *process, unsigned short reg[2])
{
  unsigned short	regp;
  
  _read_register_(vm, process, VAL_P, &regp);
  if ((process->state == DECODE))
    make_delay(process, DELAY_ADD + 1);
  else
    {
      process->state = EXECUTE;
      if (vm->is_trace || have_to_debug(vm, process->prid))
	my_printf("[process %i] add\t r%i, r%i\n", 
		  process->prid, reg[0], reg[1]);
      debug_call(vm, process);
      add(vm, process->prid, reg[0], reg[1]);
      process->cpt = 0;
    }
  return (0);
}
