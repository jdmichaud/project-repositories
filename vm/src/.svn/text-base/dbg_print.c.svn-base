/*
** dbg_print.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Jan 10 23:25:36 2002 GIZMO
** Last update Sat Jan 12 12:53:01 2002 julien gein
*/

#include "my.h"
#include "data_struct.h"
#include "my_struct.h"
#include "process.h"
#include "register.h"
#include "my_printf.h"
#include "dbg.h"
#include "dbg_cmd.h"
#include "my_printf.h"
#include "my_print_error.h"

void		dbg_print_solo(t_vm *v, t_list *args)
{
  unsigned int	prid;
  unsigned int	reg;
  
  if (((reg = parse_reg(args->elem)) == -1) && !my_isnum(args->elem))
    {
      if (!my_isnum(args->elem) || (prid = my_atoi(args->elem)) == 0)
	{
	  my_print_error("Bad param\n");
	  return ;
	}
      else
	print_all_regs(v, prid);
    }
  else
    print_reg(v, reg, v->dbg_lvl);
}

void		dbg_print(t_vm *v, t_list *args)
{
  unsigned int	prid;
  unsigned int	reg;
  
  if (list_size(args) == 1)
    dbg_print_solo(v, args);
  else
    {
      if (list_size(args) == 2)
	{
	  if ((reg = parse_reg(args->elem)) == -1)
	    {
	      my_print_error("Bad register number\n");
	      return ;
	    }
	  if ((prid = my_atoi(args->next->elem)) == 0)
	    {
	      my_print_error("Bad prid\n");
	      return ;
	    }
	  print_reg(v, reg, prid);
	}
      else
  	print_all_regs(v, v->dbg_lvl);
    }
}

void			print_all_regs(t_vm *v, unsigned int prid)
{
  t_player		*p;
  t_process		*pr;
  int			i;
  unsigned short	reg;
  
  pr = get_process(v, prid);
  p = get_player_from_prid(v, prid);
  my_printf("--> Registers of process %i (%i)<--\n", pr->prid, p->id);
  for (i = 0; i < 16; i++)
    {
      _read_register(v, pr, i, &reg);
      my_printf("  R%i\t= %u,\t\t%x\n", i, reg, reg);
    }
  _read_register(v, pr, VAL_P, &reg);
  my_printf("  P\t= %u,\t\t%x\n", reg, reg);
  _read_register(v, pr, VAL_Z, &reg);
  my_printf("  Z\t= %u,\t\t%x\n", reg, reg);
  _read_register(v, pr, VAL_PC, &reg);
  my_printf("  PC\t= %u,\t\t%x\n", reg, reg);
}


void			print_reg(t_vm *v, int reg, int prid)
{
  t_player		*p;
  t_process		*pr;
  unsigned short	reg_val;

  pr = get_process(v, prid);
  p = get_player_from_prid(v, prid);
  _read_register(v, pr, reg, &reg_val);
  if (reg == VAL_P)
    my_printf("  P\t= %u,\t\t%x\n", reg_val, reg_val);
  else
    {
      if (reg == VAL_Z)
	my_printf("  Z\t= %u,\t\t%x\n", reg_val, reg_val);
      else
	{
	  if (reg == VAL_PC)
	    my_printf("  PC\t= %u,\t\t%x\n", reg_val, reg_val);
	  else
	    my_printf("  R%i\t= %u,\t\t%x\n", reg, reg_val, reg_val);
	}
    }
}

int	parse_reg(char *arg)
{
  int	reg;
  
  if ((my_strcmp(arg, "z") == 0) || (my_strcmp(arg, "Z") == 0))
    return (VAL_Z);
  if ((my_strcmp(arg, "p") == 0) || (my_strcmp(arg, "P") == 0))
    return (VAL_P);
  if ((my_strcmp(arg, "pc") == 0) || (my_strcmp(arg, "PC") == 0))
    return (VAL_PC);
  reg = my_atoi(arg);
  if (reg >= 0 && reg <= 15)
    return (reg);
  else
    return (-1);
}
