/*
** op_fct.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Fri Jan  4 21:02:05 2002 GIZMO
** Last update Mon Jan  7 21:05:30 2002 GIZMO
*/

#include "my_struct.h"
#include "op.h"
#include "process.h"
#include "register.h"

unsigned short	copy_reg(unsigned short	reg_src,
			 unsigned short reg_dst,
			 unsigned short	reg_p)
{
  unsigned short	cpy;
  unsigned short	mask;
  unsigned short	i;
  
  cpy = reg_dst;
  for (mask = 1, i = 0; i < (reg_p + 1) * QSIZE; mask *= 2, i++)
    {
      cpy &= ~mask;
      cpy |= (reg_src & mask);
    }
  return (cpy);
}


void	update_reg_z(t_vm		*v,
		     t_process		*pr,
		     unsigned short	val)
{
  if (val == 0)
    _write_register(v, pr, VAL_Z, 1);
  else
    _write_register(v, pr, VAL_Z, 0);
}
