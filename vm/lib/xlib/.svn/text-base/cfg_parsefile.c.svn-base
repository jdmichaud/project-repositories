/*
** cfg_parsefile.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Sat Jan  5 16:24:49 2002 julien gein
** Last update Fri Jan 11 11:35:44 2002 julien gein
*/

#include <stdlib.h>
#include "my_printf.h"
#include "my_print_error.h"
#include "display.h"

t_dicl		*update_dcdpy(char *str, void *elem, int mode)
{
  static t_dicl	*dico = 0;
  
  if (mode == DV_SET)
    dico = df_ins_elt(dico, str, elem);
  return (dico);
}

void		init_dcdpy(void)
{
  unsigned int	i;
  unsigned int	j;
  t_list	*ldefault;
  const t_var	vars[] =
  {
    {"Grid", {"False", 0, 0, 0}},
    {"FontName", {"8x13", 0, 0, 0}},
    {"Env", {"MemArea", "ListPlayers", "Register", 0}},
    {"MemoryBlockSizeX", {"3", 0, 0, 0}},
    {"MemoryBlockSizeY", {"3", 0, 0, 0}},
    {"FontSizeX", {"7", 0, 0, 0}},
    {"FontSizeY", {"10", 0, 0, 0}},
    {"Infos_Nb_Process", {"True", 0, 0, 0}},
    {0, {0, 0, 0, 0}}
  };
  
  for (i = 0; vars[i].name; i++)
    {
      for (j = 0, ldefault = 0; vars[i].value[j]; j++)
	list_put(&ldefault, vars[i].value[j]);
      update_dcdpy(vars[i].name, ldefault, DV_SET);
    }
}

void		set_func(char *str)
{
  t_list	*vars;
  t_list	*vals;
  t_list	*tmp;
  
  if ((vars = get_listargs(&str, ":=")))
    {
      if ((vals = get_listargs(&str, "<EOL>")))
	for (tmp = vars; tmp; tmp = tmp->next)
	  update_dcdpy(tmp->elem, vals, DV_SET);
      list_free(&vars);
    }
}

void		cfg_parseline(char *str)
{
  char		*tk;
  
  tk = gettk(&str);
  if (!strcmp(tk, "set"))
    set_func(str);
  else
    my_print_error("\tSyntax error: Unknown command \'%s\'\n", tk);
}

void		cfg_parsefile(void)
{
  t_list	*list;
  
  init_dcdpy();
  my_printf("Parsing CFG File \'%s\'\n", ".vmdpyrc");
  if ((list = init_file_buff(".vmdpyrc")))
    for (; list; list = list->next)
      {
	cfg_parseline(list->elem);
	free(list->elem);
      }
}
