/*
** sig.c for morpion in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Nov  3 22:28:01 2001 jean-daniel michaud
** Last update Mon Nov  5 17:19:25 2001 jean-daniel michaud
*/

#include <signal.h>
#include <unistd.h>

#include "sig.h"
#include "morpion.h"
#include "my_atoi.h"

extern int	gl_stat;

void	atomic_send_sig(int pid, int val)
{
  if (val == 1)
    {
      kill(pid, SIGUSR1);
      kill(pid, SIGUSR2);
    }
  if (val == 2)
    {
      kill(pid, SIGUSR2);
      kill(pid, SIGUSR1);
    }      
  if (val == 3)
    {
      kill(pid, SIGUSR2);
      kill(pid, SIGUSR2);
    }      
}

void	send_sig(int pid, int slot)
{
  atomic_send_sig(pid, slot / 10);
  atomic_send_sig(pid, slot % 10);
}


void	reveive_usr1(int n)
{
  gl_stat *= 10;
}

void	reveive_usr2(int n)
{
  gl_stat *= 10;
  ++gl_stat;
}

int		wait4response(int pid, int game[3][3])
{
  int		i;
  sigset_t	set;

  sigemptyset(&set);
  gl_stat = 0;
  for (i = 0; i <= 3; ++i)
    sigsuspend(&set);
  gl_stat = bin2dec(gl_stat);
  game[gl_stat % 10 - 1][gl_stat / 10 - 1] = CROSS;
  gl_stat = 0;
  return (1);
}


