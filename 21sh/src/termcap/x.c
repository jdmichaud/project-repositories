/*
** x.c
** 
** Made by (Florent Monbillard)
** Login   <monbil_f@epita.fr>
** 
** Started on  Mon Dec 17 01:22:46 2001 Florent Monbillard
** Last update Mon Dec 31 15:16:23 2001 jean-daniel michaud
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "init_termcap.h"
#include "x.h"

#ifdef __sun
char *tgetstr(char id[2], char **area);
#endif

char    *xtgetstr(char *cap)
{
  char  *capstr;
  char	*area;
  char	t[4096];

  area = t;
  if ((capstr = tgetstr(cap, &area)) == NULL)
    return (NULL);
  return (capstr);
}

int	xtcgetattr(int fd, struct termios *t)
{
  if (tcgetattr(fd, t) < 0)
    return (0);
  return (1);
}

int	xtcsetattr(int fd, int action, const struct termios *t)
{
  if (tcsetattr(fd, action, t) < 0)
    return (0);
  return (1);
}





