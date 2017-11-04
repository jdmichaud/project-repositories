/*
** list_apply_on_eq.c for list_apply_on_eq in ~/c/renduy/piscine/j6/
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 22:33:59 2001 jean-daniel michaud
** Last update Thu Oct  4 03:15:35 2001 jean-daniel michaud
*/

#include "list.h"
#include "dlist.h"


void	dlist_apply_on_eq(t_dlist *dlist, void *elem, t_cmpfunc cmp, 
			void (*f)(void *))
{
  for (; dlist != 0; dlist = dlist->next)
    if (!cmp(dlist->elem, elem))
      f(dlist->elem);
}
