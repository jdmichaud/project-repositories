/*
** list_find_node.c for list_find_node in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 22:52:49 2001 jean-daniel michaud
** Last update Sun Oct  7 15:23:39 2001 jean-daniel michaud
*/

#include "list.h"

t_list	*list_find_node(t_list *list, void *elem, t_cmpfunc cmp)
{
  for (; list != NULL; list = list->next)
    if (!cmp(list->elem, elem))
      return (list);
  return (NULL);
}
