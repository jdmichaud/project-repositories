/*
** ed_error.c for sploum in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sun Nov 25 10:15:33 2001 jean-daniel michaud
** Last update Sun Nov 25 20:34:04 2001 jean-daniel michaud
*/

#include <curses.h>
#include <errno.h>

int	openfile_error(WINDOW *w)
{
  wclear(w);
  beep();
  wmove(w, getmaxy(w) - 1, 1);
  if (errno == ENOENT)
    wprintw(w, "No such file or directory");  
  if (errno == EACCES)
    wprintw(w, "Permission denied");
  wrefresh(w);
  return (0);
}
