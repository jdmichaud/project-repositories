/*
** dbg_call.c for  in 
** 
** Made by romain bottier
** Login   <bottie_r@epita.fr>
** 
** Started on  Wed Jan  9 21:31:08 2002 romain bottier
** Last update Fri Jan 11 16:57:20 2002 GIZMO
*/

#include "my.h"
#include "my_struct.h"
#include "my_printf.h"
#include "my_print_error.h"
#include "process.h"
#include "dbg.h"
#include "decode.h"
#include "dbg_cmd.h"

int		have_to_debug(t_vm *vm, unsigned int prid)
{
  return ((vm->dbg_lvl ==  prid) ? 1 : 0);
}

int		debug_call(t_vm *vm, t_process *process)
{
  if (have_to_debug(vm, process->prid))
    wait_for_cmd(vm, get_player_from_prid(vm, process->prid));
  return (0);
}

void		dbg_purchase(t_vm *v, t_list *args)
{
  my_printf("Continue execution without debugger (cdb).\n");
  v->in_debug = CDB_OFF;
  v->dbg_lvl = 0;
}

void		dbg_player(t_vm *v, t_list *args)
{
  unsigned int	id;
  
  id = my_atoi(args->elem);
  v->dbg_lvl = id;
}
