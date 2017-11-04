/*
** dlist_to_list.c for dlist_to_list in ~/c/rendu/piscine/j7
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Oct  3 23:22:59 2001 jean-daniel michaud
** Last update Thu Oct  4 00:24:42 2001 jean-daniel michaud
*/

#include "list.h"
#include "dlist.h"

void    *malloc(unsigned int);
void            append(t_list **list, void *elem);

void            append(t_list **list, void *elem)
{
  t_list        *l;

  if (*list == 0)
    {
      if ((*list = malloc(sizeof (t_list))) == 0)
        return;
      (*list)->next = 0;
      (*list)->elem = elem;
    }
  else
    {
      for (l = *list; l->next != 0; l = l->next)
        ;
      if ((l->next = malloc(sizeof (t_list))) == 0)
        return;
      l->next->next = 0;
      l->next->elem = elem;
    }
}

t_list		*dlist_to_list(t_dlist *list)
{
  t_list	*l;

  l = 0;
  for (; list != 0; list = list->next)
    append(&l, list->elem);
  return (l);
}
