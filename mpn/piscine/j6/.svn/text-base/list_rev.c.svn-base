/*
** list_rev.c for list_rev in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 21:03:41 2001 jean-daniel michaud
** Last update Wed Oct  3 02:03:24 2001 jean-daniel michaud
*/

#include "list.h"
#define	NULL	0

void		list_rev(t_list **list)
{
  t_list	*head;
  t_list	*tmp;
  t_list	*new_list;

  head = *list;
  new_list = NULL;
  while (head != NULL)
    {
      list_put(&new_list, head->elem);
      tmp = head;
      head = head->next;
      free(tmp);
    }
  *list = new_list;
}
