/*
** list_rev.c for list_rev in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 21:03:41 2001 jean-daniel michaud
** Last update Thu Oct  4 02:04:49 2001 jean-daniel michaud
*/

#include "list.h"
#include "dlist.h"

void		dlist_rev(t_dlist **dlist)
{ 
  t_dlist	*tmp;
  t_dlist	*l;
  
  if (!(*dlist))
    return;
  l = *dlist;
  while (l->next != 0)
    {
      tmp = l->next;
      l->next = l->prev;
      l->prev = tmp;
      l = tmp;
    }
  tmp = l->next;
  l->next = l->prev;
  l->prev = tmp;
  *dlist = l;
}
