/*
** ls.c for sploum in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Nov 22 19:28:19 2001 jean-daniel michaud
** Last update Sun Nov 25 17:25:28 2001 jean-daniel michaud
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "struct.h"
#include "ls.h"
#include "my_xmalloc.h"
#include "ex_error.h"
#include "utils.h"

extern t_win	*gl_win;

t_dir	*ls(char *path)
{
  t_dir	*d;

  move(getmaxy(stdscr) - 1, 1);
  printw("exploring directory, please wait ...");
  refresh();
  d = my_xmalloc(sizeof (t_dir));
  if ((d->dir = opendir(path)) == NULL)
    {
      opendir_error(stdscr);
      free(d);
      return (NULL);
    }
  chdir(path);
  d->name = path;
  d->next = NULL;
  d->files = NULL;
  d->total = ls_on_dir(&d);
  d->actual = 1;
  d->max_name_len = getmax(d->files);
  move(getmaxy(stdscr) - 1, 1);
  wclear(gl_win->w);
  return (d);
}

int		ls_on_dir(t_dir **d)
{
  struct stat   *sb;
  struct dirent *entry;
  t_file	*file;
  char		tmp[255];
  int		nbr;
  
  nbr = 0;
  if (d)
    {
      entry = readdir((*d)->dir);
      for (; entry; nbr++, entry = readdir((*d)->dir))
	{
	  sb = my_xmalloc(sizeof (struct stat));
	  strcpy(tmp, "./");
	  strcpy(&tmp[2], entry->d_name);
	  lstat(tmp, sb);
	  file = my_xmalloc(sizeof (t_file));
	  file->name = strdup(entry->d_name);
	  file->size = strlen(file->name);
	  file->sb = sb;
	  file->next = NULL;
	  put_in_sort_list(&((*d)->files), file);
	}
    }
  return (nbr);
}

void	put_in_sort_list(t_file **list, t_file *elem)
{
  t_file   *tmp;
  
  if (!*list)
    {
      elem->next = NULL;
      *list = elem;
    }
  else
    {
      if (!(*list)->next)
        if (strcmp((*list)->name, elem->name) < 0)
          (*list)->next = elem;
        else
          {
            elem->next = *list;
            *list = elem;
          }
      else
        {
          for (tmp = *list; tmp && tmp->next 
                 && strcmp(tmp->next->name, elem->name) < 0;)
            tmp = tmp->next;
          elem->next = tmp->next;
          tmp->next = elem;
        }
    }
}

void		freelist(t_file *file)
{
  t_file	*f;
  
  while (file)
    {
      f = file;
      file = file->next;
      if (f->name)
	free(f->name);
      if (f->sb)
	free(f->sb);
      free(f);
    }
}
