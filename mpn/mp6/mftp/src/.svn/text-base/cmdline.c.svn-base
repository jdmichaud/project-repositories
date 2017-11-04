/*
** cmdline.c for complètement_local in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Dec 13 10:13:06 2001 jean-daniel michaud

*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

#include "struct.h"
#include "cmdline.h"
#include "dcmd.h"
#include "list.h"

static const t_debugcmd	 dcmd[] =
{
  {"user", listuser},
  {"adduser", dadduser},
  {"deluser", ddeluser},
  {"quit", dquit},
  {NULL, NULL}
};

char		*gnl(void)
{
  char		c;
  t_list	*list;
  
  list = NULL;
  for (read(1, &c, 1); (c != '\n'); read(1, &c, 1))
    push(&list, c);
  push(&list, 0);
  return (collapse(list));
}

void	prompt(void)
{
  int	i;
  char	*cmd;

  while (1)
    {
      cmd = gnl();
      for (i = 0; dcmd[i].id; ++i)
	if (!strcmp(cmd, dcmd[i].id))
	  dcmd[i].fnct(NULL);
      free(cmd);
      printf(PROMPT);
      fflush(stdout);
    }
}

void	parsecmd(char *cmd)
{
}
