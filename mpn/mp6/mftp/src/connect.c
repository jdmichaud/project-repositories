/*
** connect.c for complètement_local in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Dec 13 09:22:16 2001 jean-daniel michaud

*/

#ifndef __alpha
#include <sys/types.h>
#endif
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "struct.h"
#include "connect.h"
#include "error.h"
#include "login.h"
#include "utils.h"
#include "comm.h"
#include "log.h"

static struct sockaddr_in	client;


int				waitfor(t_server *server)
{
  int				clientsocket;
#ifndef	__alpha
  unsigned int			addrlen;
#else
  int				addrlen;
#endif

  if (listen(server->socket, BACKLOG) < 0)
    error(3, 1);
  addrlen = sizeof(struct sockaddr_in);
  while (1)
    {
      log(3, "listening ...\n");
      if ((clientsocket = 
	   accept(server->socket, (struct sockaddr *) &client, &addrlen)) < 0)
	error(4, 0);
      else
	dupserver(server, clientsocket);
    }
 return (0);
}

int				fconnect(int fd, char *host, int pport)
{
  log(2, "Connection to client ...\n");
  client.sin_port = htons(pport);
  if ((connect(fd, (struct sockaddr *)&client, sizeof(client))) == -1)
    {
      perror("connect");
      printf("Error: cannot connect to host\n");
      log(2, "Cannot connect\n");
      return (1);
    }
  return (0);
}
