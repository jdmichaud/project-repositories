/*
** vchar_to_list.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Wed Dec 19 14:06:46 2001 julien gein
** Last update Sat Dec 29 17:59:53 2001 romain bottier
*/

#include "data_struct.h"

t_list		*vchar_to_list(char **tab, unsigned int length, t_createfct f)
{
  t_list	*res;
  unsigned int	i;
  
  for (res = 0, i = length; i > 0; i--)
    if (f)
      list_put(&res, f(tab[i - 1]));
    else
      list_put(&res, tab[i - 1]);
  return (res);
}
