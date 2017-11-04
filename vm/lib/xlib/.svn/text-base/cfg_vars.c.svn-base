/*
** cfg_vars.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Tue Jan  8 13:53:55 2002 julien gein
** Last update Tue Jan  8 17:14:19 2002 jean-daniel michaud
*/

#include "display.h"
#include "my.h"

#include "my_printf.h"

int	cmp(void *e1, void *e2)
{
  return (my_strcmp(e1, e2));
}


unsigned int	truc_is_def(char *var, char *val)
{
  t_dicl	*dico;
  t_list	*list;
  
  dico = update_dcdpy(0, 0, DV_GET);
  list = df_get_elt(dico, var);
    return (list_find_node(list, val, cmp) ? 1 : 0);
  return (1);
}


