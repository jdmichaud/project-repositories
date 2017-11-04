/*
** tab.h for regis in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Mon Dec 10 12:22:29 2001 jean-daniel michaud
** Last update Mon Dec 10 17:36:09 2001 jean-daniel michaud
*/

#ifndef TAB_H_
# define TAB_H_

void	dec_degree(t_matrix *matrix, int node);
void	inc_degree(t_matrix *matrix, int node);
void	update(t_matrix *matrix, int *choice);
void	freehere(t_matrix	*matrix, 
		 int		*choice, 
		 t_list		**current, 
		 t_stack	*stack);

#endif
