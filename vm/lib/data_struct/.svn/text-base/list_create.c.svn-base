/*
** list_create.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Wed Dec  5 11:25:53 2001 julien gein
** Last update Sun Dec 30 17:17:46 2001 romain bottier
*/

#include <stdlib.h>
#include "data_struct.h"

t_list		*list_create(void *elem)
{
  t_list	*res;
  
  res = xmalloc(sizeof (t_list));
  res->elem = elem;
  res->next = 0;
  return (res);
}
