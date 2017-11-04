/*
** list_free.c for list_free in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 23:58:37 2001 jean-daniel michaud
** Last update Sun Oct  7 15:22:18 2001 jean-daniel michaud
*/

#include "list.h"

void		list_free(t_list **list)
{
  t_list	*l;
  t_list	*prev;

  l = *list;
  while (l)
    {
      prev = l;
      l = l->next;
      free(prev);
    }
  *list = NULL;
}
