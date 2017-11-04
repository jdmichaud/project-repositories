/*
** my_atoi.c for my_atoi.c in ~/c/rendu/piscine/j2
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Sep 25 21:56:08 2001 jean-daniel michaud
** Last update Wed Sep 26 02:01:29 2001 jean-daniel michaud
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
