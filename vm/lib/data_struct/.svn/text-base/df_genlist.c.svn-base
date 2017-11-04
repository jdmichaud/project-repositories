/*
** df_genlist.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Wed Dec 19 12:20:45 2001 julien gein
** Last update Wed Dec 19 12:20:53 2001 julien gein
*/

#include "data_struct.h"

void	df_mklist(t_dicl *dico, t_list **list)
{
  if (dico)
    {
      if (dico->elt)
	list_put(list, dico->elt);
      df_mklist(dico->bros, list);
      df_mklist(dico->child, list);
    }
}

t_list		*df_genlist(t_dicl *dico)
{
  t_list	*res;
  
  res = 0;
  df_mklist(dico, &res);
  return (res);
}
