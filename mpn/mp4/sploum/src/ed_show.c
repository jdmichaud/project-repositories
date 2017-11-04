/*
** ed_show.c for sploum in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Mon Nov 26 14:09:47 2001 jean-daniel michaud
** Last update Tue Nov 27 22:12:38 2001 jean-daniel michaud
*/

#include <curses.h>
#include <stdio.h>
#include <dirent.h>
#include <ctype.h>
#include <stdlib.h>

#include "ed_show.h"
#include "struct.h"
#include "utils.h"
#include "retrace.h"

extern t_win	*gl_win;

void		show_file_in_hexa(void)
{
  int		i;
  int		j;
  
  i = gl_win->info->fline;
  for (; gl_win->code && gl_win->code[i] && (getmaxy(gl_win->w) - 2 - i 
					     + gl_win->info->fline); ++i)
    {
      wmove(gl_win->w, i + 1 - gl_win->info->fline, 1);
      wprintw(gl_win->w, "%08x  ", i * 16);
      for (j = 0; (j <= 15) && (gl_win->code[i][j] != 255); ++j)
	{
	  wprintw(gl_win->w, "%02x ", gl_win->code[i][j]);
	  if (j == 7)
	    wprintw(gl_win->w, " ");
	}
      mvwprintw(gl_win->w, i + 1 - gl_win->info->fline, 60, " |");
      for (j = 0; (j <= 15) && (gl_win->code[i][j] != 255); ++j)
	if (!isgraph(gl_win->code[i][j]) && (gl_win->code[i][j] != 32))
	  wprintw(gl_win->w, ".");
	else
	  wprintw(gl_win->w, "%c", gl_win->code[i][j]);
      wprintw(gl_win->w, "|");
    }
  build_edwin();
  wrefresh(gl_win->w);
}

void	show_file(void)
{
  int	i;
  int	j;
  int	line;

  wclear(gl_win->w);
  i = gl_win->info->fline;
  line = 1;
  wmove(gl_win->w, 1, 1);
  for (; gl_win->code && gl_win->code[i] && (getmaxy(gl_win->w) - line); ++i)
    for (j = 0; (j < 16) && (gl_win->code[i][j] != 255); ++j)
      {
	if (gl_win->code[i][j] == 10)
	  wmove(gl_win->w, ++line, 1);
	else
	  wprintw(gl_win->w, "%c", gl_win->code[i][j]);
      }
  box(gl_win->w, ACS_VLINE, ACS_HLINE);
  build_edwin();
  wrefresh(gl_win->w);
}






