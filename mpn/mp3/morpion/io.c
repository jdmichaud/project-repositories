/*
** io.c for morpion in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Nov  3 15:17:28 2001 jean-daniel michaud
** Last update Mon Nov  5 15:38:03 2001 jean-daniel michaud
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <signal.h>

#include "io.h"
#include "morpion.h"
#include "my_printscreen.h"
#include "my_strcmp.h"

void	my_get(char *str)
{
  int	i;

  i = read(0, str, 10);
  str[i - 1] = '\0';
}

void	print_game(int game[3][3])
{
  int	i;
  int	j;

  for (i = 0; i <= 2; ++i)
    {
      my_tiny_printscreen(LINE);
      for (j = 0; j <= 2; ++j)
	{
	  my_tiny_printscreen(SEPARATOR);
	  if (game[i][j] == CROSS)
	    my_tiny_printscreen(CROSS_CHAR);
	  else
	    if (game[i][j] == CIRCLE)
	      my_tiny_printscreen(CIRCLE_CHAR);
	    else
	      if (game[i][j] == VOID)
		my_tiny_printscreen(VOID_CHAR);
	}
      my_tiny_printscreen(SEPARATOR);
      my_tiny_printscreen("\n");
    }
  my_tiny_printscreen(LINE);
}

void	prompt(int pid, char *cmd, int game[3][3])
{
  int	i;

  do
    {
      my_tiny_printscreen(PROMPT);
      my_get(cmd);
      if (!my_strcmp(cmd, PRINT))
	print_game(game);
      else
	if (!my_strcmp(cmd, EXIT))
	  {
	    for (i = 0; i <= 3; ++i)
	      kill(pid, SIGUSR1);
	    exit(3);
	  }
    } while (!my_strcmp(cmd, PRINT));
  cmd[2] = '\0';
}
