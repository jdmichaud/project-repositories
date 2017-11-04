/*
** df_create_elt.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Wed Dec 19 12:17:11 2001 julien gein
** Last update Wed Dec 19 12:17:25 2001 julien gein
*/

#include "data_struct.h"

t_dicl		*df_create_elt(char c, t_dicl *bros, t_dicl *child)
{
  t_dicl	*new;
  
  new = xmalloc(sizeof (t_dicl));
  new->c = c;
  new->bros = bros;
  new->child = child;
  new->elt = 0;
  return (new);
}
