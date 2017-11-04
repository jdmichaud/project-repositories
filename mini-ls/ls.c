/*
** ls.c for mini-ls in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Oct 31 11:26:58 2001 jean-daniel michaud
** Last update Tue Nov 20 02:08:09 2001 jean-daniel michaud
*/

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <time.h>
#include <sys/stat.h>
#include <stdlib.h>

#include "list_file.h"
#include "list_args.h"
#include "ls.h"
#include "get_option.h"
#include "my_strdup.h"
#include "my_strcmp.h"
#include "my_printf.h"
#include "get_type.h"
#include "sort.h"
#include "show.h"
#include "utils.h"

void		ls(t_list_args *list, int option)
{
  t_list_args	*tmp;
  int		flag;

  tmp = list;
  flag = is_multiple_dir(list);
  while (tmp)
    {
      ls_on_dir(tmp);
      if (is_file(tmp->name))
	show(tmp->link, option);
      tmp = tmp->next;
    }
  while (list)
    {
      if (!is_file(list->name))
	{
	  my_printf("\n");
	  if (flag && my_strcmp(list->name, "."))
	    my_printf("%s:\n", list->name);
	  show(list->link, option);
	}
      list = list->next;
    }
}

void		recur_ls(t_list_args **list, int option)
{
  t_list_args	*args;
  t_list_file	*tmp;
  DIR		*dir;
  char		*name;
  
  args = *list;
  while (args)
    {
      ls_on_dir(args);
      if (!(args->is_file))
	for (tmp = args->link; tmp; tmp = tmp->next)
	  {
	    name = make_filename(args->name, tmp->name);
	    if (is_directory(name) && (my_strcmp(tmp->name, ".")) 
		&& (my_strcmp(tmp->name, ".."))  
		&& !((dir = open_dir(name)) == NULL))
	      add_dir_end(list, dir, name);
	  }
      args = args->next;
    }
  ls(*list, option);
}


t_list_args	*make_list_from_args(char **argv)
{
  DIR		*dir;
  t_list_args	*list;
  int		i;
  int		flag;
  
  list = NULL;
  for (i = 1, flag = 0; argv[i]; ++i)
    {
      if (argv[i][0] != '-')
	{
	  flag = 1;
	  if ((is_file(argv[i])) && !is_directory(argv[i]))
	    add_file(&list, make_filename(argv[i], "/"));
	  else
	    if ((dir = open_dir(argv[i])) != NULL)
	      add_dir(&list, dir, make_filename(argv[i], "/"));
	}
    }
  if (!flag)
    if (!((dir = open_dir(NULL)) == NULL))
      add_dir(&list, dir, "./");
  return (list);
}

unsigned int	count(t_list_file *list, int type)
{
  unsigned int	i;

  while (list)
    {
      list = list->next;
      ++i;
    }
  return (i);
}

int		is_multiple_dir(t_list_args *list)
{
  int		i;

  i = 0;
  while (list && (i < 2))
    {
      if (is_directory(list->name))
	++i;
      list = list->next;
    }
  return (i > 1);
}
