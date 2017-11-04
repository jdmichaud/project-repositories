/*
** colors.c for sploum in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Nov 22 17:38:56 2001 jean-daniel michaud
** Last update Fri Nov 23 21:27:39 2001 jean-daniel michaud
*/

#include <curses.h>

#include "def.h"
#include "colors.h"

void	init_palette(int n)
{
  if (n)
    {
      init_pair(WONB, COLOR_WHITE, COLOR_BLACK);
      init_pair(BONW, COLOR_BLACK, COLOR_WHITE);
      init_pair(YONB, COLOR_YELLOW, COLOR_BLUE);
      init_pair(BONY, COLOR_BLUE, COLOR_YELLOW);
    }
  else
    {
      init_pair(WONB, COLOR_WHITE, COLOR_BLACK);
      init_pair(BONW, COLOR_WHITE, COLOR_BLACK);
      init_pair(YONB, COLOR_WHITE, COLOR_BLACK);
      init_pair(BONY, COLOR_WHITE, COLOR_BLACK);
    }
}

void	enable_color(void)
{
  init_pair(USER, COLOR_WHITE, COLOR_BLACK);
  if (has_colors())
    {
      start_color();
      bkgd(COLOR_PAIR(USER));
      init_palette(1);
      refresh();
    }
  else
    init_palette(0);
}
