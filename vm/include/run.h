/*
** run.h for vm in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sun Jan  6 09:27:30 2002 jean-daniel michaud
** Last update Tue Jan  8 09:38:03 2002 jean-daniel michaud
*/

#ifndef RUN_H_
# define RUN_H_

void	run_vm(t_vm *vm);
int	age_process(t_vm *vm);
int	the_mower(t_vm *vm);
void	end_cycle(t_vm *vm);
void	process_cycle(t_vm *vm, t_process *process);

#endif
