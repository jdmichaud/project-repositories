/*
** ntree_free.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Wed Dec 19 13:58:35 2001 julien gein
** Last update Thu Dec 20 18:30:13 2001 julien gein
*/

#include <stdlib.h>
#include "data_struct.h"

void		ntree_free(t_ntree **tree)
{
  t_list	*childs;
  t_ntree	*child_node;
  
  if (*tree)
    {
      childs = (*tree)->childs;
      while (childs)
	{
	  child_node = childs->elem;
	  ntree_free(&child_node);
	}
      free(*tree);
      *tree = 0;
    }
}
