/*
** list_find_node.c for list_find_node in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 22:52:49 2001 jean-daniel michaud
** Last update Thu Oct  4 03:31:25 2001 jean-daniel michaud
*/

#include "list.h"
#include "dlist.h"

t_dlist	*dlist_find_node(t_dlist *dlist, void *elem, t_cmpfunc cmp)
{
  for (; dlist != 0; dlist = dlist->next)
    if (!cmp(dlist->elem, elem))
      return (dlist);
  return (0);
}
