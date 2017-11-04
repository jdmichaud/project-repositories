/*
** dc_genlist_pref.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Fri Dec 14 11:53:35 2001 julien gein
** Last update Sun Dec 30 14:05:03 2001 julien gein
*/

#include "data_struct.h"

static void	df_mklist(t_dicl *dico, t_list **list, t_listfunc fct)
{
  if (dico)
    {
      if (dico->elt)
	list_put(list, fct(dico->elt));
      df_mklist(dico->bros, list, fct);
      df_mklist(dico->child, list, fct);
    }
}

t_dicl	*dc_getpos(t_dicl *dico, char *pref)
{
  if (dico)
    {
      if (dico->c == *pref)
	return (!*(pref + 1) ? dico : dc_getpos(dico->child, pref + 1));
      else
	if (dico->c < *pref)
	  return (dc_getpos(dico->bros, pref));
    }
  return (0);
}

t_list		*df_genlist_pref(t_dicl *dico, char *pref, t_listfunc fct)
{
  t_list	*res;
  t_dicl	*pos;
  
  res = 0;
  if (!pref || !*pref)
    {
      if (dico)
	df_mklist(dico, &res, fct);
    }
  else
    {
      if ((pos = dc_getpos(dico, pref)))
	{
	  if (pos->elt)
	    list_put(&res, fct(pos->elt));
	  df_mklist(pos->child, &res, fct);
	}
    }
  return (res);
}
