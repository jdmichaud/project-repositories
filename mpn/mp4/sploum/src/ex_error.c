/*
** ex_error.c for sploum in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Nov 22 21:20:44 2001 jean-daniel michaud
** Last update Sun Nov 25 17:23:49 2001 jean-daniel michaud
*/

#include <curses.h>
#include <errno.h>

void	opendir_error(WINDOW *w)
{
  wclear(w);
  beep();
  wmove(w, getmaxy(w) - 1, 1);
  if (errno == ENOENT)
    wprintw(w, "No such file or directory");  
  if (errno == EACCES)
    wprintw(w, "Permission denied");
  wrefresh(w);
}

int	winsize(int height, int width)
{
  if ((getmaxy(stdscr) < height) || (getmaxx(stdscr) < width))
    {
      printw("Fenetre trop petite");
      refresh();
      return (1);
    }
  return (0);
}
