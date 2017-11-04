/*
** format.c for sploum in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Nov 24 19:24:24 2001 jean-daniel michaud
** Last update Tue Nov 27 21:29:22 2001 jean-daniel michaud
*/

#include <curses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <stdlib.h>
#include <pwd.h>
#include <unistd.h>

#include "struct.h"
#include "format.h"
#include "utils.h"
#include "get_type.h"

extern t_win	*gl_win;

void		print_file(t_file *file, int line)
{
  int		nl;
  int		tmp;
  int		offs;

  nl = my_nbrlen(file->sb->st_size);
  wmove(gl_win->w, line, 1);
  wprintw(gl_win->w, "%s", file->name);
  offs = ((getmaxx(gl_win->w) - gl_win->content->max_name_len) > 10)
     ? 10 : getmaxx(gl_win->w) - gl_win->content->max_name_len - 2;
  for (tmp = 0; (gl_win->content->max_name_len + offs) - tmp - nl - file->size;
       tmp++)
    wprintw(gl_win->w, " ");
  show_info(file, offs);
  for (offs = getcurx(gl_win->w), tmp = getmaxx(gl_win->w) - 2; offs <= tmp;
       ++offs)
    wprintw(gl_win->w, " ");
}

void		show_info(t_file *file, int offs)
{
  int		tmp;
  char		*t;
  struct passwd *p;
  int		maxx;
  char          link[1024];

  maxx = getmaxx(gl_win->w);
  tmp = file->sb->st_size;
  wprintw(gl_win->w, "%i", tmp);
  t = ctime(&(file->sb->st_mtime));
  t[strlen(t) - 1] = '\0';
  if (t && (maxx > gl_win->content->max_name_len + offs + strlen(t) + 2))
    wprintw(gl_win->w, "  %s", t);
  if (maxx > gl_win->content->max_name_len + offs + strlen(t) + 15)
    print_right(file->sb->st_mode);
  p = getpwuid(file->sb->st_uid);
  if (p && (maxx > gl_win->content->max_name_len + 
	    offs + strlen(t) + 17 + strlen(p->pw_name)))
    wprintw(gl_win->w, "  %s", p->pw_name);
  if (is_link(file->name) && (maxx > gl_win->content->max_name_len + 
			      offs + strlen(t) + 17 + strlen(p->pw_name + 30)))
    {
      link[readlink(file->name, link, 1023)] = '\0';
      wprintw(gl_win->w, " -> %s", link);
    }
}

void		print_right(mode_t mode)
{
  char  *str;

  str = malloc(11 * sizeof (char));
  str[0] = ((mode & S_IFMT) == S_IFDIR) ? 'd' : '-';
  if ((mode & S_IFMT) == S_IFCHR)
    str[0] = 'c';
  if ((mode & S_IFMT) == S_IFLNK)
    str[0] = 'l';
  if ((mode & S_IFMT) == S_IFBLK)
    str[0] = 'b';
  str[1] = (mode & S_IRUSR) ? 'r' : '-';
  str[2] = (mode & S_IWUSR) ? 'w' : '-';
  str[3] = (mode & S_IXUSR) ? 'x' : '-';
  str[4] = (mode & S_IRGRP) ? 'r' : '-';
  str[5] = (mode & S_IWGRP) ? 'w' : '-';
  str[6] = (mode & S_IXGRP) ? 'x' : '-';
  str[7] = (mode & S_IROTH) ? 'r' : '-';
  str[8] = (mode & S_IWOTH) ? 'w' : '-';
  str[9] = (mode & S_IXOTH) ? 'x' : '-';
  str[10] = '\0';
  wprintw(gl_win->w, "  %s", str);
  free(str);
}
