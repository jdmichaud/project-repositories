/*
** dlist_add_to_sortdlist.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Wed Oct  3 21:22:57 2001 GIZMO
** Last update Thu Nov 29 15:09:14 2001 GIZMO
*/

#include "dlist.h"

void	dlist_add_to_sortdlist(t_dlist **dest, t_dlist *src, t_cmpfunc cmp)
{
  if (dest)
    {
      while (src != 0)
	{
	  dlist_put(dest, src->elem);
	  src = src->next;
	}
      dlist_sort(dest, cmp);
      dlist_free(&src);
    }
}
