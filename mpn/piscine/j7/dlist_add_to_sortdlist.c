/*
** list_add_to_sortlist.c for list_add_to_sortlist.c in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 23:41:31 2001 jean-daniel michaud
** Last update Wed Oct  3 23:32:36 2001 jean-daniel michaud
*/

#include "list.h"
#include "dlist.h"

void    *malloc(unsigned int);
t_dlist		*put_in_sortdlist(t_dlist **dlist, void *elem, t_cmpfunc cmp);

t_dlist		*put_in_sortdlist(t_dlist **dlist, void *elem, t_cmpfunc cmp)
{
  t_dlist	*l;
  t_dlist	*tmp;
  
  for (l = *dlist; ((l != 0) && (cmp(elem, l->elem) > 0)); l = l->next)
    ;
  if (l == 0)
    dlist_append(dlist, elem);
  else
    {
      if ((tmp = malloc(sizeof (t_dlist))) == 0)
	return (0);
      tmp->elem = elem;
      tmp->next = l;
      tmp->prev = l->prev;
      l->prev = tmp;
      if (l->prev != 0)
	tmp->prev->next = tmp;
    }
  return (tmp->next);
}

void		dlist_add_to_sortdlist(t_dlist **dest, t_dlist *src, 
					t_cmpfunc cmp)
{
  t_dlist	*l;

  for (l = *dest; src != 0; src = src->next)
    l = put_in_sortdlist(&l, src->elem, cmp);
}

