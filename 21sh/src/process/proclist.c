/*
** proclist.c for 21sh in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Dec 12 11:21:45 2001 jean-daniel michaud
** Last update Sun Dec 30 15:47:01 2001 jean-daniel michaud
*/

#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

#include "process.h"

extern t_glprocess	*gl_process;

void		delproc(t_list **glprocess, int pid)
{
  t_list	*lprocess;
  t_process	*process;

  if (*glprocess)
    {
      process = (*glprocess)->elem;
      if (process->pid == pid)
	{
	  lprocess = *glprocess;
	  *glprocess = (*glprocess)->next;
	  if (*glprocess)
	    (*glprocess)->prec = NULL;
	  free_elem(lprocess);
	}
      else
	{
	  for (lprocess = *glprocess, process = lprocess->elem; lprocess 
		 && (process->pid != pid); process = lprocess->elem)
	    lprocess = lprocess->next;
	  lprocess->prec->next = lprocess->next;
	  if (lprocess->next)
	    lprocess->next->prec = lprocess->prec;
	  free_elem(lprocess);
	}
    }
}

t_process	*getproc(t_list *lprocess, int pid)
{
  t_process	*process;

  if (lprocess)
    for (process = lprocess->elem; lprocess && (process->pid != pid); )
      {
	lprocess = lprocess->next;
	if (lprocess)
	  process = lprocess->elem;
      }
  if (lprocess)
    return (process);
  return (NULL);
}

int		isfgprocrunning(t_list *lprocess)
{
  t_process	*process;

  if (lprocess)
    for (process = lprocess->elem; lprocess; lprocess = lprocess->next)
      {
	process = lprocess->elem;
	if ((!process->background) && (!process->suspended))
	  return (process->pid);
      }
  return (0);
}

void		free_elem(t_list *lprocess)
{
  int		i;
  t_process	*process;

  process = lprocess->elem;
  for (i = 0; process->argv[i]; ++i)
    free(process->argv[i]);
  free(process);
  free(lprocess);
}

void		stopall(void)
{
  t_list	*lprocess;
  t_process	*process;

  lprocess = gl_process->process;
  while (lprocess)
    {
      process = lprocess->elem;
      printf("Sending TERM signal to %i\n", process->pid);
      fflush(stdout);
      kill(process->pid, SIGTERM);
      lprocess = lprocess->next;
    }
  lprocess = gl_process->process;
  while (lprocess)
    {
      process = lprocess->elem;
      printf("Sending KILL signal to %i\n", process->pid);
      fflush(stdout);
      kill(process->pid, SIGKILL);
      lprocess = lprocess->next;
    }
}
