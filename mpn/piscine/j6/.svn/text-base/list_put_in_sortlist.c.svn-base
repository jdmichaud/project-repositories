/*
** list_put_in_sortlist.c for list_put_in_sortlist in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 22:57:12 2001 jean-daniel michaud
** Last update Wed Oct  3 01:31:58 2001 jean-daniel michaud
*/

#include "list.h"
#define	NULL	0

void	*malloc(unsigned int);

void		list_put_in_sortlist(t_list **list, void *elem, t_cmpfunc cmp)
{
  t_list	*l;
  t_list	*tmp;
  t_list	*prec;

  prec = NULL;
  for (l = *list; ((l != 0) && (cmp(elem, l->elem) > 0)); l = l->next)
    prec = l;
  if (l == NULL)
    list_append(list, elem);
  else
    {
      if ((tmp = malloc(sizeof (t_list))) == NULL)
	return;
      tmp->elem = elem;
      tmp->next = l;
      if (prec != NULL)
	prec->next = tmp;
    }
}
