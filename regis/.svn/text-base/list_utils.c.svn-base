/*
** list_utils.c for regis in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Dec  5 18:44:06 2001 jean-daniel michaud
** Last update Thu Dec  6 14:37:18 2001 jean-daniel michaud
*/

#include "defs.h"
#include "struct.h"
#include "list_utils.h"

int	listsize(t_list *list)
{
  int	i;

  for (i = 0; list; list = list->next, ++i)
    ;
  return (i);
}

int	getindice(t_list *list, char *name)
{
  char	*tmp;
  int	i;
  
  for (i = 0, tmp = list->elem; list && strcmp(tmp, name); ++i)
    {
      list = list->next;
      tmp = list->elem;
    }
  if (list)
    return (i);
  return (0);
}

char	*getname(t_list *list, int node)
{
  int	i;

  for (i = 0; list && i != node; ++i, list = list->next)
    ;
  return (list->elem);
}
