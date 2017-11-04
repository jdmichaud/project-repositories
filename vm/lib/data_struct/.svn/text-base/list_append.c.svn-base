/*
** list_append.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Tue Oct  2 20:21:45 2001 julien gein
** Last update Sun Dec 30 17:17:39 2001 romain bottier
*/

#include <stdlib.h>
#include "data_struct.h"

void		list_append(t_list **list, void *elem)
{
  t_list	*new;
  t_list	*tmp;
  
  new = xmalloc(sizeof (t_list));
  new->elem = elem;
  new->next = 0;
  if (*list)
    {
      tmp = *list;
      while (tmp->next)
	tmp = tmp->next;
      tmp->next = new;
    }
  else
    *list = new;
}
