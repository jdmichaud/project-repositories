/*
** dlist_put_in_sortdlist.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Wed Oct  3 21:16:29 2001 GIZMO
** Last update Sun Nov 11 23:19:30 2001 GIZMO
*/

#include <stdlib.h>
#include "dlist.h"

void		dlist_put_in_sortdlist(t_dlist		**dlist,
				       void		*elem,
				       t_cmpfunc	cmp)
{
  dlist_put(dlist, elem);
  dlist_sort(dlist, cmp);
}
