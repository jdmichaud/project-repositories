/*
** ftp2.c for complètement_local in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Dec 15 11:56:08 2001 jean-daniel michaud

*/

#include <stdio.h>
#ifndef __alpha
#include <sys/types.h>
#endif
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#include "struct.h"
#include "services.h"
#include "struct.h"
#include "ftp.h"
#include "log.h"
#include "comm.h"
#include "utils.h"
#include "connect.h"
#include "signals.h"

int	quit(char **argv, t_server *server, t_user *user)
{
  log(2, "Server shutdown\n");
  send2cl(user, "221 Goodbye.");
  send2cl(user, "500 ");
  close(user->datasocket);
  close(user->socket);
  close(server->socket);
  close(server->datasocket);
  free(server);
  free(user);
  exit(0);
}

int	port(char **argv, t_server *server, t_user *user)
{
  int	i;
  int	nb;
  char	addr[16];
  char	pport[8];

  log(2, "Entering active mode\n");
  if (argv[0])
    {
      for (i = 0, nb = 0; nb < 4; ++i)
	if (argv[0][i] == ',')
	  {
	    addr[i] = '.';
	    ++nb;
	  }
	else
	  addr[i] = argv[0][i];
      addr[i - 1] = 0;
      for (nb = 0; argv[0][i]; ++i, ++nb)
	pport[nb] = argv[0][i];
      pport[nb] = 0;
      user->datasocket = server->datasocket = socket(AF_INET, SOCK_STREAM, 0);
      send2cl(user, "220 PORT command succefull");
      if (fconnect(user->datasocket, addr, char2port(pport)))
	interrupt (0);
      waitingonce(server, user);
    }
  return (0);
}

int			pasv(char **argv, t_server *server, t_user *user)
{
  int			randport;
#ifndef __alpha
  unsigned int		addrlen;
#else
  int			addrlen;
#endif
  char			resp[50];
  struct sockaddr_in    addr;

  log(2, "Entering passive mode\n");
  randport = 10000;
  server->datasocket = user->datasocket = socket(AF_INET, SOCK_STREAM, 0);
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(randport);
  while (bind(server->datasocket, (struct sockaddr *) &addr, sizeof (addr)))
    if (randport > 65534)
      addr.sin_port = htons(randport = 10000);
    else
      addr.sin_port = htons(++randport);
  server->dataport = user->dataport = randport;
  strcpy(resp, "227 Entering Passive Mode (");
  strcat(resp, getip(1));
  strcat(resp, ",");
  strcat(resp, port2char(randport));
  strcat(resp, ")");
  listen(server->datasocket, BACKLOG);
  send2cl(user, resp);
  addrlen = sizeof (struct sockaddr_in);
  user->datasocket = 
    accept(server->datasocket, (struct sockaddr *) &addr, &addrlen);
  waitingonce(server, user);
  return (0);
}

int			epsv(char **argv, t_server *server, t_user *user)
{
  noimp(NULL, server, user);
  return (0);
}

int			type(char **argv, t_server *server, t_user *user)
{
  if (argv[0])
    {
      if (!strcmp(argv[0], "A"))
	{
	  user->datatype = ASCII_TYPE;
	  log(2, "change data type to ASCII\n");
	  send2cl(user, "200 Type is now ASCII");
	}
      else if (!strcmp(argv[0], "I"))
	{
	  user->datatype = IMAGE_TYPE;
	  log(2, "change data type to BINARY\n");
	  send2cl(user, "200 Type is now IMAGE (BINARY)");
	}
      else
	send2cl(user, "504 Command not implemented for this parameter");
    }
  return (0);
}
