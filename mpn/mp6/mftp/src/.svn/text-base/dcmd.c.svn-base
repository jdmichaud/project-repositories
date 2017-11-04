/*
** dcmd.c for complètement_local in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sun Dec 16 15:14:34 2001 jean-daniel michaud

*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "struct.h"
#include "list.h"
#include "user.h"
#include "dcmd.h"
#include "xmalloc.h"
#include "log.h"
#include "files.h"

int	listuser(char **argv)
{
  FILE	*file;
  char	*token;

  log(2, "From server: Asking user list\n");
  file = fopen(PASSFILE, "r");
  if (!file)
    {
      printf ("%s is a bad pass file\n", PASSFILE);
      log(2, "From server: bad pass file\n");
    }
  else
    while ((token = gnw(file)) && !feof(file))
      {
	printf("User : %s\t\t", token);
	token = gnw(file);
	printf("Pass : %s\t\t", token);
	token = gnw(file);
	printf("Home : %s\n", token);
  fflush(stdout);
      }
  fflush(stdout);
  return (0);
}

int		dadduser(char **argv)
{
  char		name[MAXLOGINSIZE];
  char		home[MAXDIRSIZE];
  char		*passwd;
  t_list	*list;
  char		c;

  log(2, "From server: Adding user\n");
  list = NULL;
  printf("login  : ");
  scanf("%s", name);
  printf("passwd : ");
  fflush(stdout);
  for (read(1, &c, 1); (c != '\n'); read(1, &c, 1))
    push(&list, c);
  passwd = collapse(list);
  printf("Home   : ");
  scanf("%s", home);
  adduser(name, passwd, home);
  if (passwd != NULL)
    free(passwd);
  return (1);
}

int	ddeluser(char **argv)
{
  return (0);
}

int	dquit(char **argv)
{
  exit(0);
  return (0);
}
