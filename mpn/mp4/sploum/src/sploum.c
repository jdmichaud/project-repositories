/*
** main.c for sploum in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Nov 22 17:33:37 2001 jean-daniel michaud
** Last update Tue Nov 27 22:15:26 2001 jean-daniel michaud
*/

#include <curses.h>
#include <dirent.h>
#include <signal.h>
#include <stdlib.h>

#include "def.h"
#include "struct.h"
#include "colors.h"
#include "explorer.h"
#include "retrace.h"
#include "my_xmalloc.h"
#include "sploum.h"
#include "ls.h"
#include "hexaeditor.h"
#include "help.h"

t_win		*gl_win;

void		init_all(void)
{
  initscr();
  keypad(stdscr, TRUE);
  cbreak();
  noecho();
}

int			invite(void)
{
  int			k;
  struct sigaction	s;

  sigemptyset(&(s.sa_mask));
  sigaddset(&(s.sa_mask), SIGINT);
  s.sa_flags = SA_RESTART;
  s.sa_handler = quit;
  sigaction(SIGINT, &s, NULL);
  sigemptyset(&(s.sa_mask));
  sigaddset(&(s.sa_mask), SIGWINCH);
  s.sa_flags = SA_RESTART;
  s.sa_handler = retrace_invite;
  sigaction(SIGWINCH, &s, NULL);
  retrace_invite(0);
  k = 0;
  while ((k != 'e') && (k != 'h') && (k != 'q'))
    k = wgetch(gl_win->w);
  delwin(gl_win->w);
  refresh();
  return (k);
}

void		quit(int sig)
{
  freeall();
  endwin();
  printf("---** sploum termine **---\n");
  exit(0);
}

void		freeall(void)
{
  int		i;

  move(getmaxy(stdscr) - 1, 1);
  printw("Veuillez patientez ...");
  refresh();
  if (!gl_win)
    return;
  if (gl_win->code)
    for (i = 0; gl_win->code[i]; ++i)
      free(gl_win->code[i]);
  if (gl_win->content && gl_win->content->name)
    free(gl_win->content->name);
  if (gl_win->content && gl_win->content->files)
    freelist(gl_win->content->files);
}

int			main(int argc, char *argv[])
{
  int			choice;

  gl_win = my_xmalloc(sizeof (t_win));
  gl_win->w = NULL;
  gl_win->content = NULL;
  gl_win->code = NULL;
  gl_win->tag = 0;
  gl_win->info = my_xmalloc(sizeof (t_curinfo));
  init_all();
  enable_color();
  if (argv[1] && (!strcmp(argv[1], "--help") || !strcmp(argv[1], "-h")))
    helpme();
  if ((choice = invite()) == 'e')
    explorer(DEFAULT_DIR);
  else
    if (choice == 'h')
      hexaeditor(NULL);
  freeall();
  endwin();
  return (0);
}
