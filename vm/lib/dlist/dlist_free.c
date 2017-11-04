/*
** dlist_free.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Wed Oct  3 21:24:09 2001 GIZMO
** Last update Thu Jan 10 18:21:57 2002 romain bottier
*/

#include <stdlib.h>
#include "dlist.h"

void		dlist_free(t_dlist **dlist)
{
  t_dlist	*tmp;
  t_dlist	*save;

  if (dlist)
    {
      tmp = *dlist;
      while (tmp != 0)
	{
	  save = tmp;
	  tmp = tmp->next;
	  free(save->elem);
	  free(save);
	  save = 0;
	}
      *dlist = 0;
    }
}
