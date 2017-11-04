/*
** dlist_apply_on_node.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Wed Oct  3 21:02:44 2001 GIZMO
** Last update Thu Oct  4 00:34:35 2001 GIZMO
*/

#include "dlist.h"

void		dlist_apply_on_node(t_dlist *dlist, void (*f)(t_dlist *))
{
  t_dlist	*tmp;
  
  tmp = dlist;
  while (tmp != 0)
    {
      f(tmp);
      tmp = tmp->next;
    }
}
