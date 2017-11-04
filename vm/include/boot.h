/*
** boot.h for vm in ~/c/rendu/projs/corewar/vm
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Wed Nov 28 17:38:14 2001 GIZMO
** Last update Sat Jan 12 12:19:44 2002 julien gein
*/

#ifndef BOOT_H_
# define BOOT_H_

int	boot(t_vm *vm, t_list *file);
int	shutdown_vm(t_vm *vm);
void	winner(t_vm *vm);

#endif /* !BOOT_H_ */
