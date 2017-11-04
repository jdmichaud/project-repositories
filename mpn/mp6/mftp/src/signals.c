/*
** signals.c for complètement_local in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Dec 13 19:36:52 2001 jean-daniel michaud
** Last update Mon Dec 17 20:05:20 2001 jean-daniel michaud
*/

#ifndef __alpha
#include <sys/types.h>
#endif
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

#include "struct.h"
#include "log.h"
#include "signals.h"
#include "xmalloc.h"
#include "comm.h"

extern int		gl_port;

void			interrupt(int n)
{
  log(2, "Server interrupted, closing socket\n");
  close(gl_port);
  exit(0);
}

void			timeout(int n)
{
  t_user		*user;

  user = xmalloc(sizeof (t_user));
  log(2, "timeout\n");
  user->socket = gl_port;
  send2cl(user, "426 ");
  free(user);
  close(gl_port);
  exit(0);
}

void                    init_signals(void)
{
  handling(SIGINT, interrupt);
  handling(SIGQUIT, interrupt);
  handling(SIGTERM, interrupt);
  handling(SIGALRM, timeout);
}

void                    handling(int idsignal, t_handler handler)
{
  struct sigaction      sig;

  sig.sa_handler = handler;
  sigemptyset(&sig.sa_mask);
  sigaddset(&sig.sa_mask, idsignal);
#ifndef __sun
  sig.sa_flags = SA_RESTART;
#else
  sig.sa_flags = 0;
#endif
  sigaction(idsignal, &sig, NULL);
}
