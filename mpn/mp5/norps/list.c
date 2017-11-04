/*
** list.c for beswitch in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Nov  7 15:44:49 2001 jean-daniel michaud
** Last update Tue Dec  4 04:05:48 2001 jean-daniel michaud
*/

#include <stdlib.h>
#include <stdio.h>

#include "list.h"

void		push(t_list **list, char c)
{
  t_list	*tmp;

  if (!*list)
    {
      if ((*list = malloc(sizeof (t_list))) == NULL)
	exit(1);
      (*list)->next = NULL;
    }
  else
    {
      if ((tmp = malloc(sizeof (t_list))) == NULL)
	exit(1);
      tmp->next = *list;
      *list = tmp;
    }
  (*list)->c = c;
}

char		pop(t_list **list)
{
  char		tmp;
  t_list	*todel;

  if (*list)
    {
      tmp = (*list)->c;
      todel = *list;
      *list = (*list)->next;
      free(todel);
      return (tmp);
    }
  return (NULL);
}

unsigned int	size(t_list *list)
{
  unsigned int	size;

  for (size = 0; list; ++size)
    list = list->next;
  return (size);
}

char		*collapse(t_list *list)
{
  char		*str;
  unsigned int	i;

  if (list)
    {
      str = malloc((size(list) + 1) * sizeof (char));
      for (i = size(list) - 1; list; --i, list = list->next)
	str[i] = list->c;
      return (str);
    }
  return (NULL);
}

void		free_list(t_list **list)
{
  t_list	*l;
  t_list	*ll;

  for (l = *list; l; l = ll)
    {
      ll = l->next;
      free(l);
    }
  *list = NULL;
}
