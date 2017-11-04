/*
** lddump.c for lddump in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Nov 29 21:07:23 2001 jean-daniel michaud
** Last update Tue Dec  4 04:06:04 2001 jean-daniel michaud
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "struct.h"
#include "vars.h"
#include "libs.h"
#include "norps.h"
#include "io.h"
#include "parser.h"

void			quit(int n)
{
  printf("norps terminated\n");
  exit(0);
}

void			init_sig(void)
{
  struct sigaction      s;
  
  sigemptyset(&(s.sa_mask));
  sigaddset(&(s.sa_mask), SIGINT);
  s.sa_flags = SA_RESTART;
  s.sa_handler = quit;
  sigaction(SIGINT, &s, NULL);
}

int		main(void)
{
  t_libs	*libs;
  t_vars	*vars;
  char		*cmd;
  int		i;
  
  libs = NULL;
  vars = NULL;
  init_sig();
  i = 1;
  while (i)
    {
      cmd = getcmd();
      i = parse(&libs, &vars, cmd);
      if (cmd)
	free(cmd);
    }
  free_libs(libs);
  return (0);
}
