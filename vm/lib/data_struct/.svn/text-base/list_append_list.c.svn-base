/*
** list_append_list.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Fri Dec 21 18:16:17 2001 julien gein
** Last update Fri Dec 21 18:18:48 2001 julien gein
*/

#include "data_struct.h"

void		list_append_list(t_list **list, t_list *add)
{
  t_list	*tmp;
  
  if (*list)
    {
      tmp = *list;
      while (tmp->next)
	tmp = tmp->next;
      tmp->next = add;
    }
  else
    *list = add;
}
