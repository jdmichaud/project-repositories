/*
** utils.c for sploum in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Fri Nov 23 22:17:40 2001 jean-daniel michaud
** Last update Mon Nov 26 16:24:58 2001 jean-daniel michaud
*/

#include <curses.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>

#include "def.h"
#include "struct.h"
#include "utils.h"
#include "my_xmalloc.h"

extern t_win	*gl_win;

int	my_nbrlen(int nbr)
{
  int	len;
  
  if (nbr == 0)
    return (1);
  for (len = 0; nbr != 0; nbr /= 10, len++)
    ;
  return (len);
}

int	getmax(t_file	*file)
{
  int	max;

  max = 0;
  while (file)
    {
      if (max < file->size)
	{
	  max = file->size;
	  wprintw(gl_win->w, "%i", max);
	  wrefresh(gl_win->w);
	}
      file = file->next;
    }
  return (max);
}

char	*dec2hex(int nbr)
{
  char	*base;
  char	*temp;
  int	div;

  temp = my_xmalloc(2 * sizeof (char));
  base = strdup("0123456789abcdef");
  temp[0] = '0';
  temp[1] = '0';
  div = 1;
  while ((nbr / div) >= 16)
    div *= 16;
  temp[0] = base[nbr / div];
  temp[1] = (div / 16) ? base[(nbr % div) / (div / 16)] : '0';
  free(base);
  return (temp);
}

void	help(int whence)
{
  move(getmaxy(stdscr) - 1, 1);
  if (whence)
    {
      printw("o: open a directory, e: open the editor, q: quit, ");
      printw("return: explore a directory, h: this help");
    }
  else
    {
      printw("o: open a file, e: open the explorer, q: quit, ");
      printw("h: this help");
    }
  refresh();
}

void	my_getstr(char *str)
{
  int	i;
  int	pos;

  pos = i = 0;
  while ((i = getch()) != KEY_RETURN)
    {
      if ((i > 32) && (i < 127))
	{
	  printw("%c", i);
	  str[pos++] = i;
	}
      if (i == KEY_BACKSPACE)
	{
	  mvwprintw(stdscr, getcury(stdscr), getcurx(stdscr) - 1, " ");
	  move(getcury(stdscr), getcurx(stdscr) - 1);
	  pos--;
	}
    }
}
