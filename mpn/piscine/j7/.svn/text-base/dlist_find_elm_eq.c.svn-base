/*
** list_find_elm_eq.c for list_find_elm_eq in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 22:42:37 2001 jean-daniel michaud
** Last update Wed Oct  3 22:37:36 2001 jean-daniel michaud
*/

#include "list.h"
#include "dlist.h"

void	*dlist_find_elm_eq(t_dlist *dlist, void *elem, t_cmpfunc cmp)
{
  for (; dlist != 0; dlist = dlist->next)
    if (!cmp(dlist->elem, elem))
      return (dlist->elem);
  return (0);
}
