/*
** output.c for beswitch in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Nov  7 15:34:14 2001 jean-daniel michaud
** Last update Mon Nov 12 11:56:03 2001 jean-daniel michaud
*/

#include <stdlib.h>

#include "list.h"
#include "tree.h"
#include "output.h"
#include "my_printf.h"
#include "utils.h"

void	make_indent(int	nb)
{
  for (; nb >= 0; --nb)
    my_printf("  ");
}

void	make_list_of_token(t_dico *tree, t_list **list)
{
  char	*tmp;
  int	i;

  if (tree)
    {
      push(list, tree->c);
      if (!tree->son)
	{
	  make_indent(3);
	  tmp = collapse(*list);
	  my_printf("\"");
	  for (i = 0; tmp[i]; ++i)
	    {
	      if (is_spec(tmp[i]))
		my_printf("%c", tmp[i]);
	    }
	  my_printf("\"");
	  my_printf(",\n");
	  free(tmp);
	}
      make_list_of_token(tree->son, list);
      pop(list); 
      if (tree->bros)
	make_list_of_token(tree->bros, list);
    }
}


int	make_code_from_bros(t_dico *tree, int i, int index)
{
  if (tree)
    {
      my_printf("case('%c'): {\n", tree->c);
      if (tree->c == '\0')
	my_printf("return (wordlist[%d]);\n", i, index++);
      else
	index = make_code_from_son(tree->son, i + 1, index);
      my_printf("}\n");
      index = make_code_from_bros(tree->bros, i, index);  
    }
  return (index);
}

int	make_code_from_son(t_dico *tree, int i, int index)
{
  if (tree)
    {
      my_printf("switch(str[%d])  {\n", i);
      my_printf("case('");
      if (!is_spec(tree->c))
	my_printf("'): {\n");
      else
	my_printf("%c'): {\n", tree->c);
      if (tree->c == '\0')
	my_printf("return (wordlist[%d]);\n", index++);
      else
	index = make_code_from_son(tree->son, i + 1, index);
      my_printf("}\n");
      index = make_code_from_bros(tree->bros, i, index);
      my_printf("default: return(NULL);\n");
      my_printf("}\n");
    }
  return (index);
}

int		make_code(t_dico *tree)
{
  t_list	*list;

  list = NULL;
  my_printf(INCLUDE);
  my_printf("\n");
  my_printf(FNC_PRT);
  my_printf("{\n");
  make_indent(1);
  my_printf("%s\n", STC_TAB);
  make_indent(2);
  my_printf("{\n");
  make_list_of_token(tree, &list);
  make_indent(2);
  my_printf("};\n\n", STC_TAB);
  make_code_from_son(tree, 0, 0);
  my_printf("}\n");
  return (0);
}
