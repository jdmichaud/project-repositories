/*
** utils.h for regis in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Dec  6 14:26:22 2001 jean-daniel michaud
** Last update Sun Dec  9 11:28:28 2001 jean-daniel michaud
*/

#ifndef UTILS_H_
# define UTILS_H_

int		isempty(int *tab, int n);
int		isnear(t_matrix *matrix, int node, t_list *neighb);
void		spile(t_matrix *matrix, t_list *list);
void		err_spile(t_matrix *matrix, t_list *list);
int		iscolorize(t_list *list);

#endif
