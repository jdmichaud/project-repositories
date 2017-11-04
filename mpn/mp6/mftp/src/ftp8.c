/*
** ftp8.c for complètement_local in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Dec 15 11:56:36 2001 jean-daniel michaud

*/

#include <stdio.h>
#include <string.h>

#include "struct.h"
#include "ftp.h"
#include "log.h"
#include "xmalloc.h"
#include "comm.h"
#include "utils.h"
#include "files.h"

int	help(char **argv, t_server *server, t_user *user)
{
  send2cl(user, "214- Command implemented");
  sendfile2cl(user, HELP);
  send2cl(user, "214 End of help");
  return (0);
}

int	noop(char **argv, t_server *server, t_user *user)
{
  send2cl(user, "OK");
  return (0);
}

int	size(char **argv, t_server *server, t_user *user)
{
  FILE	*file;
  char	*resp;

  log(2, "Size demande\n");
  if (!(file = fopen(argv[0], "r")))
    {
      send2cl(user, "550 : No such file or directory.");
      return (1);
    }
  if (fseek(file, 0, SEEK_END) < 0)
    return (1);;
  resp = xmalloc(255 * sizeof (char));
  strcpy(resp, "213 ");
  strcat(resp, itoa(ftell(file)));
  send2cl(user, resp);
  return (0);
}

int	noimp(char **argv, t_server *server, t_user *user)
{
  log(2, "Not implemented yet ...\n");
  send2cl(user, "500 Not implemented yet");
  return (0);
}
