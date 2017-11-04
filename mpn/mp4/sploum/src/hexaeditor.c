/*
** hexaeditor.c for sploum in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sun Nov 25 10:14:53 2001 jean-daniel michaud
** Last update Tue Nov 27 21:57:25 2001 jean-daniel michaud
*/

#include <curses.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <signal.h>
#include <stdlib.h>
#include <ctype.h>

#include "struct.h"
#include "retrace.h"
#include "utils.h"
#include "my_xmalloc.h"
#include "explorer.h"
#include "ed_error.h"
#include "ed_events.h"
#include "ed_events2.h"
#include "hexaeditor.h"
#include "ed_show.h"

extern t_win		*gl_win;

int		load(char *filename)
{
  FILE		*file;
  struct stat   sb;
  char		tmp[257];
  void		*buf;
  int		i;
  int		size;

  if ((file = fopen(filename, "r")) == NULL)
    return (openfile_error(stdscr));
  move(getmaxy(stdscr) - 1, 1);
  printw("opening file, please wait ...");
  refresh();
  free_buffer();
  gl_win->filename = filename;
  strcpy(tmp, "./");
  strcpy(&tmp[2], filename);
  lstat(tmp, &sb);
  gl_win->code = my_xmalloc((sb.st_size / 16 + 1) * sizeof (char *));
  buf = my_xmalloc(16 * sizeof (char));
  for (i = 0; !feof(file); size = fread(buf, 1, 16, file),
       buf = my_xmalloc(16 * sizeof (char)), gl_win->code[++i] = NULL)
    gl_win->code[i] = buf;
  gl_win->code[i - 1][size] = EOF;
  return (i);
}

int			hexaeditor(char *filename)
{
  struct sigaction	s;
  
  curs_set(1);
  gl_win->filename = filename;
  gl_win->info->posx = 11;
  gl_win->info->posy = 1;
  gl_win->info->mode = 0;
  gl_win->info->fline = 0;  
  sigemptyset(&(s.sa_mask));
  sigaddset(&(s.sa_mask), SIGWINCH);
  s.sa_flags = SA_RESTART;
  s.sa_handler = retrace_hexaeditor;
  sigaction(SIGWINCH, &s, NULL);
  keypad(gl_win->w, TRUE);
  retrace_hexaeditor(0);
  if (filename || (filename = openfilebox()))
    if ((gl_win->info->total = load(filename)))
      retrace_hexaeditor(0);
  edit();
  return (0);
}

void	edit(void)
{
  int	i;

  while ((i = getch()) != 'q')
    {
      if ((i == 'o') && ((gl_win->info->total = load(openfilebox()))))
	retrace_hexaeditor(0);
      if (i == 'h')
	help(0);
      if (i == 'e')
	explorer(".");
      if (i == KEY_DOWN)
	key__down();
      if (i == KEY_UP)
	key__up();
      if (i == KEY_RIGHT)
	key__right();
      if (i == KEY_LEFT)
	key__left();
      if (i == 'x')
	key__x();
      if (i == KEY_NPAGE)
	key__npage();
      if (i == KEY_PPAGE)
	key__ppage();
    }
}

void	free_buffer(void)
{
  int	i;

  if ((gl_win) && (gl_win->code))
    {
      for (i = 0; gl_win->code[i]; ++i)
	free(gl_win->code[i]);
      if (gl_win->filename)
	free(gl_win->filename);
    }
}
