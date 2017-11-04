/*
** ftp1.c for complètement_local in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Dec 15 11:47:24 2001 jean-daniel michaud
** Last update Mon Dec 17 21:31:01 2001 jean-daniel michaud
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "struct.h"
#include "ftp.h"
#include "log.h"
#include "comm.h"
#include "xmalloc.h"

int	cwd(char **argv, t_server *server, t_user *user)
{
  if (argv[0])
    {
      log(2, "change directory\n");
      if (chdir(argv[0]) < 0)
	{
	  send2cl(user, "550 impossible");
	  return (1);
	}
    }
  send2cl(user, "250 CWD command successful.");	
  return (0);
}

int	cdup(char **argv, t_server *server, t_user *user)
{
  char	**arg;

  arg = xmalloc(sizeof (char *));
  argv[0] = strdup("..");
  cwd(arg, server, user);
  free(argv[0]);
  free(arg);
  return (0);
}

int	smnt(char **argv, t_server *server, t_user *user)
{
  noimp(NULL, server, user);
  return (0);
}

int	rein(char **argv, t_server *server, t_user *user)
{
  noimp(NULL, server, user);
  return (0);
}
