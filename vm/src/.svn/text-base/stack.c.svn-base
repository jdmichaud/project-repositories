/*
** stack.c for vm in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Fri Jan  4 14:46:26 2002 jean-daniel michaud
** Last update Sat Jan  5 11:05:17 2002 jean-daniel michaud
*/

#include <stdio.h>

#include "my_struct.h"
#include "stack.h"

int _push_(t_process *process, unsigned short quad)
{
  process->stack_pos %= 16;
  process->stack[process->stack_pos] = quad;
  ++(process->stack_pos);
  return (process->stack_pos);
}

int _pop_(t_process *process, unsigned short *quad)
{
  fflush(stdout);
  if (--(process->stack_pos) > 16)
    process->stack_pos = 15;
  *quad = process->stack[process->stack_pos];
  return (process->stack_pos);
}
