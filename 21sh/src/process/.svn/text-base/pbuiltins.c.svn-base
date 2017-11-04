/*
** pbuiltins.c for 21sh in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Mon Dec 10 21:43:37 2001 jean-daniel michaud
** Last update Sun Dec 30 23:48:10 2001 jean-daniel michaud
*/

#include <stdio.h>
#include <signal.h>

#include "list.h"
#include "struct.h"
#include "process.h"
#include "pbuiltins.h"


extern t_glprocess	*gl_process;

int			jobs(t_command *cmd)
{
  t_list		*lprocess;
  t_process		*process;

  if (gl_process->process)
    {
      lprocess = gl_process->process;
      for (; lprocess; lprocess = lprocess->next)
	{
	  process = lprocess->elem;
	  printf("[%i] %i ", process->id, process->pid);
	  printf("%s", process->argv[0]);
	  if (process->suspended)
	    printf(" - Suspended ");
	  printf("\n");
	}
    }
  cmd = NULL;
  return (0);
}

int	pkill(int pid)
{
  kill(pid, SIGKILL);
  return (pid);
}

int		fg(t_command *cmd)
{
  t_list	*lprocess;
  t_process	*process;

  lprocess = gl_process->process;
  while (lprocess)
    {
      process = lprocess->elem;
      process->suspended = 0;
      printf("%s reactivated\n", process->argv[0]);
      kill(process->pid, SIGCONT);
      lprocess = lprocess->next;
    }
  waitson();
  cmd = NULL;
  return (0);
}

int	bg(t_command *cmd)
{
  t_list	*lprocess;
  t_process	*process;

  lprocess = gl_process->process;
  while (lprocess)
    {
      process = lprocess->elem;
      process->suspended = 0;
      process->background = 1;
      printf("%s reactivated\n", process->argv[0]);
      kill(process->pid, SIGCONT);
      lprocess = lprocess->next;
    }
  cmd = NULL;
  return (0);
}

