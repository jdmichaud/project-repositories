/*
** error.c for complètement_local in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Dec 13 10:44:06 2001 jean-daniel michaud
** Last update Mon Dec 17 19:50:54 2001 jean-daniel michaud
*/

#include <stdio.h>

#include "error.h"
#include "log.h"

static const char	*taberror[] =
{
  "Cannot create socket ",
  "Cannot bind port ",
  "Cannot listen on port ",
  "Cannot accept client ...",
  "Too much user "
};

int	error(int errcode, int exitcode)
{
  if (errcode >= MAXERR)
    {
      fprintf(stderr, "Erreur\n");
      exit(1);
    }
  else
    {
      fprintf(stderr, "%s\n", taberror[errcode]);
      log(4, taberror[errcode]);
      if (exitcode > 0)
	exit(exitcode);
    }
  return (0);
}

int	usage(void)
{
  printf(USAGE);
  exit(1);
}
