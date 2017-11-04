/*
** dlist_add_to_dlist.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Wed Oct  3 21:21:47 2001 GIZMO
** Last update Thu Nov 29 15:08:51 2001 GIZMO
*/

#include "dlist.h"

void		dlist_add_to_dlist(t_dlist **dest, t_dlist *src)
{
  t_dlist	*tmp;
  t_dlist	*save;  
  
  if (dest != 0)
    {
      tmp = *dest;
      save = *dest;
      while (tmp != 0)
        {
          save = tmp;
          tmp = tmp->next;
        }
      save->next = src;
      src->prev = save;
    }
}
