/*
** options.c for vm in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Jan  2 16:37:26 2002 jean-daniel michaud
** Last update Thu Jan 10 21:33:26 2002 jean-daniel michaud
*/

#include <stdio.h>

#include "my_struct.h"
#include "options.h"
#include "my_printf.h"
#include "debug.h"
#include "my.h"

static const char	*opts[] =
{
  "help",
  "ms",
  "mp",
  "im",
  "cy",
  "nl",
  "cd",
  "t",
  "interface",
  "g",
  "v",
  "delay"
};

int	get_option(char *argv[], int indice)
{
  int	i;

  for (i = 1; argv[i]; ++i)
    if ((*argv[i] == '-') && argv[i][1] 
	&& (!my_strcmp(&argv[i][1], opts[indice])))
      {
	if (argv[i + 1] && my_isnum(argv[i + 1]))
	  return (my_atoi(argv[i + 1]));
	else
	  usage();
      }
  return (0);
}

char	*get_char_option(char *argv[], int indice)
{
  int	i;

  for (i = 1; argv[i]; ++i)
    if ((*argv[i] == '-') && argv[i][1] && 
	(!my_strcmp(&argv[i][1], opts[indice])))
      {
	if (argv[i + 1][0] != '-')
	  return (argv[i + 1]);
	else
	  usage();
      }
  return (0);
}


int	option_here(char *argv[], int indice)
{
  int	i;

  for (i = 1; argv[i]; ++i)
    if ((*argv[i] == '-') && argv[i][1] && 
	(!my_strcmp(&argv[i][1], opts[indice])))
      return (1);
  return (0);
}

int	noill_options(char *argv[])
{
  int	i;
  int	j;

  for (i = 1; argv[i]; ++i)
    if (argv[i][0] == '-')
      {
	for (j = 0; (j <= MAX_OPTS - 1) && argv[i][1] &&
	       (my_strcmp(&argv[i][1], opts[j])); ++j)
	  ;
	if (j > MAX_OPTS - 1)
	  return (1);
      }
  return (0);
}

t_list		*get_filename(char **argv)
{
  t_list	*list;
  int		i;
  int		j;
  
  list = NULL;
  for (i = 1, j = 1; argv[i]; ++i)
    if (!my_isnum(argv[i]) && argv[i][1] && 
	(argv[i][0] != '-') && j <= 15 && my_strcmp(argv[i - 1], "-follow"))
      {
	++j;
	list_append(&list, argv[i]);
      }
  return (list);
}
