/*
** list.c for 21sh in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Dec  4 14:28:08 2001 jean-daniel michaud
** Last update Sun Dec  9 19:34:57 2001 jean-daniel michaud
*/

#include <stdio.h>
#include <stdlib.h>

#include "defs.h"
#include "struct.h"
#include "list.h"
#include "xmalloc.h"

void		hadd(t_list **list, void *elem)
{
  t_list	*tmp;
  
  if (!*list)
    {
      *list = xmalloc(sizeof (t_list));
      (*list)->next = NULL;
    }
  else
    {
      tmp = xmalloc(sizeof (t_list));
      tmp->next = *list;
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
    }
  else
    {
      for (tmp = *list; tmp->next; tmp = tmp->next)
	;
      tmp->next = xmalloc(sizeof (t_list));
      tmp->next->elem = elem;
      tmp->next->next = NULL;
    }
}

void		*dummy_pop(t_list **list)
{
  t_list	*tmp;

  tmp = *list;
  *list = (*list)->next;
  return (tmp->elem);
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
