/*
** ex_events.c for sploum in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sun Nov 25 09:56:29 2001 jean-daniel michaud
** Last update Tue Nov 27 22:31:51 2001 jean-daniel michaud
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

extern t_win	*gl_win;

void	key_up(void)
{
  if (gl_win->tag > 1)
    gl_win->tag--;
  else
    if (gl_win->content->actual > 1)
      gl_win->content->actual--;
    else
      beep();
  show();
  wrefresh(gl_win->w);
}

void	key_down(void)
{
  if (gl_win->tag < getmaxy(gl_win->w) - 2)
    gl_win->tag++;
  else
    if (gl_win->content->actual + gl_win->tag < gl_win->content->total)
      gl_win->content->actual++;
    else
      beep();
  show();
  wrefresh(gl_win->w);
}

void	key_ppage(void)
{
  if (gl_win->tag <= 1)
    {
      if (gl_win->content->actual >= 2 * getmaxy(gl_win->w) - 2)
	gl_win->content->actual -= getmaxy(gl_win->w) - 2;
      else
	gl_win->content->actual = 0;
    }
  else
    gl_win->tag = 1;
  show();
  wrefresh(gl_win->w);
}

void	key_npage(void)
{
  int	tmp;

  tmp = getmaxy(gl_win->w) - 2;
  if (gl_win->tag >= tmp)
    if (gl_win->content->total >= gl_win->content->actual + 2 * tmp)
      gl_win->content->actual += tmp;
    else
      gl_win->content->actual = gl_win->content->total - (tmp - 1);
  else
    gl_win->tag = tmp > gl_win->content->total ? gl_win->content->total : tmp;
  show();
  wrefresh(gl_win->w);
}

void		key_return(void)
{
  int		i;
  t_file	*f;
  t_dir		*d;

  for (f = gl_win->content->files, i = 0; f && 
	 (i < gl_win->tag + gl_win->content->actual - 2); 
       ++i, f = f->next)
    ;
  if (is_file(f->name))
    {
      hexaeditor(f->name);
      retrace_explorer(0);
    }
  else
    if (f && ((d = ls(f->name)) != NULL))
      {
	free(gl_win->content);
	gl_win->content = d;
	retrace_explorer(0);
      }
}

