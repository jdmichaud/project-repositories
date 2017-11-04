/*
** df_list_elt.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Wed Dec 19 12:16:25 2001 julien gein
** Last update Wed Dec 19 12:16:34 2001 julien gein
*/

#include "data_struct.h"

void	df_list_elt(t_dicl *dico, t_printfunc f)
{
  if (dico)
    {
      df_list_elt(dico->bros, f);
      if (dico->elt)
	f(dico->elt);
      df_list_elt(dico->child, f);
    }
}
