/*
** df_remove_elt.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Wed Dec 19 12:15:56 2001 julien gein
** Last update Wed Dec 19 12:16:08 2001 julien gein
*/

#include "data_struct.h"

t_dicl	*df_remove_elt(t_dicl *dico, char *str)
{
  if (dico->c == *str)
    {
      if (!*(str + 1))
	{
	  dico->elt = 0;
	  return (dico);
	}
      dico->child = df_remove_elt(dico->child, str + 1);
    }
  else
    dico->bros = df_remove_elt(dico->bros, str);
  return (dico);
}
