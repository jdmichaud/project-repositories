/*
** init.c for complètement_local in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Dec 13 10:36:36 2001 jean-daniel michaud
** Last update Mon Dec 17 20:12:04 2001 jean-daniel michaud
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

#include "struct.h"
#include "init.h"
#include "xmalloc.h"
#include "option.h"
#include "error.h"
#include "log.h"

extern int		gl_port;

t_server		*init(t_options *options)
{
  t_server		*server;

  if (options->options & VERSION)
    {
      fprintf(stdout, MFTP);
      exit(0);
    }
  if (options->loglevel >= 0)
    {
      log(options->loglevel, NULL);
      log(-1, options->logfile);
    }
  server = init_connection(options->port);
  server->params = options->options;
  server->loglevel = options->loglevel;
  server->maxuser = options->maxuser;
  return (server);
}

t_server		*init_connection(int port)
{
  int			authorize;
  t_server		*server;
  struct sockaddr_in    ftpaddr;

  log(3, "Init connection\n");
  server = xmalloc(sizeof (t_server));
  if ((server->socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    error(0, 1);
  log(3, "open socket\n");
  if (port == -1)
    server->port = getuid();
  else
    server->port = port;
  gl_port = server->port;
  ftpaddr.sin_family = AF_INET;
  ftpaddr.sin_port = htons(server->port);
  ftpaddr.sin_addr.s_addr = INADDR_ANY;
  authorize = 1;
  setsockopt(server->socket, SOL_SOCKET, SO_REUSEADDR, 
	     &authorize, sizeof (int));
  if (bind(server->socket, (struct sockaddr *) &ftpaddr, sizeof (ftpaddr)) < 0)
    error(1, 2);
  log(3, "bind done\n");
  fprintf(stdout, "Server launched on port %i\n", server->port);
  return (server);
}
