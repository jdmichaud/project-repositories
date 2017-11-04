/*
** cycle.c for  in 
** 
** Made by 
** Login   <bottie_r@epita.fr>
** 
** Started on  Tue Jan  8 23:52:39 2002 
** Last update Fri Jan 11 15:51:37 2002 romain bottier
*/

#include "my_struct.h"
#include "data.h"
#include "decode.h"

void	make_delay(t_process *process, int delay)
{
  process->ctw = delay;
  process->state = DELAY;
}

void   	check_state_vm(t_vm *vm, t_process *process)
{
  if (process->state == EXECUTE && process->nb_call == 0)
    process->state = DECODE;
  if (process->state == DELAY && process->ctw == 0)
    process->state = EXECUTE;
  if (vm->dbg_lvl == process->prid && vm->dbg_cycle > 0)
    {
      if (vm->dbg_cycle == 1)
	vm->in_debug = CDB_ON;
      if (process->cpt == 0)
	{
	  (vm->dbg_cycle)--;
	  vm->in_debug = CDB_OFF;
	}
    }
}
