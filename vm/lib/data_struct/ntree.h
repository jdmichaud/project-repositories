/*
** ntree.h for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Wed Dec 19 11:42:33 2001 julien gein
** Last update Wed Dec 19 11:56:51 2001 julien gein
*/

#ifndef NTREE_H_
# define NTREE_H_

# include "list.h"

typedef struct	n_tree
{
  void		*elem;
  t_list	*childs;
}		t_tree;

int		cmp_node(void *elem, void *node);
t_ntree		*ntree_create(void *elem, t_list *childs);
t_ntree		*ntree_find_node(t_ntree *root, void *elem, t_cmpfunc fct);

#endif /* NTREE_H_ */
