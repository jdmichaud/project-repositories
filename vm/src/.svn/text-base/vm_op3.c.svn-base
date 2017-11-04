/*
** vm_op3.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Mon Jan  7 16:29:04 2002 GIZMO
** Last update Fri Jan 11 18:11:50 2002 julien gein
*/

#include "my_struct.h"
#include "decode.h"
#include "my_printf.h"
#include "op.h"

int		dc_fork(t_vm *vm, t_process *process)
{
  if (process->state == DECODE)
    make_delay(process, DELAY_FORK + 1);
  else
    {
      process->state = EXECUTE;
      if (vm->is_trace || have_to_debug(vm, process->prid))
	my_printf("[process %i] fork\n", process->prid);
      debug_call(vm, process);
      my_fork(vm, process->prid);
      process->cpt = 0;
    }
  return (0);
}

int		dc_push(t_vm *vm, t_process *process, unsigned short id)
{
  if (process->state == DECODE)
    make_delay(process, DELAY_PUSH + 1);
  else
    {
      process->state = EXECUTE;
      if (vm->is_trace || have_to_debug(vm, process->prid))
	my_printf("[process %i] push\t r%i\n", process->prid, id);
      debug_call(vm, process);
      push(vm, process->prid, id);
      process->cpt = 0;
    }
  return (0);
}

int		dc_pop(t_vm *vm, t_process *process, unsigned short id)
{
  if (process->state == DECODE)
    make_delay(process, DELAY_POP + 1);
  else
    {
      process->state = EXECUTE;
      if (vm->is_trace || have_to_debug(vm, process->prid))
	my_printf("[process %i] pop\t r%i\n", process->prid, id);
      debug_call(vm, process);
      pop(vm, process->prid, id);
      process->cpt = 0;
    }
  return (0);
}

int		dc_jmp(t_vm *vm, t_process *process, unsigned short id)
{
  if (process->state == DECODE)
    make_delay(process, DELAY_JMP + 1);
  else
    {
      process->state = EXECUTE;
      if (vm->is_trace || have_to_debug(vm, process->prid))
	my_printf("[process %i] jmp\t r%i\n", process->prid, id);
      debug_call(vm, process);
      jmp(vm, process->prid, id);
      process->cpt = 0;
    }
  return (0);
}

int		dc_write(t_vm *vm, t_process *process, unsigned short id)
{
  if (process->state == DECODE)
    make_delay(process, DELAY_WRITE + 1);
  else
    {
      process->state = EXECUTE;
      if (vm->is_trace || have_to_debug(vm, process->prid))
	my_printf("[process %i] write\t r%i\n", process->prid, id);
      debug_call(vm, process);
      my_write(vm, process->prid, id);
      process->cpt = 0;
    }
  return (0);
}
