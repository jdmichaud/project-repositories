/*
** pile.c for bistromathique in ~/c/rendu/projs/bistromathique
** 
** Made by jonathan mimouni
** Login   <mimoun_j@epita.fr>
** 
** Started on  Sun Oct 21 01:22:51 2001 jonathan mimouni
** Last update Sat Oct 27 13:32:15 2001 jonathan mimouni
*/

#include <stdlib.h>
#include "bistromathique.h"
#include "utils_str.h"
#include "pile.h"

void		push_op(t_pile_op **pile, char elem)
{
  t_pile_op	*p;

  if ((p = malloc(sizeof (t_pile_op))) != NULL)
    {
      p->elem = elem;
      p->next = *pile;
      *pile = p;
    }
}

char		pop_op(t_pile_op **pile)
{
  t_pile_op	*p;
  char		i;
  
  p = *pile;
  if (p == NULL)
    return (NULL);
  else
    {
      *pile = p->next;
      i = p->elem;
      free(p);
      return (i);
    }
}

void		push_str(t_pile_str **pile, char *elem)
{
  t_pile_str	*p;

  if ((p = malloc(sizeof (t_pile_op))) != NULL)
    {
      p->elem = malloc(my_strlen(elem));
      my_strcpy(p->elem, elem);
      p->next = *pile;
      *pile = p;
    }
}

char		*pop_str(t_pile_str **pile)
{
  t_pile_str	*p;
  char		*i;
  
  p = *pile;
  if (p == NULL)
    return (NULL);
  else
    {
      *pile = p->next;
      i = malloc(my_strlen(p->elem) + 1);
      my_strcpy(i, p->elem);
      free(p->elem);
      free(p);
      return (i);
    }
}

