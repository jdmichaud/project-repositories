/*
** list_add_to_list.c for list_add_to_list in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 23:26:57 2001 jean-daniel michaud
** Last update Tue Oct  2 23:31:18 2001 jean-daniel michaud
*/

#include "list.h"
#define	NULL	0

void		list_add_to_list(t_list **dest, t_list *src)
{
  t_list	*l;
  t_list	*lsrc;

  if (*dest == NULL)
    *dest = src;
  for (l = *dest; l->next != NULL; l = l->next)
    ;
  l->next = src;
}
