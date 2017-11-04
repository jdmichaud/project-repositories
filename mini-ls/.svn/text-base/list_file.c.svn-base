/*
** list.c for mini-ls in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Oct 31 12:29:11 2001 jean-daniel michaud
** Last update Tue Nov 20 01:47:17 2001 jean-daniel michaud
*/

#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>

#include "list_file.h"
#include "list_args.h"
#include "my_strcmp.h"
#include "my_printf.h"
#include "utils.h"
#include "my_strdup.h"
#include "sort.h"

void		add(t_list_file	**list, 
		    struct stat	*sb, 
		    char	*name, 
		    char	*path)
{
  t_list_file	*tmp;
  struct passwd	*info_owner;
  struct group	*info_group;


  tmp = malloc(sizeof (t_list_file));
  tmp->next = NULL;
  tmp->name = my_strdup(name);
  tmp->path = my_strdup(path);
  purge(tmp->name);
  tmp->sb = sb;
  if ((info_owner = getpwuid(sb->st_uid)) == NULL)
    tmp->owner = NULL;
  else
    tmp->owner = info_owner->pw_name;
  if ((info_group = getgrgid(sb->st_gid)) == NULL)
    tmp->group = NULL;
  else
    tmp->group = info_group->gr_name;
  put_in_sort_list(list, tmp);
}

void	free_list(t_list_file **list)
{
  if (!*list)
    return;
  free_list(&((*list)->next));
  free(*list);
}

void		put_in_sort_list(t_list_file **list, t_list_file *elem)
{
  t_list_file	*tmp;
  
  if (!*list)
    *list = elem;
  else
    {
      if (!(*list)->next)
	if (my_strcmp((*list)->name, elem->name) < 0)
	  (*list)->next = elem;
	else
	  {
	    elem->next = *list;
	    *list = elem;
	  }
      else
	{
	  for (tmp = *list; tmp->next 
		 && my_strcmp(tmp->next->name, elem->name) < 0;)
	    tmp = tmp->next;
	  elem->next = tmp->next;
	  tmp->next = elem;
	}
    }
}

void		free_list_file(t_list_file **file)
{
  t_list_file	*prec;

  while (file && *file)
    {
      prec = *file;
      *file = (*file)->next;
      free(prec->sb);
      free(prec);
    } 
}
