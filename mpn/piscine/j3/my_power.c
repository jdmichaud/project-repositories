/*
** my_power.c for my_power in ~/c/rendu/piscine/j3
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Sep 26 21:01:15 2001 jean-daniel michaud
** Last update Wed Sep 26 21:05:58 2001 jean-daniel michaud
*/

int	my_power(int n, unsigned int p)
{
  int	res;
  int	i;

  if (!p)
    return (1);
  return (n * my_power(n, p - 1)); 
}
