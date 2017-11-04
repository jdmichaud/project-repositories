/*
** log.c for complètement_local in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Dec 13 09:14:08 2001 jean-daniel michaud
** Last update Mon Dec 17 17:22:13 2001 jean-daniel michaud
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#include "log.h"
#include "error.h"

FILE		*log(int loglvl, const char *msg, ...)
{
  static int	lvl = 0;
  static int	verbose = 0;
  static FILE	*logfile = NULL;
  int		pid = getpid();

  if (loglvl == -3)
    verbose = 1;
  else
    if (loglvl == -2)
      fclose(logfile);
    else
      if (!msg && (loglvl > -1))
	lvl = loglvl;
      else
	if ((loglvl == -1) && msg)
	  logfile = fopen(msg, "w");
	else
	  if ((loglvl <= lvl) && msg)
	    fprintf(logfile, "%i - %s", pid, msg);
  if (verbose && msg)
    fprintf(stdout, "%i - %s", pid, msg);
  if (loglvl == -4)
    return (logfile);
  else
    return (NULL);
}
