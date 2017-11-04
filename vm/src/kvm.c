/*
** kvm.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Nov 29 14:55:01 2001 GIZMO
** Last update Fri Jan 11 21:18:06 2002 jean-daniel michaud
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>

#include "my_struct.h"
#include "my_printf.h"
#include "register.h"
#include "options.h"
#include "process.h"
#include "player.h"
#include "dlist.h"
#include "stack.h"
#include "init.h"
#include "boot.h"
#include "mem.h"
#include "run.h"
#include "my.h"

int	main(int argc, char **argv)
{
  t_vm	*vm;
  char	c;

  vm = init(argv);
  boot(vm, get_filename(argv));
  run_vm(vm);
  if (vm->interface)
    {
      my_printf("\nHit enter\n");
      read(0, &c, 1);
    }
  shutdown_vm(vm);
  return (0);
}

