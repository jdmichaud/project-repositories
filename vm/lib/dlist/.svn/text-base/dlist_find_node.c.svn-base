/*
** dlist_find_node.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Wed Oct  3 21:15:08 2001 GIZMO
** Last update Thu Oct  4 00:35:07 2001 GIZMO
*/

#include "dlist.h"

t_dlist		*dlist_find_node(t_dlist *dlist, void *elem, t_cmpfunc cmp)
{
  t_dlist	*tmp;

  tmp = dlist;
  while (tmp != 0)
    {
      if (cmp(tmp->elem, elem) == 0)
	return (tmp);
      tmp = tmp->next;
    }
  return (0);
}
