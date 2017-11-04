/*
** dlist_rev.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Wed Oct  3 20:50:57 2001 GIZMO
** Last update Thu Oct  4 00:37:38 2001 GIZMO
*/

#include "dlist.h"

void		dlist_rev(t_dlist **dlist)
{
  t_dlist	*tmp;
  t_dlist	*save;
  t_dlist	*first;

  if ((dlist != 0) && (*dlist != 0))
    {
      tmp = *dlist;
      first = 0;
      while (tmp != 0)
	{
	  save = tmp->next;
	  tmp->next = tmp->prev;
	  tmp->prev = save;
	  first = tmp;
	  tmp = save;
	}
      *dlist = first;
    }
}
