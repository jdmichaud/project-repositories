/*
** retrace.c for sploum in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Fri Nov 23 11:11:09 2001 jean-daniel michaud
** Last update Tue Nov 27 22:10:33 2001 jean-daniel michaud
*/

#include <curses.h>
#include <dirent.h>
#include <unistd.h>

#include "def.h"
#include "retrace.h"
#include "sploum.h"
#include "struct.h"
#include "my_xmalloc.h"
#include "explorer.h"
#include "ex_error.h"
#include "hexaeditor.h"
#include "ed_show.h"

extern	t_win	*gl_win;

void		retrace_invite(int sig)
{
  endwin();
  init_all();
  curs_set(0);
  gl_win->w = newwin(5, 30, getmaxy(stdscr) / 2 - 2, getmaxx(stdscr) / 2 - 15);
  wbkgd(gl_win->w, COLOR_PAIR(YONB));
  if (winsize(4, 30))
    return;
  wmove(gl_win->w, 1, 0);
  wprintw(gl_win->w, " e - Explorateur\n");
  wprintw(gl_win->w, " h - Editeur Hexadecimal\n");
  wprintw(gl_win->w, " q - Quitter");
  box(gl_win->w, ACS_VLINE, ACS_HLINE);
  wmove(gl_win->w, 0, (getmaxx(gl_win->w) - 4) / 2);
  wprintw(gl_win->w, "Menu");
  wrefresh(gl_win->w);
}

void		retrace_explorer(int sig)
{
  endwin();
  init_all();
  curs_set(0);
  gl_win->w = newwin(getmaxy(stdscr) - 2, getmaxx(stdscr) - 2, 1, 1);
  wbkgd(gl_win->w, COLOR_PAIR(YONB));
  if (winsize(2, 30))
    return;
  if (gl_win->content)
    gl_win->content->actual = 1;
  gl_win->tag = 0;
  show();
  wrefresh(gl_win->w);
}

void		build_exwin(void)
{
  wmove(gl_win->w, 0, (getmaxx(stdscr) / 2 - 9));
  wprintw(gl_win->w, "Explorateur");
  wmove(gl_win->w, getmaxy(gl_win->w) - 1, 1);
  if (gl_win->content && gl_win->content->name)
    wprintw(gl_win->w, "[ %s ]", getcwd(NULL, 0));
}

void	retrace_hexaeditor(int sig)
{
  endwin();
  init_all();
  gl_win->w = newwin(getmaxy(stdscr) - 2, getmaxx(stdscr) - 2, 1, 1);
  wbkgd(gl_win->w, COLOR_PAIR(YONB));
  if (winsize(2, 30))
    return;
  gl_win->tag = 0;
  if (gl_win->info->mode)
    show_file();
  else
    show_file_in_hexa();
  box(gl_win->w, ACS_VLINE, ACS_HLINE);
  build_edwin();
  wmove(gl_win->w, gl_win->info->posy, gl_win->info->posx);
  wrefresh(gl_win->w);
}

void		build_edwin(void)
{
  int		pc;

  if (gl_win->info->mode)
    {
      wmove(gl_win->w, 0, (getmaxx(stdscr) / 2 - 4));
      wprintw(gl_win->w, "Editeur");
    }
  else
    {
      wmove(gl_win->w, 0, (getmaxx(stdscr) / 2 - 11));
      wprintw(gl_win->w, "Editeur Hexadecimal");
    }
  wmove(gl_win->w, getmaxy(gl_win->w) - 1, 1);
  if (gl_win->filename)
    wprintw(gl_win->w, "[ %s ]", gl_win->filename);
  wmove(gl_win->w, getmaxy(gl_win->w) - 1, getmaxx(gl_win->w) - 14);
  if (gl_win->info && gl_win->info->total)
    {
      pc = ((gl_win->info->fline + gl_win->info->posy) * 100) 
	/ gl_win->info->total;
      wprintw(gl_win->w, "[ %3i%% ]", pc);
    }
}
