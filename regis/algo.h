/*
** algo.h for regis in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Dec  6 10:32:43 2001 jean-daniel michaud
** Last update Mon Dec 10 12:31:19 2001 jean-daniel michaud
*/

#ifndef ALGO_H_
# define ALGO_H_

t_list	*reduce(t_matrix *matrix, int node);
int	colorize(t_matrix *matrix, t_list *head, t_list *current);
int	nkill(t_matrix *matrix, t_list **list, int *choice);
void	freeto(t_list **begin, t_list *end);
t_list	*spill(t_matrix	*matrix, 
	      t_list	**head, 
	      t_list	*current, 
	      int	*choice);

#endif
