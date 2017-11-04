/*
** mini-ls.c for mini-ls in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Oct 18 12:32:18 2001 jean-daniel michaud
** Last update Tue Nov 20 00:24:01 2001 jean-daniel michaud
*/

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <time.h>
#include <stdio.h>
#include <sys/stat.h>

#include "list_file.h"
#include "list_args.h"
#include "mini-ls.h"
#include "get_option.h"
#include "ls.h"
#include "sort.h"
#include "error.h"

int		main(int argc, char **argv)
{
  int		option;
  t_list_args	*args;

  if (argc < 1)
    return (error(1));
  option = get_option(argv);
  if (argv[1])
    sort_tab(&argv[1]);
  args = make_list_from_args(argv);
  if (option & 8)
    recur_ls(&args, option);
  else
    ls(args, option);
  free_list_args(&args);
  return (0);
}

int	error(int i)
{
  if (i == 1)
    {
      Usage();
      exit(1);
    }
  return (0);
}
