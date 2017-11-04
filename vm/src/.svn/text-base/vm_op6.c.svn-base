/*
** vm_op6.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Mon Jan  7 16:35:15 2002 GIZMO
** Last update Sat Jan 12 22:13:01 2002 julien gein
*/

#include "my_struct.h"
#include "decode.h"
#include "my_printf.h"
#include "op.h"
#include "register.h"

int			dc_bz(t_vm *vm, t_process *process)
{
  unsigned short	reg;

  if (process->state == DECODE)
    make_delay(process, DELAY_BZ + 1);
  else
    {
      process->state = EXECUTE;
      reg = process->instr[1];
      if (vm->is_trace || have_to_debug(vm, process->prid))
	my_printf("[process %i] bz\t r%i\n", process->prid, reg);
      debug_call(vm, process);
      bz(vm, process->prid, reg);
      process->cpt = 0;
    }
  return (0);
}


int		dc_lsr(t_vm *vm, t_process *process, unsigned short reg[2])
{
  unsigned short	regp;
  
  _read_register_(vm, process, VAL_P, &regp);
  if (process->state == DECODE)
    make_delay(process, DELAY_LSR + 1);
  else
    {
      process->state = EXECUTE;
      if (vm->is_trace || have_to_debug(vm, process->prid))
	my_printf("[process %i] lsr\t r%i, %i\n", 
		  process->prid, reg[0], reg[1]);
      debug_call(vm, process);
      lsr(vm, process->prid, reg[0], reg[1]);
      process->cpt = 0;
    }
  return (0);
}

int		dc_lsl(t_vm *vm, t_process *process, unsigned short reg[2])
{
  unsigned short	regp;
  
  _read_register_(vm, process, VAL_P, &regp);
  if (process->state == DECODE)
    make_delay(process, DELAY_LSL + 1);
  else
    {
      process->state = EXECUTE;
      if (vm->is_trace || have_to_debug(vm, process->prid))
	my_printf("[process %i] lsl\t r%i, %i\n", 
		  process->prid, reg[0], reg[1]);
      debug_call(vm, process);
      lsl(vm, process->prid, reg[0], reg[1]);
      process->cpt = 0;
    }
  return (0);
}

int		dc_asr(t_vm *vm, t_process *process, unsigned short reg[2])
{
  unsigned short	regp;
  
  _read_register_(vm, process, VAL_P, &regp);
  if (process->state == DECODE)
    make_delay(process, DELAY_ASR + 1);
  else
    {
      process->state = EXECUTE;
      if (vm->is_trace || have_to_debug(vm, process->prid))
	my_printf("[process %i] asr\t r%i, %i\n", 
		  process->prid, reg[0], reg[1]);
      debug_call(vm, process);
      asr(vm, process->prid, reg[0], reg[1]);
      process->cpt = 0;
    }
  return (0);
}

int		dc_sub(t_vm *vm, t_process *process, unsigned short reg[2])
{
  unsigned short	regp;
  
  _read_register_(vm, process, VAL_P, &regp);
  if (process->state == DECODE)
    make_delay(process, DELAY_SUB + 1);
  else
    {
      process->state = EXECUTE;
      if (vm->is_trace || have_to_debug(vm, process->prid))
	my_printf("[process %i] sub\t r%i, r%i\n", 
		  process->prid, reg[0], reg[1]);
      debug_call(vm, process);
      sub(vm, process->prid, reg[0], reg[1]);
      process->cpt = 0;
    }
  return (0);
}
