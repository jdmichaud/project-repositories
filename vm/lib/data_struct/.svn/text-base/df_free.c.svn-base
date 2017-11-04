/*
** df_free.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Fri Dec 14 15:09:28 2001 julien gein
** Last update Wed Dec 19 12:21:39 2001 julien gein
*/

#include <stdlib.h>
#include "data_struct.h"

void	df_free(t_dicl **dico, t_df_free fct)
{
  if (*dico)
    {
      df_free(&(*dico)->bros, fct);
      df_free(&(*dico)->child, fct);
      if ((*dico)->elt && fct)
	fct((*dico)->elt);
      free(*dico);
      *dico = 0;
    }
}
