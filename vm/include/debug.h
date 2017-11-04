/*
** debug.h for vm in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Mon Jan  7 20:43:04 2002 jean-daniel michaud
** Last update Tue Jan  8 14:14:24 2002 jean-daniel michaud
*/

#ifndef DEBUG_H_
# define DEBUG_H_

void	show_vm(t_vm *vm);
void	show_file(t_list *file);
void	show_buffwrite(t_dlist *list);
int	still_alive(t_vm *vm);
void	usage(void);

#endif /* !DEBUG_H_ */
