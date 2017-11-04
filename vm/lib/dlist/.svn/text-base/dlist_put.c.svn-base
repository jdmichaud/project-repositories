/*
** dlist_put.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Wed Oct  3 20:41:24 2001 GIZMO
** Last update Thu Oct  4 00:36:46 2001 GIZMO
*/

#include <stdlib.h>
#include "dlist.h"

void		dlist_put(t_dlist **dlist, void *elem)
{
  t_dlist	*tmp;
  t_dlist	*new;
  
  if (dlist)
    {
      tmp = *dlist;
      new = malloc(sizeof (t_dlist));
      new->elem = elem;
      new->prev = 0;
      if (tmp == 0)
	new->next = 0;
      else
	{
	  new->next = tmp;
	  tmp->prev = new;
	}
      *dlist = new;
    }
}
