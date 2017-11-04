/*
** list_inlist.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Fri Dec 21 17:51:56 2001 julien gein
** Last update Fri Dec 21 18:04:50 2001 julien gein
*/

#include "data_struct.h"

t_list		*list_inslist_pb(t_list *list, t_list *add)
{
  t_list	*res;
  t_list	*tmp;

  if (!add)
    return (list);
  res = list->next;
  list->next = add;
  for (tmp = add; tmp->next; tmp = tmp->next)
    ;
  tmp->next = res;
  return (res);
}
