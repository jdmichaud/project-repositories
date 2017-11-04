/*
** explorer.c for sploum in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Nov 22 18:40:22 2001 jean-daniel michaud
** Last update Tue Nov 27 18:36:37 2001 jean-daniel michaud
*/

#include <curses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

#include "def.h"
#include "struct.h"
#include "explorer.h"
#include "ex_events.h"
#include "ls.h"
#include "retrace.h"
#include "my_xmalloc.h"
#include "utils.h"
#include "format.h"
#include "hexaeditor.h"
#include "sploum.h"

extern t_win	*gl_win;

void		show(void)
{
  int		line;
  t_file	*f;
  int		tmp;

  if (gl_win->content)
    {
      f = gl_win->content->files;
      for (build_exwin(), tmp = 1; f && tmp < gl_win->content->actual; ++tmp)
	f = f->next;
      for (line = 1; f && (line + 1 < getmaxy(gl_win->w)); 
	   ++line, f = f->next)
	{
	  if (line == gl_win->tag)
	    wattron(gl_win->w, COLOR_PAIR(BONY));
	  print_file(f, line);
	  if (line == gl_win->tag)
	    wattron(gl_win->w, COLOR_PAIR(YONB));
	}
    }
  box(gl_win->w, ACS_VLINE, ACS_HLINE);
  build_exwin();
}

char		*openfilebox(void)
{
  char		*filename;
  
  filename = my_xmalloc(255 * sizeof (char));
  move(getmaxy(stdscr) - 1, 1);
  printw("Open file: ");
  my_getstr(filename);
  clear();
  refresh();
  return (filename);
}

int			explorer(char *path)
{
  struct sigaction	s;
  
  chdir(path);
  sigemptyset(&(s.sa_mask));
  sigaddset(&(s.sa_mask), SIGWINCH);
  s.sa_flags = SA_RESTART;
  s.sa_handler = retrace_explorer;
  sigaction(SIGWINCH, &s, NULL);
  retrace_explorer(0);
  keypad(gl_win->w, TRUE);
  retrace_explorer(0);
  if ((gl_win->content = ls(path)) == NULL)
    explore();
  gl_win->content->actual = 1;
  retrace_explorer(0);
  explore();
  return (0);
}

void	buildlist(int whence)
{
  t_dir	*d;

  if (whence)
    {
      if ((d = ls(openfilebox())) != NULL)
	{
	  freeall();
	  gl_win->content = d;
	  retrace_explorer(0);
	}
    }
  else
    if ((d = ls(".")) != NULL)
      {
	freeall();
	gl_win->content = d;
	retrace_explorer(0);
      }
}

void	explore(void)
{
  int	i;

  while ((i = getch()) != 'q')
    {
      if (i == 'o')
	buildlist(1);
      if (i == 'r')
	buildlist(0);
      if (i == 'h')
	help(1);
      if (i == KEY_UP)
	key_up();
      if (i == KEY_DOWN)
	key_down();
      if (i == KEY_RETURN)
	key_return();
      if (i == KEY_PPAGE)
	key_ppage();
      if (i == KEY_NPAGE)
	key_npage();
      if (i == 'e')
	hexaeditor(openfilebox());
    }
}
