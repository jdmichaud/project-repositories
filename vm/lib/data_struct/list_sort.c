/*
** list_sort.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Tue Oct  2 20:44:38 2001 julien gein
** Last update Wed Dec 19 12:05:27 2001 julien gein
*/

#include "data_struct.h"

void		list_sort(t_list **list, t_cmpfunc cmp)
{
  t_list	*tmp;
  t_list	*tmp2;
  t_list	*save_pos;
  void		*save_elem;
  
  if ((*list) && ((*list)->next))
    {
      for (tmp = *list; tmp; tmp = tmp->next)
	{
	  save_pos = tmp;
	  for (tmp2 = tmp->next; tmp2; tmp2 = tmp2->next)
	    {
	      if (cmp(save_pos->elem, tmp2->elem) > 0)
		save_pos = tmp2;
	    }
	  if (save_pos != tmp)
	    {
	      save_elem = tmp->elem;
	      tmp->elem = save_pos->elem;
	      save_pos->elem = save_elem;
	    }
	}
    }
}
