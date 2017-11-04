/*
** ftp5.c for complètement_local in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Dec 15 11:56:22 2001 jean-daniel michaud

*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#ifndef __alpha
#include <sys/types.h>
#endif
#include <sys/wait.h>

#include "struct.h"
#include "ftp.h"
#include "log.h"
#include "comm.h"
#include "utils.h"

int	rnfr(char **argv, t_server *server, t_user *user)
{
  noimp(NULL, server, user);
  return (0);
}

int	rnto(char **argv, t_server *server, t_user *user)
{
  noimp(NULL, server, user);
  return (0);
}

int	abor(char **argv, t_server *server, t_user *user)
{
  noimp(NULL, server, user);
  return (0);
}

int	dele(char **argv, t_server *server, t_user *user)
{
  int	i;
  char **toto;

  log(2, "Invoking Remove\n");
  if (fork())
    {
      wait(NULL);
      send2cl(user, "226 DELE command successful.");
      return (0);
    }
  argv[1] = argv[0];
  argv[0] = strdup("rm");

  toto = complete(argv);
  for (i = 0; toto[i]; ++i)
      fprintf(stderr, "%s ", toto[i]);
  if (argv[1])
    execvp("rm", (char **) complete(argv));
  else
    execvp("rm", argv);
  printf("Erreur interne\n");
  fflush(stdout);
  exit(1);
}
