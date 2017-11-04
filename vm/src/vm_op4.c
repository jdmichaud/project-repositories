/*
** vm_op4.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Mon Jan  7 16:31:49 2002 GIZMO
** Last update Sat Jan 12 22:13:03 2002 julien gein
*/

#include "my_struct.h"
#include "decode.h"
#include "mem.h"
#include "my_printf.h"
#include "op.h"
#include "register.h"


int		dc_fl(t_vm *vm, t_process *process, unsigned short value[2])
{
  if (process->state == DECODE)
    make_delay(process, DELAY_FL + 1);
  else
    {
      process->state = EXECUTE;
      if (process->nb_call == 0)
	{
	  _read_register(vm, process, VAL_P, &(process->nb_call));
	  process->nb_call++;
	  if (vm->is_trace || have_to_debug(vm, process->prid))
	    my_printf("[process %i] fl\t r%i, [r%i]\n", process->prid,
		      value[0], value[1]);
	  debug_call(vm, process);
	}
      fl(vm, process->prid, value[0], value[1]);
      if (--(process->nb_call) == 0)
	process->cpt = 0; 
    }
  return (0);
}

int		dc_stat(t_vm *vm, t_process *process, unsigned short value[2])
{
  if (process->state == DECODE)
    make_delay(process, DELAY_STAT + 1);
  else
    {
      process->state = EXECUTE;
      if (vm->is_trace || have_to_debug(vm, process->prid))
	my_printf("[process %i] stat\t r%i, %i\n", process->prid,
		  value[0], value[1]);
      debug_call(vm, process);
      my_stat(vm, process->prid, value[0], value[1]);
      process->cpt = 0;
    }
  return (0);
}

int		dc_mov(t_vm *vm, t_process *process, unsigned short reg[2])
{
  unsigned short	regp;
  
  _read_register_(vm, process, VAL_P, &regp);
  if (process->state == DECODE)
    make_delay(process, DELAY_MOV + 1);
  else
    {
      process->state = EXECUTE;
      if (vm->is_trace || have_to_debug(vm, process->prid))
	my_printf("[process %i] mov\t r%i, r%i\n", 
		  process->prid, reg[0], reg[1]);
      debug_call(vm, process);
      mov(vm, process->prid, reg[0], reg[1]);
      process->cpt = 0;
    }
  return (0);
}

int		dc_swp(t_vm *vm, t_process *process, unsigned short reg[2])
{
  unsigned short	regp;
  
  _read_register_(vm, process, VAL_P, &regp);
  if (process->state == DECODE)
    make_delay(process, DELAY_SWP + 1);
  else
    {
      process->state = EXECUTE;
      if (vm->is_trace || have_to_debug(vm, process->prid))
	my_printf("[process %i] swp\t r%i, r%i\n", 
		  process->prid, reg[0], reg[1]);
      debug_call(vm, process);
      swp(vm, process->prid, reg[0], reg[1]);
      process->cpt = 0;
    }
  return (0);
}

int		dc_not(t_vm *vm, t_process *process, unsigned short reg[2])
{
  unsigned short	regp;
  
  _read_register_(vm, process, VAL_P, &regp);
  if (process->state == DECODE)
    make_delay(process, DELAY_NOT + 1);
  else
    {
      process->state = EXECUTE;
      if (vm->is_trace || have_to_debug(vm, process->prid))
	my_printf("[process %i] not\t r%i, r%i\n", 
		  process->prid, reg[0], reg[1]);
      debug_call(vm, process);
      not(vm, process->prid, reg[0], reg[1]);
      process->cpt = 0;
    }
  return (0);
}







