/*
** dlist_apply.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Wed Oct  3 21:00:41 2001 GIZMO
** Last update Thu Oct  4 00:33:46 2001 GIZMO
*/

#include "dlist.h"

void		dlist_apply(t_dlist *dlist, void (*f)(void *))
{
  t_dlist	*tmp;
  
  tmp = dlist;
  while (tmp != 0)
    {
      f(tmp->elem);
      tmp = tmp->next;
    }
}
