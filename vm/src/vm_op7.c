/*
** vm_op7.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Mon Jan  7 16:45:05 2002 GIZMO
** Last update Sat Jan 12 22:13:00 2002 julien gein
*/

#include "my_struct.h"
#include "decode.h"
#include "my_printf.h"
#include "op.h"
#include "register.h"

int		dc_rsb(t_vm *vm, t_process *process, unsigned short reg[2])
{
  unsigned short	regp;
  
  _read_register_(vm, process, VAL_P, &regp);
  if (process->state == DECODE)
    make_delay(process, DELAY_RSB + 1);
  else
    {
      process->state = EXECUTE;
      if (vm->is_trace || have_to_debug(vm, process->prid))
	my_printf("[process %i] rsb\t r%i, r%i\n", 
		  process->prid, reg[0], reg[1]);
      debug_call(vm, process);
      rsb(vm, process->prid, reg[0], reg[1]);
      process->cpt = 0;
    }
  return (0);
}

int		dc_neg(t_vm *vm, t_process *process, unsigned short reg[2])
{
  unsigned short	regp;
  
  _read_register_(vm, process, VAL_P, &regp);
  if (process->state == DECODE)
    make_delay(process, DELAY_NEG + 1);
  else
    {
      process->state = EXECUTE;
      if (vm->is_trace || have_to_debug(vm, process->prid))
	my_printf("[process %i] neg\t r%i, r%i\n", 
		  process->prid, reg[0], reg[1]);
      debug_call(vm, process);
      neg(vm, process->prid, reg[0], reg[1]);
      process->cpt = 0;
    }
  return (0);
}

int		dc_inc(t_vm *vm, t_process *process, unsigned short reg[2])
{
  unsigned short	regp;
  
  _read_register_(vm, process, VAL_P, &regp);
  if (process->state == DECODE)
    make_delay(process, DELAY_INC + 1);
  else
    {
      process->state = EXECUTE;
      if (vm->is_trace || have_to_debug(vm, process->prid))
	my_printf("[process %i] inc\t r%i, %i\n", 
		  process->prid, reg[0], reg[1]);
      debug_call(vm, process);
      inc(vm, process->prid, reg[0], reg[1]);
      process->cpt = 0;
    }
  return (0);
}

int		dc_dec(t_vm *vm, t_process *process, unsigned short reg[2])
{
  unsigned short	regp;
  
  _read_register_(vm, process, VAL_P, &regp);
  if (process->state == DECODE)
    make_delay(process, DELAY_DEC + 1);
  else
    {
      process->state = EXECUTE;
      if (vm->is_trace || have_to_debug(vm, process->prid))
	my_printf("[process %i] dec\t r%i, %i\n", 
		  process->prid, reg[0], reg[1]);
      debug_call(vm, process);
      dec(vm, process->prid, reg[0], reg[1]);
      process->cpt = 0;
    }
  return (0);
}
