/*
** dlist_from_list.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Wed Oct  3 23:27:05 2001 GIZMO
** Last update Sun Jan  6 17:34:13 2002 jean-daniel michaud
*/

#include "dlist.h"

t_dlist		*dlist_from_list(t_list *list)
{
  t_dlist	*dlist;

  dlist = 0;
  while (list != 0)
    {
      dlist_append(&dlist, list->elem);
      list = list->next;
    }
  return (dlist);
}
