/*
** comm.c for complètement_local in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Dec 13 21:20:33 2001 jean-daniel michaud

*/
  
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "struct.h"
#include "comm.h"
#include "xmalloc.h"
#include "list.h"

int	send2cl(t_user *user, void *buf)
{
  int	i;
  char	stop;
  char	*sentence;

  stop = 10;
  sentence = buf;
  i = send(user->socket, sentence, strlen(sentence) + 1, 0);
  return (i + send(user->socket, &stop, sizeof (char), 0));
}

int		senddata2cl(t_user *user, void *buf, unsigned int ssize)
{
  unsigned int	i;
  unsigned int	eol;
  char		*b;
  
  for (i = 0, eol = 0; i < ssize; ++i)
    if (((char *) buf)[i] == '\n')
      ++eol;
  b = malloc ((ssize + eol) * sizeof (char));
  for (i = 0; i < ssize; ++i)
    if (((char *) buf)[i] == '\n')
      {
	b[i++] = '\r';
	b[i] = '\n';
      }
    else
      b[i] = ((char *) buf)[i];
  return (send(user->datasocket, b, ssize + eol, 0));
}

void		sendfile2cl(t_user *user, char *file)
{
  FILE		*wlcm;
  t_list	*list;
  char		c;

  wlcm = fopen(file, "r");
  list = NULL;
  while (!feof(wlcm))
    {
      c = fgetc(wlcm);
      if (c != EOF)
	push(&list, c);
    }
  push(&list, 0);
  send2cl(user, collapse(list));
  fclose(wlcm);
}

int		getfromcl(t_user *user, char **buff)
{
  int		i;
  char		c;
  t_list	*list;

  list = NULL;
  for (read(user->socket, &c, 1), i = 0; c && (c != EOL) && (c != EOF); ++i)
    {
      if (c != 13)
	push(&list, c);
      if (!read(user->socket, &c, 1))
	return (0);
    }
  push(&list, 0);
  *buff = collapse(list);
  return (i);
}

void	freeport(int pport)
{
  char	c;

  while (pport != 10)
    read(pport, &c, 1);
}
