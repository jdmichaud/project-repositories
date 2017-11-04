/*
** main.c for  complètement_local in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Dec 13 09:09:12 2001 jean-daniel michaud
** Last update Mon Dec 17 19:38:25 2001 jean-daniel michaud
*/

#ifndef __alpha
#include <sys/types.h>
#endif
#include <stdio.h>
#include <unistd.h>

#include "struct.h"
#include "init.h"
#include "option.h"
#include "log.h"
#include "connect.h"
#include "user.h"
#include "xmalloc.h"
#include "signals.h"
#include "cmdline.h"

int		gl_port;
int		promptpid;

int		main(int argc, char *argv[])
{
  t_server	*server;
  t_options	*options;
  int		pid;
  
  init_signals();
  options = getoptions(argv);
  if ((pid = fork()))
    {
      server = init(options);
      waitfor(server);
    }
  else
    prompt();
  return (0);
}
