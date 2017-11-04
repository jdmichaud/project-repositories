/*
** list_put_in_sortlist.c for list_put_in_sortlist in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 22:57:12 2001 jean-daniel michaud
** Last update Thu Oct  4 03:14:34 2001 jean-daniel michaud
*/

#include "list.h"
#include "dlist.h"

void	*malloc(unsigned int);

void		dlist_put_in_sortdlist(t_dlist **dlist, void *elem, 
					t_cmpfunc cmp)
{
  t_dlist	*l;
  t_dlist	*tmp;

  if (cmp(elem, (*dlist)->elem) > 0)
    dlist_put(dlist, elem);
  for (l = *dlist; ((l != 0) && (cmp(elem, l->elem) > 0)); l = l->next)
    ;
  if (l == 0)
    dlist_append(dlist, elem);
  else
    {
      if ((tmp = malloc(sizeof (t_dlist))) == 0)
	return;
      tmp->elem = elem;
      tmp->next = l;
      tmp->prev = l->prev;
      if (l->prev != 0)
	tmp->prev->next = tmp;
      l->prev = tmp;
      if (!tmp->prev)
	*dlist = tmp;
    }
}
