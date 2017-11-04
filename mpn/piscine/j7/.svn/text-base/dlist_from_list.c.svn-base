/*
** dlist_from_list.c for dlist_from_list in ~/c/rendu/piscine/j7
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Oct  3 23:18:00 2001 jean-daniel michaud
** Last update Thu Oct  4 00:02:35 2001 jean-daniel michaud
*/

#include "list.h"
#include "dlist.h"

t_dlist		*dlist_from_list(t_list *list)
{
  t_dlist	*dl;

  dl = 0;
  for (; list != 0; list = list->next)
    dlist_append(&dl, list->elem);
  return (dl);
}
