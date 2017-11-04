/*
** my_strlen.c for my_strlen in ~/c/rendu/piscine/j3
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Sep 26 21:25:31 2001 jean-daniel michaud
** Last update Thu Sep 27 00:05:18 2001 jean-daniel michaud
*/

unsigned int	my_strlen(char *str)
{
  int	i;

  for (i = 0; str[i] != 0; ++i)
    ;
  return (i);
}
  
