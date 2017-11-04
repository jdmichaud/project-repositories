/*
** df_ins_elt.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Wed Dec 19 12:15:03 2001 julien gein
** Last update Wed Dec 19 12:15:16 2001 julien gein
*/

#include "data_struct.h"

t_dicl	*df_ins_elt(t_dicl *dico, char *token, void *elt)
{
  if (!*token)
    return (dico);  
  if (!dico)
    {
      dico = df_create_elt(*token, 0, 0);
      dico->elt = *(token + 1) ? 0 : elt;
      dico->child = df_ins_elt(dico->child, ++token, elt);
    }
  else
    {
      if (dico->c < *token)
	dico->bros = df_ins_elt(dico->bros, token, elt);
      else
	{
	  if (dico->c > *token)
	    dico = df_create_elt(*token, dico, 0);
	  dico->elt = *(token + 1) ? dico->elt : elt;
	  dico->child = df_ins_elt(dico->child, ++token, elt);
	}
    }
  return (dico);
}
