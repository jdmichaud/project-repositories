/*
** list_find_elm_eq.c for list_find_elm_eq in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 22:42:37 2001 jean-daniel michaud
** Last update Wed Oct  3 02:27:50 2001 jean-daniel michaud
*/

#include "list.h"
#define	NULL	0

void	*list_find_elm_eq(t_list *list, void *elem, t_cmpfunc cmp)
{
  for (; list != NULL; list = list->next)
    if (!cmp(list->elem, elem))
      return (list->elem);
  return (NULL);
}
