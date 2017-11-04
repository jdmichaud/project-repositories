/*
** register.c for vm in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Jan  3 16:22:28 2002 jean-daniel michaud
** Last update Thu Jan 10 19:24:59 2002 jean-daniel michaud
*/

#include "my_struct.h"
#include "register.h"
#include "display.h"
#include "player.h"
#include "my.h"

int			_write_register_(t_vm		*vm,
					 t_process	*process, 
					 unsigned short	reg,
					 unsigned short	quad)
{
  unsigned short	mask;
  
  upt_interface(vm, process, reg, quad);
  if (reg > VAL_P)
    return (1);
  if (reg < VAL_Z)
    process->regs[reg] = quad;
  if (reg == VAL_P)
    {
      mask = my_power(2, sizeof (short) * 8) - 4;
      process->regs[REG_P] &= mask;
      quad &= 3;
      process->regs[REG_P] |= quad;
    }
  if (reg == VAL_Z)
    {
      mask = my_power(2, sizeof (short) * 8) - 5;
      process->regs[REG_Z] &= mask;
      quad *= 4;
      process->regs[REG_Z] |= quad;
    }
  return (0);
}

int			_read_register_(t_vm		*vm,
					t_process	*process, 
					unsigned short	reg, 
					unsigned short	*quad)
{
  unsigned short	mask;
  unsigned short	save;
  
  *quad = 0;
  if (reg > VAL_P)
    return (1);
  if (reg < VAL_Z)
    *quad = process->regs[reg];
  if (reg == VAL_P)
    {
      mask = my_power(2, sizeof (short) * 8) - 4;
      *quad &= mask;
      save = process->regs[REG_Z];
      save &= 3;
      *quad |= save;
    }
  if (reg == VAL_Z)
    {
      mask = my_power(2, sizeof (short) * 8) - 5;
      *quad &= mask;
      save = process->regs[REG_Z];
      save /= 4;
      *quad |= save;
    }
  return (0);
}

void	upt_interface(t_vm		*vm,
		      t_process		*process, 
		      unsigned short	reg,
		      unsigned short	quad)
{
  if (vm->interface)
    {
      if (reg == VAL_PC)
	update_memdpy(vm->mem.size,
		      get_id_from_prid(vm, process->prid), quad, MD_PC);
      if (process->prid == vm->follow_prid)
	update_reg(10, 512 + 30, reg, quad);
    }
}
