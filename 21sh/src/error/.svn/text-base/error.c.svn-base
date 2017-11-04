/*
** error.c for 21sh in ~/c/rendu/projs/21sh
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Nov 29 11:29:23 2001 jean-daniel michaud
** Last update Sun Dec 30 22:12:06 2001 Florent Monbillard
*/

#include <stdio.h>

#include "error.h"

static char		*tab_error[] =
{
  "Not enough memory ",
  "I/O error ",
  "You are not in a terminal ",
  "bad pattern "
};

int	error(int n)
{
  if (n > MAX_ERROR)
    {
      fprintf(stderr, "21sh: Error\n");
      return (1);
    }
  else
    fprintf(stderr, "21sh: %s", tab_error[n + 1]);
  return (0);
}
