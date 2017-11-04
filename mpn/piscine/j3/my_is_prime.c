/*
** my_is_prime.c for my_is_prime in ~/c/rendu/piscine/j3
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Sep 26 21:06:43 2001 jean-daniel michaud
** Last update Mon Oct  1 15:36:56 2001 jean-daniel michaud
*/

unsigned int	my_is_prime(unsigned int a)
{
  int	i;

  if ((a == 1) || (a == 0))
    return (0);
  for (i = a - 1; i > 1; --i)
    if (!(a % i))
      return (0);
  return (1);
}

