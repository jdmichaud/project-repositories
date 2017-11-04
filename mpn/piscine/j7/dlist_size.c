/*
** list_size.c for list_size in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 22:30:03 2001 jean-daniel michaud
** Last update Thu Oct  4 02:22:33 2001 jean-daniel michaud
*/

#include "list.h"
#include "dlist.h"

unsigned int	dlist_size(t_dlist *dlist)
{
  unsigned int	size;
  
  if (!dlist)
    return (0);
  for (size = 0; dlist != 0; dlist = dlist->next)
    ++size;
  return (size);
}
