/*
** ftp7.c for complètement_local in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Dec 15 11:56:32 2001 jean-daniel michaud

*/

#include <sys/types.h>
#include <unistd.h>
#ifndef __alpha
#include <sys/types.h>
#endif
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/utsname.h>
#include <sys/time.h>
#include <stdlib.h>

#include "struct.h"
#include "ftp.h"
#include "login.h"
#include "comm.h"
#include "xmalloc.h"
#include "log.h"

int		nlst(char **argv, t_server *server, t_user *user)
{
  char		c;
  int		p[2];
  int		pid;
  int		i;

  log(2, "special list file in directory for completion\n");
  send2cl(user, "150");
  pipe(p);
  if ((pid = fork()))
    {
      close(p[1]);
      for (read(p[0], &c, 1); read(p[0], &c, 1) > 0; )
	if (c == '\n')
	  write(user->datasocket, "\r\n", 2);
	else
	  write(user->datasocket, &c, 1);
      send2cl(user, "226");
      close(user->datasocket);
      wait(pid);
      return (0);
    }
  argv[1] = argv[0];
  argv[0] = strdup("ls");
  close(p[0]);
  dup2(p[1], 1);

  if (argv[1] && isregexp (argv[1]))
    execvp("ls", (char **) complete (argv));
  else
    execvp("ls", argv);
  exit(1);
}

int	site(char **argv, t_server *server, t_user *user)
{
  noimp(NULL, server, user);
  return (0);
}

int			syst(char **argv, t_server *server, t_user *user)
{
  char			*tmp;
  struct utsname	*name;

  log(2, "client ask system info\n");
  name = xmalloc(sizeof (struct utsname));
  uname(name);
  tmp = xmalloc(sizeof (char) *  255);
  strcpy(tmp, "215 ");
  strcat(tmp, name->sysname);
  send2cl(user, tmp);
  free(tmp);
  free(name);
  return (0);
}

int			status(char **argv, t_server *server, t_user *user)
{
  char			*info;
  char			*tmp;
  struct utsname	*name;

  log(2, "client ask system stat\n");
  name = xmalloc(sizeof (struct utsname));
  if (uname(name))
    {
      log(3, "Error on uname\n");
      send2cl(user, "202 Internal server error");
      free(name);
      return (1);
    }
  tmp = xmalloc(sizeof (char) * 255);
  strcpy(tmp, "211 Connected to mftp, itself running on ");
  strcat(tmp, name->sysname);
  strcat(tmp, " ");
  strcat(tmp, name->release);
  strcat(tmp, " ");
  strcat(tmp, name->version);
  strcat(tmp, " ");
  strcat(tmp, name->machine);
  send2cl(user, tmp);
  free(name);
  free(tmp);
  return (0);
}
