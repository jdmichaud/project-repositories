/*
** ed_events.c for sploum in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sun Nov 25 10:15:50 2001 jean-daniel michaud
** Last update Tue Nov 27 19:31:56 2001 jean-daniel michaud
*/

#include <curses.h>
#include <dirent.h>
#include <stdlib.h>

#include "struct.h"
#include "ex_events.h"
#include "explorer.h"
#include "ls.h"
#include "retrace.h"
#include "utils.h"
#include "hexaeditor.h"
#include "get_type.h"
#include "ed_events.h"
#include "ed_show.h"

extern t_win	*gl_win;

void		key__ppage(void)
{
  if (gl_win->info->posy > 1)
    gl_win->info->posy = 1;
  else
    {
      if (gl_win->info->fline > getmaxy(gl_win->w) - 2)
	gl_win->info->fline -= getmaxy(gl_win->w) - 2;
      else
	gl_win->info->fline = 0;
      if (gl_win->info->mode)
	show_file();
      else
	show_file_in_hexa();
    }
  wmove(gl_win->w, gl_win->info->posy, gl_win->info->posx);
  wrefresh(gl_win->w);
}

void	key__npage(void)
{
  if (gl_win->info->posy < (getmaxy(gl_win->w) - 2))
    gl_win->info->posy = getmaxy(gl_win->w) - 2 > gl_win->info->total ?
      gl_win->info->total : getmaxy(gl_win->w) - 2;
  else
    {
      if (gl_win->info->fline < gl_win->info->total 
	  - ((getmaxy(gl_win->w) - 2) * 2))
	  gl_win->info->fline += getmaxy(gl_win->w) - 2;
      else
	gl_win->info->fline = gl_win->info->total - getmaxy(gl_win->w) + 2;
      if (gl_win->info->mode)
	show_file();
      else
	show_file_in_hexa();
    }
  wmove(gl_win->w, gl_win->info->posy, gl_win->info->posx);
  wrefresh(gl_win->w);
}
