/*
** list.c for 21sh in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Dec  4 14:28:08 2001 jean-daniel michaud
** Last update Wed Dec 12 11:36:26 2001 jean-daniel michaud
*/

#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "xmalloc.h"

void		hadd(t_list **list, void *elem)
{
  t_list	*tmp;
  
  if (!*list)
    {
      *list = xmalloc(sizeof (t_list));
      (*list)->next = NULL;
      (*list)->prec = NULL;      
    }
  else
    {
      tmp = xmalloc(sizeof (t_list));
      tmp->next = *list;
      (*list)->prec = tmp;
      *list = tmp;
    }
  (*list)->elem = elem;
}

void		qadd(t_list **list, void *elem)
{
  t_list	*tmp;

  if (!*list)
    {
      *list = xmalloc(sizeof (t_list));
      (*list)->elem = elem;
      (*list)->next = NULL;
      (*list)->prec = NULL;
    }
  else
    {
      for (tmp = *list; tmp->next; tmp = tmp->next)
	;
      tmp->next = xmalloc(sizeof (t_list));
      tmp->next->elem = elem;
      tmp->next->prec = tmp;
      tmp->next->next = NULL;
    }
}

void		add_sort(t_list **list, void *elem, t_cmpfunc cmp)
{
  t_list	*seek;
  t_list	*prec;
  t_list	*tmp;

  if (!list)
    {
      *list = xmalloc(sizeof (t_list));
      (*list)->elem = elem;
      (*list)->prec = NULL;
      (*list)->next = NULL;
    }
  else
    {
      for (seek = *list; cmp(seek->elem, elem); seek = seek->next)
	prec = seek;
      tmp = xmalloc(sizeof (t_list));
      tmp->elem = elem;
      tmp->next = prec->next;
      tmp->next->prec = tmp;
      tmp->prec = prec;
      prec->next = tmp;
    }
}

int 		lsize(t_list *list)
{
  int		i;

  for (i = 0; list; ++i)
    list = list->next;
  return (i);
}


void		lfree(t_list **list, t_freefunc ffree)
{
  t_list	*tmp;
  
  while (*list)
    {
      tmp = *list;
      *list = (*list)->next;
      ffree(tmp->elem);
      free(tmp);
    }
}
