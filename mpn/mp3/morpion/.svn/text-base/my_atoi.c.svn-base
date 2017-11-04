/*
** my_atoi.c for my_atoi.c in ~/c/rendu/piscine/j2
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Sep 25 21:56:08 2001 jean-daniel michaud
** Last update Sun Nov  4 16:52:27 2001 jean-daniel michaud
*/

int	my_atoi(char *str)
{
  int	cpt;
  int	mul;
  int	res;
  
  res = 0;
  for (cpt = 0; str[cpt + 1] != 0; ++cpt);
  mul = 1;
  while (cpt >= 0)
    {
      if (str[cpt] == '-')
	res *= -1;
      else
	  res += (str[cpt] - 48) * mul;
      mul *= 10;
      --cpt;
    }
  return (res);
}

int     my_power(int val, int pow)
{
  int   res;
  int   i;

  if (!pow)
    return (1);
  res = val;
  for (i = 2; i <= pow; ++i)
    res *= val;
  return (res);
}

int	value_of_duet(int nbr)
{
  if (nbr == 1)
    return (1);
  else
    if (nbr == 10)
      return (2);
    else
      if (nbr == 11)
	return (3);
  return (0);
}

int	bin2dec(int nbr)
{
  if (nbr == 0)
    exit(3);
  return ((value_of_duet(nbr / 100) * 10) + (value_of_duet(nbr % 100)));
}
