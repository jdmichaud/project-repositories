/*
** process.h for vm in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Fri Jan  4 16:06:18 2002 jean-daniel michaud
** Last update Thu Jan 10 21:33:03 2002 GIZMO
*/

#ifndef PROCESS_H_
# define PROCESS_H_

t_process	*get_process(t_vm *vm, unsigned int prid);
int		del_process(t_dlist *process);
t_player	*get_player_from_prid(t_vm *vm, unsigned int prid);
t_process	*new_process(t_vm *vm, t_player *player);
t_process	*fork_process(t_vm *vm, t_player *player, t_process *process);

unsigned short	next_process(t_vm *vm, unsigned int prid);
unsigned short	prev_process(t_vm *vm, unsigned int prid);
unsigned short	next_alive_from_player(t_vm *vm, int id);

#endif /* PROCESS_H_ */
