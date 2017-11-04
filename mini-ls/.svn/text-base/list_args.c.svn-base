/*
** list_args.c for mini-ls in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Nov 14 15:23:52 2001 jean-daniel michaud
** Last update Tue Nov 20 01:48:29 2001 jean-daniel michaud
*/

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>
#include <stdio.h>

#include "get_option.h"
#include "list_file.h"
#include "list_args.h"
#include "utils.h"
#include "my_strcmp.h"
#include "my_strdup.h"
#include "sort.h"

void		add_file(t_list_args **list, char *name)
{
  t_list_args	*tmp;
  
  if (!*list)
    {
      *list = malloc(sizeof (t_list_args));
      (*list)->next = NULL;
    }
  else
    {
      tmp = malloc(sizeof (t_list_args));
      tmp->next = *list;
      *list = tmp;
    }
  (*list)->name = my_strdup(name);
  purge((*list)->name);
  (*list)->link = NULL;
  (*list)->is_file = 1;
}

void		add_dir(t_list_args **list, DIR *dir, char *name)
{
  t_list_args	*tmp;
  char		*tmp_name;

  if (!*list)
    {
      *list = malloc(sizeof (t_list_args));
      (*list)->next = NULL;
    }
  else
    {
      tmp = malloc(sizeof (t_list_args));
      tmp->next = *list;
      *list = tmp;
    }
  (*list)->dir = dir;
  tmp_name = make_filename(name, "/");
  purge(tmp_name);
  (*list)->name = tmp_name;
  (*list)->link = NULL;
  (*list)->is_file = 0;
}

void		add_dir_end(t_list_args **list, DIR *dir, char *name)
{
  t_list_args	*tmp;
  char		*tmp_name;
  
  if (!*list)
    {
      *list = malloc(sizeof (t_list_args));
      (*list)->next = NULL;
      tmp = *list;
    }
  else
    {
      for (tmp = *list; tmp->next; tmp = tmp->next)
	;
      tmp->next = malloc(sizeof (t_list_args));
      tmp->next->next = NULL;
    }      
  tmp->next->dir = dir;
  tmp_name = make_filename(name, "/");
  purge(tmp_name);
  tmp->next->name = tmp_name;
  tmp->next->link = NULL;
  tmp->next->is_file = 0;
}

void		free_list_args(t_list_args **list)
{
  t_list_args	*tmp;

  tmp = *list;
  while (tmp)
    {
      *list = (*list)->next;
      free(tmp);
      tmp = *list;
    }
}

void		ls_on_dir(t_list_args *list)
{
  struct stat	*sb;
  struct dirent	*entry;
  
  if (list->is_file)
    {
      sb = malloc(sizeof (struct stat));
      lstat(make_filename("./", list->name), sb);
      add(&list->link, sb, list->name, NULL);
    }
  else
    {
      entry = readdir(list->dir);
      while (entry)
	{
	  sb = malloc(sizeof (struct stat));
 	  lstat(make_filename(list->name, entry->d_name), sb);
	  add(&list->link, sb, entry->d_name, list->name);
	  entry = readdir(list->dir);
	}
    }
}
