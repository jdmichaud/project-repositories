/*
** mkgraph.h for regis in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Dec  5 18:24:07 2001 jean-daniel michaud
** Last update Mon Dec 10 14:33:43 2001 jean-daniel michaud
*/

#ifndef MKGRAPH_H_
# define MKGRAPH_H_

void		syntax_error(void);
t_matrix	*make_graph(void);
void		make_vertex(t_matrix *matrix, int ret);
void		make_lnode(t_matrix *matrix);
void		make_choice(int **choice, t_matrix *matrix);

#endif
