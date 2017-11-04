/*
** morpion.c for morpion in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Nov  3 14:06:16 2001 jean-daniel michaud
** Last update Mon Nov  5 17:25:01 2001 jean-daniel michaud
*/

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

#include "morpion.h"
#include "my_printscreen.h"
#include "io.h"
#include "my_atoi.h"
#include "game.h"
#include "sig.h"

int		gl_stat;

void		init_game(int game[3][3])
{
  int		i;
  int		j;

  for (i = 0; i <= 2; ++i)
    for (j = 0; j <= 2; ++j)
      game[i][j] = VOID;
}

int		ask_pid(void)
{
  char		*pid;
  int		i;

  my_tiny_printscreen("Quel est le pid du concurent? >");
  pid = malloc(sizeof (10));
  my_get(pid);
  i = my_atoi(pid);
  free(pid);
  return (i);
}

int		start(int my_pid, int other_pid, int game[3][3])
{
  int		slot;
  char		*cmd;
  int		who;
 
  cmd = malloc(10 * sizeof (char));
  who = (my_pid > other_pid);
  while (is_end(game) == 3)
    {
      if (who)
	{
	  prompt(other_pid, cmd, game);
	  slot = my_atoi(cmd);
	  if (!free_slot(game, slot))
	    {
	      who = 0;
	      game[slot % 10 - 1][slot / 10 - 1] = 1;
	      send_sig(other_pid, slot);
	    }
	}
      else
	who = wait4response(other_pid, game);
    }
  return (is_end(game));
}

int			main(void)
{
  int			game[3][3];
  int			my_pid;
  int			other_pid;
  struct sigaction	action1;
  struct sigaction	action2;

  action1.sa_handler = reveive_usr1;
  sigemptyset(&(action1.sa_mask));
  action1.sa_flags = 0;
  action2.sa_handler = reveive_usr2;
  sigemptyset(&(action2.sa_mask));
  action2.sa_flags = 0;
  sigaction(SIGUSR1, &action1, NULL);
  sigaction(SIGUSR2, &action2, NULL);
  my_tiny_printscreen("pid : %d\n", my_pid = getpid());
  init_game(game);
  other_pid = ask_pid();
  return (start(my_pid, other_pid, game));
}
