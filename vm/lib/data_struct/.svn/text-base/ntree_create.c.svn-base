/*
** ntree_create.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Wed Dec 19 11:41:30 2001 julien gein
** Last update Wed Dec 19 12:00:23 2001 julien gein
*/

#include "data_struct.h"

t_ntree		*ntree_create(void *elem, t_list *childs)
{
  t_ntree	*res;
  
  res = xmalloc(sizeof (t_ntree));
  res->elem = elem;
  res->childs = childs;
  return (res);
}
