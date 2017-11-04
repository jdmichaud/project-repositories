/*
** my_strstr.c for my_strstr in ~/c/rendu/piscine/j3/
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Sep 26 22:30:56 2001 jean-daniel michaud
** Last update Thu Sep 27 01:47:35 2001 jean-daniel michaud
*/

unsigned int	my_strlen(char *str)
{
  int	i;

  for (i = 0; str[i] != 0; ++i)
    ;
  return (i);
}

char	*my_strstr(char *big, char *litle)
{
  int	i;
  int	j;
  int	size;
  int	size_big;
  
  if (!(*litle))
    return (big);
  size = my_strlen(litle);
  size_big = my_strlen(big);
  j = 0;
  while (j <= (size_big - size))
    {
      for (i = 0; ((i < (size - 1)) && (big[i + j] == litle[i])); ++i)
	;
      if (big[i + j] == litle[i])
	return (&big[j]);
      ++j;
    }
  return (0);
}


