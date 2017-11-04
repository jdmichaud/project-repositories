/*
** graph.h for regis in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Dec  6 10:15:13 2001 jean-daniel michaud
** Last update Mon Dec 10 14:29:46 2001 jean-daniel michaud
*/

#ifndef GRAPH_H_
# define GRAPH_H_

int	degree(t_matrix *matrix, int inode);
int	find_nsnode(t_matrix *matrix);
int	lifr_node(int *tnode, t_matrix *matrix);
int	pure(int *nodes, int degree, int n);

#endif
