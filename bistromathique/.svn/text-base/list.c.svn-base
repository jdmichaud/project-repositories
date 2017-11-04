/*
** list.c for  in 
** 
** Made by jonathan mimouni
** Login   <mimoun_j@epita.fr>
** 
** Started on  Tue Oct  9 14:59:29 2001 jonathan mimouni
** Last update Sun Oct 21 17:57:23 2001 jonathan mimouni
*/

#include <stdlib.h>
#include "bistromathique.h"
#include "print.h"
#include "list.h"

void		list_append(t_list **list, char elem)
{
  t_list	*p;
  
  if (*list == NULL)
    {
      if (((*list) = malloc(sizeof (t_list))) != NULL)
	{
	  (*list)->elem = elem;
	  (*list)->next = NULL;
	}
    }
  else
    {
      p = *list;
      while (p->next != NULL)
	p = p->next;
      if ((p->next = malloc(sizeof (t_list))) != NULL)
	{
	  p->next->elem = elem;
	  p->next->next = NULL;
	}
    }
}

void		list_free(t_list **list)
{
  t_list	*p;
  t_list	*prec;
  
  p = *list;
  while (p != NULL)
    {
      prec = p;
      p = p->next;
      free(prec);
    }
  *list = NULL;
}

void		list_print(t_list *list)
{
  for (; list != NULL; list = list->next)
    my_printchar(list->elem);
}






