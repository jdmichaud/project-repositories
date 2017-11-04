/*
** list_put.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Tue Oct  2 20:18:43 2001 julien gein
** Last update Sun Dec 30 17:17:57 2001 romain bottier
*/

#include <stdlib.h>
#include "data_struct.h"

void		list_put(t_list **list, void *elem)
{
  t_list	*new;
  
  new = xmalloc(sizeof (t_list));
  new->elem = elem;
  new->next = *list;
  *list = new;
}
