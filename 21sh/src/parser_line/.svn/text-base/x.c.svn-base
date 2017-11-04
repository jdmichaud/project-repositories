/*
** x.c
** 
** Made by (Florent Monbillard)
** Login   <monbil_f@epita.fr>
** 
** Started on  Mon Dec 17 01:22:46 2001 Florent Monbillard
** Last update Mon Dec 17 18:05:33 2001 Florent Monbillard
*/

#include <stdio.h>
#include <stdlib.h>
#include <termcap.h>
#include <termios.h>
#include <unistd.h>
#include "types.h"
#include "errors.h"
#include "x.h"

char    *xtgetstr(char *cap)
{
  char  *capstr;
  char	*area;
  char	t[4096];

  area = t;
  if ((capstr = tgetstr(cap, &area)) == NULL)
    errors(e_getattr, cap);
  return (capstr);
}

void	xtcgetattr(int fd, struct termios *t)
{
  if (tcgetattr(fd, t) < 0)
    errors(e_other, "tcgetattr");
}

void	xtcsetattr(int fd, int action, const struct termios *t)
{
  if (tcsetattr(fd, action, t) < 0)
    errors(e_other, "tcgetattr");
}
