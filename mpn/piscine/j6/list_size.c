/*
** list_size.c for list_size in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 22:30:03 2001 jean-daniel michaud
** Last update Wed Oct  3 03:02:36 2001 jean-daniel michaud
*/

#include "list.h"
#define	NULL	0

unsigned int	list_size(t_list *list)
{
  unsigned int	size;
  
  if (!list)
    return (0);
  for (size = 0; list != NULL; list = list->next)
    ++size;
  return (size + 1);
}
