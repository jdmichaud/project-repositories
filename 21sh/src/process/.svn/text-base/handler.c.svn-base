/*
** handler.c for 21sh in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Dec 11 16:57:05 2001 jean-daniel michaud
** Last update Sun Dec 30 23:43:39 2001 jean-daniel michaud
*/

#ifndef __alpha
#include <sys/types.h>
#endif
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>

#include "process.h"

extern t_glprocess	*gl_process;

void			hchld(int nsig)
{
  int			pid;
  t_process		*process;
  
  /*  printf("SIGCHLD\n"); */
  /*  fflush(stdout); */
  while ((pid = waitpid(-1, &(gl_process->laststatus), 
			WNOHANG | WUNTRACED)) > 0)
    if (!WIFSTOPPED(gl_process->laststatus))
      {
	process = getproc(gl_process->process, pid);
	if (process->background)
	  {
	    printf("[%i] %i %s - Die\n", process->id, process->pid, 
		   process->argv[0]);
	    fflush(stdout);
	  }
	delproc(&(gl_process->process), pid);  
      }
    else
      hstp(nsig);
}

void		hint(int nsig)
{
  nsig = 0;
  printf("interrupted\n");
}

void		hterm(int nsig)
{
  nsig = 0;
  printf("terminated\n");
}

void		hquit(int nsig)
{
  nsig = 0;
  printf("SIGQUIT\n");
}

void		hstp(int nsig)
{
  t_list	*lprocess;
  t_process	*process;

  nsig = 0;
  lprocess = gl_process->process;
  while (lprocess)
    {
      process = lprocess->elem;
      if (!process->background)
	process->suspended = 1;
      else
	kill(process->pid, SIGCONT);
      lprocess = lprocess->next;
    }
}
