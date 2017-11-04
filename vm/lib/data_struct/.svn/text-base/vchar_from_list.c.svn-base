/*
** vchar_from_list.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Wed Dec 19 12:10:08 2001 julien gein
** Last update Wed Dec 19 14:07:00 2001 julien gein
*/

#include "data_struct.h"

char		**vchar_from_list(t_list *list)
{
  unsigned int	size;
  unsigned int	i;
  char		**res;
  char		*str;

  size = list_size(list);
  res = xmalloc(sizeof (char *) * (size + 1));
  for (i = 0; i < size; i++, list = list->next)
    {
      str = list->elem;
      res[i] = str;
    }
  res[i] = 0;
  return (res);
}
