/*
** show.h for mini-ls in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Fri Nov 16 09:07:25 2001 jean-daniel michaud
** Last update Sun Nov 18 17:33:42 2001 jean-daniel michaud
*/

#ifndef SHOW_H_
# define SHOW_H_

void	show(t_list_file *list, int option);
void	show_hide(t_list_file *file, int option);
void	show_no_hide(t_list_file *file, int option);
void	show_file(t_list_file *file, int option, unsigned int max);
void	show_right(mode_t mode);


#endif
