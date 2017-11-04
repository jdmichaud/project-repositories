/*
** list_add_to_sortlist.c for list_add_to_sortlist.c in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 23:41:31 2001 jean-daniel michaud
** Last update Wed Oct  3 02:51:03 2001 jean-daniel michaud
*/

#include "list.h"
#define	NULL	0

void    *malloc(unsigned int);

t_list		*put_in_sortlist(t_list **list, void *elem, t_cmpfunc cmp)
{
  t_list        *l;
  t_list        *tmp;
  t_list        *prec;

  prec = NULL;
  for (l = *list; ((l != 0) && (cmp(elem, l->elem) > 0)); l = l->next)
    prec = l;
  if (l == NULL)
    list_append(list, elem);
  else
    {
      if ((tmp = malloc(sizeof (t_list))) == NULL)
	return (NULL);
      tmp->elem = elem;
      tmp->next = l;
      if (prec != NULL)
        prec->next = tmp;
    }
  return (tmp->next);
}

void		list_add_to_sortlist(t_list **dest, t_list *src, t_cmpfunc cmp)
{
  t_list	*l;

  for (l = *dest; src != NULL; src = src->next)
    l = put_in_sortlist(&l, src->elem, cmp);
}

