/*
** services.c for complètement_local in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Dec 15 10:16:55 2001 jean-daniel michaud

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "struct.h"
#include "comm.h"
#include "services.h"
#include "list.h"
#include "ftp.h"

static const t_command	command[] =
{
  {"USER", noimp},
  {"PASS", noimp},
  {"ACCT", noimp},
  {"CWD", cwd},
  {"CDUP", cdup},
  {"SMNT", smnt},
  {"REIN", rein},
  {"QUIT", quit},
  {"PORT", port},
  {"PASV", pasv},
  {"TYPE", type},
  {"STRU", stru},
  {"MODE", mode},
  {"RETR", retr},
  {"STOR", stor},
  {"STOU", stou},
  {"APPE", appe},
  {"ALLO", allo},
  {"REST", rest},
  {"RNFR", rnfr},
  {"RNTO", rnto},
  {"ABOR", abor},
  {"DELE", dele},
  {"RWD", rmd},
  {"MKD", mkd},
  {"PWD", pwd},
  {"LIST", list},
  {"NLST", nlst},
  {"SITE", site},
  {"SYST", syst},
  {"STAT", status},
  {"HELP", help},
  {"NOOP", noop},
  {"QUIT", quit},
  {"SIZE", size},
  {"MDTM", noimp},
  {"FEAT", noimp},
  {"EPSV", epsv},
  {"EPRT", noimp},
  {NULL, NULL}
};

void	waitingonce(t_server *server, t_user *user)
{
  char	*cmd;

  cmd = NULL;
  ualarm(TIMEOUT * 1000000, 50);
  getfromcl(user, &cmd);
#ifdef	DEBUG
  printf(cmd);
  printf("\n");
  fflush(stdout);
#endif
  ualarm(0, 0);
  parse(server, user, cmd);
}

void	waiting(t_server *server, t_user *user)
{
  char	*cmd;

  cmd = NULL;
  while (1)
    {
      ualarm(TIMEOUT * 1000000, 50);
      getfromcl(user, &cmd);
#ifdef	DEBUG
      printf(cmd);
      printf("\n");
      fflush(stdout);
#endif
      ualarm(0, 0);
      parse(server, user, cmd);
    }
}

int	parse(t_server *server, t_user *user, char *cmd)
{
  int	i;
  char	*save;
  char	*prefix;
  char	*argv[MAXARGS];
  
  save = cmd;
  prefix = get_nw(&cmd);
  strup(prefix, prefix);
  for (i = 0, argv[0] = NULL; i < MAXARGS; ++i)
    argv[i] = get_nw(&cmd);
  if ((i == MAXARGS) && (*cmd != 0))
    {
      log(2, "Command line too long");
      send2cl(user, "500 Command line too long");
    }
  else
    {
      for (i = 0; command[i].id != NULL; ++i)
	if (!strcmp(command[i].id, prefix))
	  {
	    free(save);
#ifdef	DEEPDEBUG
	    printf("CALL: %s\n", command[i].id);
	    fflush(stdout);
#endif
	    return (command[i].fnct(argv, server, user));
	  }
      send2cl(user, "500 Error");
    }
  free(save);
  return (1);
}

char		*get_nw(char **str)
{
  t_list	*llist;

  llist = NULL;
  for (; *str && (**str) && (**str != 32); (*str)++)
    push(&llist, **str);
  if (**str == 32)
    (*str)++;
  if (llist)
    push(&llist, 0);
  return (collapse(llist));
}
