/*
** vm_decode_instr.c for  in 
** 
** Made by romain bottier
** Login   <bottie_r@epita.fr>
** 
** Started on  Fri Jan  4 17:52:57 2002 romain bottier
** Last update Fri Jan 11 20:17:59 2002 jean-daniel michaud
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_struct.h"
#include "mem.h"
#include "my_printf.h"
#include "register.h"
#include "op.h"
#include "stream.h"
#include "decode.h"

int			dc_lp(t_vm *vm, t_process *process)
{
  unsigned short	reg;
  
  if (process->cpt == 2)
    {
      if (process->state == DECODE)
	make_delay(process, DELAY_LP + 1);
      else
	{
	  process->state = EXECUTE;
	  reg = process->instr[1];
	  if (vm->is_trace || have_to_debug(vm, process->prid))
	    my_printf("[process %i] lp\t %i\n", process->prid, reg);
	  debug_call(vm, process);
	  lp(vm, process->prid, reg);
	  process->cpt = 0;
	}
    }
  return (0);
}

int			dc_bnz(t_vm *vm, t_process *process)
{
  unsigned short	reg;

  if (process->state == DECODE)
    make_delay(process, DELAY_BNZ + 1);
  else
    {
      reg = process->instr[1];
      if (vm->is_trace || have_to_debug(vm, process->prid))
	my_printf("[process %i] bnz\t r%i\n", process->prid, reg);
      debug_call(vm, process);
      bnz(vm, process->prid, reg);
      process->cpt = 0;
    }
  return (0);
}

int			dc_ld(t_vm *vm, t_process *process)
{
  unsigned short	reg[2];
  
  if (process->cpt == 3)
    {
      if (process->state == DECODE)
	make_delay(process, DELAY_LD + 1);
      else
	{
	  reg[0] = process->instr[1];
	  reg[1] = process->instr[2];
	  if (process->nb_call == 0)
	    {
	      _read_register(vm, process, VAL_P, &(process->nb_call));
	      (process->nb_call)++;
	      if (vm->is_trace || have_to_debug(vm, process->prid))
		my_printf("[process %i] ld\t r%i, [r%i]\n", 
			  process->prid, reg[0], reg[1]);
	      debug_call(vm, process);
	    }
	  ld(vm, process->prid, reg[0], reg[1]);
	  if (--(process->nb_call) == 0)
	    process->cpt = 0;
	}
    }
  return (0);
}

int			get_inst(t_vm *vm, t_process *process)
{
  unsigned short	reg;
  
  reg = process->instr[0];
  if (reg == 0 || reg == 8)
    return (dc_live(vm, process));
  if (reg == 1 || reg == 9)
    return (dc_op1(vm, process));
  if (reg == 7 || reg == 15)
    return (dc_op2(vm, process));
  if (reg == 2 || reg == 10)
    return (dc_lp(vm, process));
  if (reg == 3)
    return (dc_bnz(vm, process));
  if (reg == 11)
    return (dc_bz(vm, process));
  if (reg == 4 || reg == 12)
    return (dc_ld(vm, process));
  if (reg == 5 || reg == 13)
    return (dc_st(vm, process));
  if (reg == 6)
    return (dc_lc(vm, process));
  if (reg == 14)
    return (dc_ll(vm, process));
  return (-1);
}

int			cycle_instr(t_vm *vm, t_process *process)
{
  unsigned short	quartet;
  unsigned short	pc_counter;
  int			res;
  
  if (process->state == DECODE)
    {
      process->nb_call = 0;
      _read_register(vm, process, VAL_PC, &pc_counter);
      _read_(vm, process, pc_counter, &quartet);
      _write_register(vm, process, VAL_PC, (++pc_counter) % vm->mem.size);
      process->instr[process->cpt++] = quartet;
    }
  if (process->cpt > 1)
    res = get_inst(vm, process);
  if (res == -1)
    {
      if (vm->verbose)
	my_printf("[process %i] Illegal instruction.\n", process->prid);
      die(vm, process->prid);
      process->cpt = 0;
    }
  check_state_vm(vm, process);
  return (0);
}

