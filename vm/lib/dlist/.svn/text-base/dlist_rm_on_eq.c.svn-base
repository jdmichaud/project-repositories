/*
** dlist_rm_on_eq.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Wed Oct  3 21:07:23 2001 GIZMO
** Last update Thu Jan 10 18:23:43 2002 romain bottier
*/

#include <stdlib.h>
#include "dlist.h"

void		dlist_rm_on_eq(t_dlist		**dlist,
			       void		*elem,
			       t_cmpfunc	cmp)
{
  t_dlist	*tmp;
  t_dlist	*save;
  
  tmp = *dlist;
  while (tmp != 0)
    {
      save = 0;
      if (cmp(elem, tmp->elem) == 0)
	{
	  if (tmp->prev != 0)
	    tmp->prev->next = tmp->next;
	  else
	    *dlist = tmp->next;
	  if (tmp->next != 0)
		tmp->next->prev = tmp->prev;
	  save = tmp;
	}
      tmp = tmp->next;
      if (save)
	{
	  free(save->elem);
	  free(save);
	  save = 0;
	}
    }
}
