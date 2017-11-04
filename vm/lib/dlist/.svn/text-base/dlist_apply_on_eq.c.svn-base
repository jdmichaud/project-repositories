/*
** dlist_apply_on_eq.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Wed Oct  3 21:05:34 2001 GIZMO
** Last update Thu Oct  4 00:34:20 2001 GIZMO
*/

#include "dlist.h"

void		dlist_apply_on_eq(t_dlist	*dlist,
				  void		*elem,
				  t_cmpfunc	cmp,
				  void		(*f)(void *))
{
  t_dlist	*tmp;

  tmp = dlist;
  while (tmp != 0)
    {
      if (cmp(tmp->elem, elem) == 0)
	f(tmp->elem);
      tmp = tmp->next;
    }
}
