/*
** list_find_node.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Tue Oct  2 21:54:48 2001 julien gein
** Last update Wed Dec 19 12:04:45 2001 julien gein
*/

#include "data_struct.h"

t_list		*list_find_node(t_list *list, void *elem, t_cmpfunc cmp)
{
  t_list	*tmp;
  
  for (tmp = list; tmp; tmp = tmp->next)
    if (cmp(elem, tmp->elem) == 0)
      return (tmp);
  return (0); 
}
