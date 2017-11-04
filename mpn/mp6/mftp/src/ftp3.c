/*
** ftp3.c for complètement_local in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Dec 15 11:56:13 2001 jean-daniel michaud

*/

#ifndef __alpha
#include <sys/types.h>
#endif
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

#include "struct.h"
#include "ftp.h"
#include "log.h"
#include "comm.h"
#include "xmalloc.h"

int	stru(char **argv, t_server *server, t_user *user)
{
  noimp(NULL, server, user);
  return (0);
}

int	mode(char **argv, t_server *server, t_user *user)
{
  noimp(NULL, server, user);
  return (0);
}

int	retr(char **argv, t_server *server, t_user *user)
{
  FILE	*file;
  void	*buf;
  int	ssize;

  if (!(file = fopen(argv[0], "r")))
    {
      send2cl(user, "550 : No such file or directory.");
      return (1);
    }
  log(2, "Sending file ...\n");
  send2cl(user, "150 Opening BINARY mode data connection");
  buf = xmalloc(BUFFTRANS * sizeof (char));
  while (!feof(file))
    {
      ssize = fread(buf, 1, BUFFTRANS, file);
      senddata2cl(user, buf, ssize);
    }
  send2cl(user, "226 Transfer complete.");
  close(user->datasocket);
  fclose(file);
  free(buf);
  return (0);
}

int	stor(char **argv, t_server *server, t_user *user)
{
  FILE	*file;
  void	*buf;
  int	ssize;

  if (!(file = fopen(argv[0], "w+")))
    {
      send2cl(user, "550 : No such file or directory.");
      return (1);
    }
  log(2, "reveiving file ...\n");
  send2cl(user, "150 Opening BINARY mode data connection");
  buf = xmalloc(BUFFTRANS * sizeof (char));
  /*FIXME*/
  while (recv(user->datasocket, buf, ssize, 0))
    {
      recv(user->datasocket, buf, ssize, 0);
      ssize = fwrite(buf, 1, BUFFTRANS, file);
    }
  send2cl(user, "226 Transfer complete.");
  close(user->datasocket);
  fclose(file);
  free(buf);
  return (0);
}
