/*
** init.c for vm in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Jan  2 16:17:53 2002 jean-daniel michaud
** Last update Fri Jan 11 16:20:40 2002 romain bottier
*/

#include <stdio.h>

#include "my_struct.h"
#include "init.h"
#include "options.h"
#include "my_printf.h"
#include "my.h"
#include "debug.h"
#include "stream.h"

t_vm	*init(char *argv[])
{
  t_vm	*vm;
  
  if (noill_options(argv) || option_here(argv, 0))
    usage();
  vm = my_xmalloc(sizeof (t_vm));
  vm->list_player = NULL;
  vm->mem.area = NULL;
  init_struct(argv, vm);
  vm->is_trace = 0;
  if (option_here(argv, 7))
    vm->is_trace = 1;
  vm->interface = 0;
  if (option_here(argv, 8))
    vm->interface = 1;
  vm->cpt_cycles = 0;
  vm->verbose = option_here(argv, 10);
  vm->dec_ctd = DONT_DEC_DELTA;
  vm->follow_rg = 1;
  vm->in_debug = CDB_ON;
  vm->dbg_cycle = 0;
  if (vm->verbose)
    show_vm(vm);
  return (vm);
}

void	init_struct(char *argv[], t_vm *vm)
{
  if (!(vm->mem.size = get_option(argv, 1)))
    vm->mem.size = MEM_SIZE;
  if (!(vm->max_proc = get_option(argv, 2)))
    vm->max_proc = MAX_PROC;
  if (!(vm->idx_mod = get_option(argv, 3)))
    vm->idx_mod = IDX_MOD;
  if (!(vm->ctd = get_option(argv, 4)))
    vm->ctd = CYCLE_TO_DIE;
  if (!(vm->nbr_live = get_option(argv, 5)))
    vm->nbr_live = NBR_LIVE;
  vm->cst_nbr_live = vm->nbr_live;
  if (!(vm->cycle_delta = get_option(argv, 6)))
    vm->cycle_delta = CYCLE_DELTA;
  if (!(vm->dbg_lvl = get_option(argv, 9)))
    vm->dbg_lvl = NO_DEBUG;
  if (!(vm->delay = get_option(argv, 11)))
    vm->delay = NO_DELAY;
}
