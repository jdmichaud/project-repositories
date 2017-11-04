/*
** beswitch.c for beswitch in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Nov  7 12:38:38 2001 jean-daniel michaud
** Last update Mon Nov 12 15:19:43 2001 jean-daniel michaud
*/

#include <stdio.h>
#include <stdlib.h>

#include "my_printf.h"
#include "my_print_error.h"
#include "tree.h"
#include "parser.h"
#include "output.h"
#include "beswitch.h"
#include "errors.h"

extern FILE	*yyin;
extern char	*gl_str;
extern t_func	tab[];

void		errors(unsigned int err, char *file)
{
  if (err == 43)
    {
      my_print_error("malloc: not enougth memory\n");
      exit(43);
    }
  tab[err].f(file);
}

int		start(t_dico **tree, char *filename)
{
  int		ret;

  while (!(ret = yylex()))
    if (!add_word(tree, gl_str))
      errors(1, filename);
    else
      {
	free(gl_str);
	gl_str = NULL;
      }
  if (ret > 0)
    errors(ret, filename);
  if (ret == -3)
    make_code(*tree);
  if ((ret = yylex()) > 0)
    errors(ret, filename);
  return (0);
}

int		main(int argc, char *argv[])
{
  t_dico	*tree;
 
  tree = NULL;
  if ((yyin = fopen(argv[1], "r")) == NULL)
    {
      if (argv[1] == NULL)
	my_print_error("warning: %s\n", W_STDIN);
      else	
	my_print_error("warning: %s introuvable, %s\n", argv[1], W_STDIN);
      yyin = stdin;
    }
  start(&tree, argv[1]);
  free_tree(tree);
  if (yyin != stdin)
    fclose(yyin);
  return (0);
}
