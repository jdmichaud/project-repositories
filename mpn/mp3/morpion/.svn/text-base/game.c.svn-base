/*
** game.c for morpion in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Nov  3 16:14:10 2001 jean-daniel michaud
** Last update Mon Nov  5 17:24:18 2001 jean-daniel michaud
*/

#include "game.h"
#include "my_printscreen.h"

int	win(int game[3][3], int player)
{
  int	i;

  for (i = 0; i <= 2; ++i)
    {
      if ((game[i][0] == player) && (game[i][1] == player) 
	  && (game[i][2] == player))
	return (1);
      if ((game[0][i] == player) && (game[1][i] == player) 
	  && (game[2][i] == player))
	return (1);
    }
  if ((game[0][0] == player) && (game[1][1] == player)
      && (game[2][2] == player))
    return (1);
  if ((game[2][0] == player) && (game[1][1] == player)
      && (game[0][2] == player))
    return (1);
  return (0);
}

int	is_game_full(int game[3][3])
{
  int	i;
  int	j;

  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j)
      if (!game[i][j])
	return (0);
  return (1);
}

int	is_end(int game[3][3])
{
  if (is_game_full(game))
    return (2);
  if (win(game, 1))
    return (0);
  if (win(game, 2))
    return (1);
  return (3);
}


int	free_slot(int game[3][3], int  slot)
{
  if (((slot / 10) > 3) || ((slot / 10) < 1)
      || ((slot % 10) > 3) || ((slot % 10) < 1))
    {
      my_tiny_printscreen("Case invalide\n");
      return (1);
    }
  if (game[slot % 10 - 1][slot / 10 - 1])
    {
      my_tiny_printscreen("Case %d%d prise\n", slot / 10, slot % 10);
      return (2);
    }
  return (0);
}
