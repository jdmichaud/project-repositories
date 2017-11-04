/*
** dlist_find_elm_eq.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Wed Oct  3 21:13:47 2001 GIZMO
** Last update Thu Oct  4 00:34:46 2001 GIZMO
*/

#include "dlist.h"

void		*dlist_find_elm_eq(t_dlist *dlist, void *elem, t_cmpfunc cmp)
{
  t_dlist	*tmp;

  tmp = dlist;
  while (tmp != 0)
    {
      if (cmp(tmp->elem, elem) == 0)
	return (tmp->elem);
      tmp = tmp->next;
    }
  return (0);
}
