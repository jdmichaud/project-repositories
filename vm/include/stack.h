/*
** stack.h for vm in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Fri Jan  4 14:43:46 2002 jean-daniel michaud
** Last update Sat Jan  5 10:37:59 2002 jean-daniel michaud
*/

#ifndef STACK_H_
# define STACK_H_

int _push_(t_process *process, unsigned short quad);
int _pop_(t_process *process, unsigned short *quad);

#endif
