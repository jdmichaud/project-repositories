/*
** list_push.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Thu Dec 20 18:26:40 2001 julien gein
** Last update Thu Dec 20 18:28:19 2001 julien gein
*/

#include <stdlib.h>
#include "data_struct.h"

void		*list_push(t_list **list)
{
  void		*res;
  t_list	*tmp;
  
  res = (*list)->elem;
  tmp = *list;
  *list = (*list)->next;
  free(tmp);
  return (res);
}
