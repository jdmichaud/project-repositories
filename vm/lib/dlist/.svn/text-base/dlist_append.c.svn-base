/*
** dlist_append.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Wed Oct  3 20:45:49 2001 GIZMO
** Last update Sun Nov 11 23:40:59 2001 GIZMO
*/

#include <stdlib.h>
#include "dlist.h"

void		dlist_append(t_dlist **dlist, void *elem)
{
  t_dlist	*tmp;
  t_dlist	*new;
  t_dlist	*save;
  
  if (*dlist)
    { 
      if ((new = malloc(sizeof (t_dlist))))
	{
	  new->elem = elem;
	  new->next = 0;
	  if (*dlist == 0)
	    {
	      new->prev = 0;
	      *dlist = new;
	    }
	  else
	    {
	      for (tmp = *dlist, save = tmp; tmp != 0; tmp = tmp->next)
		save = tmp;
	      new->prev = save;
	      tmp->next = new;
	    }
	}
    }
}
