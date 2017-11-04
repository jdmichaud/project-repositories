/*
** pile.c for pile in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sun Oct  7 16:35:28 2001 jean-daniel michaud
** Last update Sun Oct  7 23:19:26 2001 jean-daniel michaud
*/

#include "eval_expr.h"

int		push(t_pile **p, int a)
{
  t_pile	*pile;

  pile = malloc(sizeof (t_pile));
  pile->val = a;
  pile->next = *p;
  *p = pile;
  return (a);
}

int		pop(t_pile **p)
{
  t_pile	*pile;
  int		res;

  pile = *p;
  if (*p)
    {
      *p = (*p)->next;
      res = pile->val;
      free(pile);
      return (res);
    }
  return (NULL);
}

int		collapse(t_pile *p)
{
  int		res;

  res = 0;
  while (p)
    res += pop(&p);
  return (res);
}
