/*
** df_get_elt.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Wed Dec 19 12:15:24 2001 julien gein
** Last update Wed Dec 19 12:15:42 2001 julien gein
*/

#include "data_struct.h"

void	*df_get_elt(t_dicl *dico, char *token)
{
  if (!dico)
    return (0);
  if (dico->c == *token)
    {
      if (*(token + 1))	
	return (df_get_elt(dico->child, ++token));
      return (dico->elt);
    }
  else
    return (df_get_elt(dico->bros, token));
}
