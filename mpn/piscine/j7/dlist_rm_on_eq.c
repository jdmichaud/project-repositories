/*
** dlist_rm_on_eq.c for dlist_rm_on_eq in ~/c/rendu/piscine/j7
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Oct  3 21:59:59 2001 jean-daniel michaud
** Last update Thu Oct  4 02:32:57 2001 jean-daniel michaud
*/

#include "list.h"
#include "dlist.h"

void	free(void *);

void	dlist_rm_on_eq(t_dlist **dlist, void *elem, t_cmpfunc cmp)
{
  t_dlist	*l;
  t_dlist	*tmp;

  l = *dlist;
  if (!cmp(l->elem, elem))
    {
      (*dlist) = l->next;
      free(l);
    }
  for (; l->next != 0; l = l->next)
    if (!cmp(l->next->elem, elem))
      {
	tmp = l->next;
	l->next = tmp->next;
	if (tmp->next != 0)
	  tmp->next->prev = l;
	free(tmp);
      }
}
