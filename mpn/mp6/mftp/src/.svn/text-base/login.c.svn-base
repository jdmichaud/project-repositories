/*
** login.c for complètement_local in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Fri Dec 14 12:38:24 2001 jean-daniel michaud
pwd

*/


#ifndef __alpha
#include <sys/types.h>
#endif
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>
#include <sys/time.h>

#include "struct.h"
#include "login.h"
#include "xmalloc.h"
#include "log.h"
#include "comm.h"
#include "user.h"
#include "services.h"
#include "ftp.h"
#include "files.h"

void		dupserver(t_server *server, int csocket)
{
  t_user	*user;
  FILE		*f;

  ++server->nbuser;
  if (server->nbuser > server->maxuser)
    {
      log(1, "Too much users...");
      error(4, 0);
      user = xmalloc(sizeof (t_user));
      user->socket = csocket;
      send2cl(user, "530 Too much user, try later");
      close(csocket);
      free(user);
      return;
    }
  if (fork())
    {
      log(3, "OK, we've got a client\n");
      if ((f = log(-4, NULL)))
	fprintf(f, "Client connected on socket %i\n", csocket);
      close (csocket);
    }
  else
    {
      user = login(server, csocket);
      chdir(user->homedir);
      waiting(server, user);
    }
}

t_user			*login(t_server *server, int csocket)
{
  t_user		*user;
  char			*sstime;
  struct timeval	tp;
  FILE			*f;

  if (!(user = authorize(server, csocket)))
    {
      log(3, "Access refused\n");
      send2cl(user, "530 Incorrect Login");
      quit(NULL, server, user);
    }
  log(3, "Access granted\n");
  send2cl(user, "230");
  gettimeofday(&tp, NULL);
  sstime = ctime(&tp.tv_sec);
  if ((server->loglevel >= 0) && (f = log(-4, NULL)))
    fprintf(f, "user %s logged in on %s\n", user->name, sstime);
  fprintf(stdout, "user %s logged in on %s\n", user->name, sstime);
  return (user);
}

t_user		*authorize(t_server *server, int csocket)
{
  t_user	*user;
  char		*name;
  char		*passwd;

  ualarm(TIMEOUT * 1000000, 50);
  log(3, "login\n");
  user = xmalloc(sizeof (t_user));
  user->socket = csocket;
  log(3, "asking logname\n");
  send2cl(user, "220-");
  sendfile2cl(user, WLCMSG);
  send2cl(user, "220 Service ready for new user");
  getfromcl(user, &name);
  log(3, "asking passwd\n");
  send2cl(user, "331");
  getfromcl(user, &passwd);
  name += strlen("USER ");
  passwd += strlen("PASS ");
  ualarm(-1, -1);
  if (!getuser(name, passwd, user) || (server->params & ANONYMOUS))
    return (user);
  fflush(stdout);
  return (NULL);
}
