/*
** ntree_find_node.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Wed Dec 19 11:45:25 2001 julien gein
** Last update Wed Dec 19 12:00:02 2001 julien gein
*/

#include "data_struct.h"

int		cmp_node(void *elem, void *node)
{
  t_ntree	*node_tree;
  char		*node_str;
  char		*elem_str;
  
  node_tree = node;
  node_str = node_tree->elem;
  elem_str = elem;
  return (strcmp(node_str,elem_str));
}

t_ntree		*ntree_find_node(t_ntree *root, void *elem, t_cmpfunc fct)
{
  t_ntree	*tmp;
  t_list	*childs;
  t_list	*list_res;
  t_ntree	*res;
  
  childs = root->childs;
  if ((list_res = list_find_node(childs, elem, fct)))
    {
      res = list_res->elem;
      return (res);
    }
  while (childs)
    {
      childs = childs->next;
      tmp = childs->elem;
      return (ntree_find_node(tmp, elem, fct));
    }
  return (0);
}
