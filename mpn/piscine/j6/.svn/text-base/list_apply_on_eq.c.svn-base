/*
** list_apply_on_eq.c for list_apply_on_eq in ~/c/renduy/piscine/j6/
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 22:33:59 2001 jean-daniel michaud
** Last update Tue Oct  2 22:41:35 2001 jean-daniel michaud
*/

#include "list.h"
#define	NULL	0


void	list_apply_on_eq(t_list *list, void *elem, t_cmpfunc cmp, 
			void (*f)(void *))
{
  for (; list != NULL; list = list->next)
    if (!cmp(list->elem, elem))
      f(list->elem);
}
