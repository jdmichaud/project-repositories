/*
** init_xserver.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Sun Jan  6 15:37:12 2002 julien gein
** Last update Sat Jan 12 14:31:45 2002 julien gein
*/

#include <stdio.h>
#include <stdlib.h>

#include "my_printf.h"
#include "display.h"
#include "my_struct.h"

void		init_interface(t_vm *vm)
{
  t_list	*list;
  t_win		*w;  
  
  init_dcdpy();
  if (vm->verbose)
    my_printf("Parsing CFG File \'%s\'\n", ".vmdpyrc");
  if ((list = init_file_buff(".vmdpyrc")))
    for (; list; list = list->next)
      {
	cfg_parseline(list->elem);
	free(list->elem);
      }
  init_window();
  init_memdpy(vm->mem.size, MD_FLUSH);
  init_infodpy(vm);
  init_infoinsdpy();
  w = update_stwin(0);
  w->offset = 0;
  w->max = vm->mem.size > 16384 ? (vm->mem.size - 16384) / (512 / 4) + 1 : 0;
  XFlush(w->dpy);  
}
