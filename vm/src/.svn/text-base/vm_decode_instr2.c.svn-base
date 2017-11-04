/*
** vm_decode_instr2.c for  in 
** 
** Made by 
** Login   <bottie_r@epita.fr>
** 
** Started on  Sat Jan  5 01:14:14 2002 
** Last update Fri Jan 11 19:31:00 2002 jean-daniel michaud
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_struct.h"
#include "mem.h"
#include "my_printf.h"
#include "register.h"
#include "op.h"
#include "decode.h"


int		dc_st(t_vm *vm, t_process *process)
{
  short		reg[2];
  
  if (process->cpt == 3)
    {
      if (process->state == DECODE)
	make_delay(process, DELAY_ST + 1);
      else
	{
	  reg[0] = process->instr[1];
	  reg[1] = process->instr[2];
	  if (process->nb_call == 0)
	    {
	      _read_register(vm, process, VAL_P, &(process->nb_call));
	      process->nb_call++;
	      if (vm->is_trace || have_to_debug(vm, process->prid))
		my_printf("[process %i] st\t [r%i], r%i\n",
			  process->prid, reg[0], reg[1]);
	      debug_call(vm, process);
	    }
	  st(vm, process->prid, reg[0], reg[1]);
	  if (--(process->nb_call) == 0) 
	      process->cpt = 0; 
	}
    }
  return (0);
}


int		dc_lc(t_vm *vm, t_process *process)
{
  short		reg;
  int		value;
  
  if (process->cpt == 4)
    {
      if (process->state == DECODE)
	make_delay(process, DELAY_LC + 1);
      else
	{
	  process->state = EXECUTE;
	  reg = process->instr[1];
	  value = little_endian2(&(process->instr[2]));
	  if (vm->is_trace || have_to_debug(vm, process->prid))
	    my_printf("[process %i] lc\t r%i, %i\n", 
		      process->prid, reg, value);
	  debug_call(vm, process);
	  lc(vm, process->prid, reg, value);
	  process->cpt = 0;
	}
    }
  return (0);
}

int			dc_ll(t_vm *vm, t_process *process)
{
  unsigned short	reg;
  unsigned short	value;
  
  if (process->cpt == 6)
    {
      if (process->state == DECODE)
	make_delay(process, DELAY_LL + 1);
      else
	{
	  process->state = EXECUTE;
	  reg = process->instr[1];
	  value = little_endian4(&(process->instr[2]));
	  if (vm->is_trace || have_to_debug(vm, process->prid))
	    my_printf("[process %i] ll\t r%i, %i\n", 
		      process->prid, reg, value);
	  debug_call(vm, process);
	  ll(vm, process->prid, reg, value);
	  process->cpt = 0;
	}
    }
  return (0);
}

int		dc_die(t_vm *vm, t_process *process)
{
  if (DELAY_DIE)
    {
      if (process->state == DECODE)
	make_delay(process, DELAY_DIE);
    }
  else
    {
      process->state = EXECUTE;
      if (vm->is_trace || have_to_debug(vm, process->prid))
	my_printf("[process %i] die\n", process->prid);
      debug_call(vm, process);
      die(vm, process->prid);
      process->cpt = 0;
    }
  return (0);
}

int		dc_live(t_vm *vm, t_process *process)
{
  short		reg;
  
  if (process->cpt == 2)
    {
      reg = process->instr[1];
      if (reg != 0)
	if (process->state == DECODE)
	  make_delay(process, DELAY_LIVE + 1);
	else
	  {
	    if (vm->is_trace || have_to_debug(vm, process->prid))
	      my_printf("[process %i] live %i\n", process->prid, reg);
	    debug_call(vm, process);
	    live(vm, process->prid, reg);
	    process->cpt = 0;
	  }
      else
	dc_die(vm, process);
    }
  return (0);
}













