/*
** ftp6.c for complètement_local in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Dec 15 11:56:27 2001 jean-daniel michaud

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
#include "xmalloc.h"

int	rmd(char **argv, t_server *server, t_user *user)
{
  noimp(NULL, server, user);
  return (0);
}

int	mkd(char **argv, t_server *server, t_user *user)
{
  log(2, "Make directory\n");
  if (mkdir(argv[0], 0766) < 0)
    {
      log(3, "Erreur a la creation\n");
      send2cl(user, "550 MKD command successful.");
      return (1);;
    }
  send2cl(user, "257 MKD command successful.");
  return (0);
}

int	pwd(char **argv, t_server *server, t_user *user)
{
  char	cd[MAXDIRSIZE];
  char	s[MAXDIRSIZE + 30];

  log(2, "Request current dir\n");
  getcwd(cd, MAXDIRSIZE);
  sprintf(s, "257 \"%s\" is current directory.", cd);
  send2cl(user, s);
  return (0);
}

int	list(char **argv, t_server *server, t_user *user)
{
  int	p[2];
  char	c;

  log(2, "list file in directory\n");
  send2cl(user, "150 Opening ASCII mode data connection for /bin/ls");
  pipe(p);
  if (fork())
    {
      close(p[1]);
      for (read(p[0], &c, 1); read(p[0], &c, 1) > 0; )
	if (c == '\n')
	  write(user->datasocket, "\r\n", 2);
	else
	  write(user->datasocket, &c, 1);
      close(user->datasocket);
      send2cl(user, "226 Transfer complete.");
      return (0);
    }
  argv[2] = argv[0];
  argv[0] = strdup("ls");
  argv[1] = strdup("-l");
  close(p[0]);
  dup2(p[1], 1);
  execvp("ls", argv);
  exit(1);
}
