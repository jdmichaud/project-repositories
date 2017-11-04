/*
** init_signals.c for 21sh in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Dec 11 14:50:01 2001 jean-daniel michaud
** Last update Sun Dec 30 11:57:48 2001 jean-daniel michaud
*/

#include <stdio.h>
#include <signal.h>

#include "process.h"
#include "xmalloc.h"

void			init_signals(void)
{
  handling(SIGINT, hint);
  handling(SIGCHLD, hchld);
  handling(SIGQUIT, hquit);
  handling(SIGTERM, hterm);
  handling(SIGTSTP, hstp);
}

void			handling(int idsignal, t_handler handler)
{
  struct sigaction	*sig;
  sigset_t		set;

  sig = xmalloc(sizeof (struct sigaction));
  sig->sa_handler = handler;
  sigemptyset(&set);
  sigaddset(&set, idsignal);
  sig->sa_mask = set;
  sig->sa_flags = SA_RESTART;
  sigaction(idsignal, sig, NULL);
}
