/*
** process.c for 21sh in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Dec  1 16:25:35 2001 jean-daniel michaud
** Last update Mon Dec 31 00:09:36 2001 jean-daniel michaud
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

#include "struct.h"
#include "def.h"
#include "process.h"
#include "xmalloc.h"

t_glprocess    		*gl_process = NULL;

t_process		*init_process(t_command *command)
{
  int			i;
  t_process		*process;

  process = xmalloc(sizeof (t_process));
  process->argv = xmalloc((command->argc + 1) * sizeof (char *));
  for (i = 0; (i < command->argc) && (command->argv[i]); ++i)
    process->argv[i] = strdup(command->argv[i]);
  process->argv[i] = NULL;
  process->id = lsize(gl_process->process) + 1;
  process->background = command->background;
  process->fd_in = 0;
  process->fd_out = 1; 
  process->fd_err = 1;
  process->suspended = 0;
  if (command->infile)
    process->fd_in = open(command->infile, O_RDONLY);
  if (command->outfile)
    process->fd_out = command->append ? 
      open(command->outfile, O_WRONLY | O_CREAT | O_APPEND, 0666) : 
    open(command->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0666);
  if (command->errfile)
    process->fd_err = command->append ? 
      open(command->errfile, O_WRONLY | O_CREAT | O_APPEND, 0666) : 
    open(command->errfile, O_WRONLY | O_CREAT | O_TRUNC, 0666);
  return (process);
}

int			exec_list(t_command *command)
{
  t_command		*cmd;
  t_process		*process;
  int			tpipe[2];
  int			prec;
  
  for (prec = 0, cmd = command; cmd; cmd = cmd->next)
    {
      process = init_process(cmd);
      if (prec)
	{
	  process->fd_in = tpipe[0];
	  close(tpipe[1]);
	}
      if (cmd->next)
	{
	  pipe(tpipe);
	  process->fd_out = tpipe[1];
	  prec = 1;
	}
      qadd(&gl_process->process, process);
      execute(process);
    }
  if (prec)
    close(tpipe[1]);
  return (waitson());
}

int			waitson(void)
{
  while (isfgprocrunning(gl_process->process))
    pause();
  if (WIFEXITED(gl_process->laststatus))
    return (WEXITSTATUS(gl_process->laststatus));
  else
    if (WIFSIGNALED(gl_process->laststatus))
      return (128 + WTERMSIG(gl_process->laststatus));
  return (0);
}

int			execute(t_process *process)
{
  int			ret;
  int			i;

  if ((process->pid = fork()))
    return (0);
  if (process->background)
    process->fd_in = open("/dev/null", O_RDONLY);
  redir(process->fd_in, fileno(stdin));
  redir(process->fd_out, fileno(stdout));
  redir(process->fd_err, fileno(stderr));
  for (i = 3; (i < OPEN_MAX); ++i)
    close(i);
  ret = execvp(process->argv[0], process->argv);
  perror(process->argv[0]);
  exit(ret);
}

int			redir(int pfd, int fd)
{
  if (pfd != fd)
    {
      fflush(stdout);
      close(fd);
      dup2(pfd, fd);
      return (0);
    }
  return (1);
}
