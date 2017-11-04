/*
** my_revstr.c for my_revstr in ~/c/rendu/piscine/j3/
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Sep 26 22:08:29 2001 jean-daniel michaud
** Last update Mon Oct  1 16:46:35 2001 jean-daniel michaud
*/

unsigned int	my_strlen(char *str)
{
  int	i;

  for (i = 0; str[i] != 0; ++i)
    ;
  return (i);
}

void	my_revstr(char *dest, char *src)
{
  int	i;
  int	size;
  char	c;
  
  if (dest == src)
    {
      for (size = my_strlen(src), i = 0; i < (size / 2); ++i)
	{
	  c = dest[i];
	  dest[i] = src[size - (i + 1)];  
	  src[size - (i + 1)] = c;
	}
    }
  else
    {
      for (size = my_strlen(src), i = 0; i <= size; ++i)
	  dest[i] = src[size - (i + 1)];  
    }
  dest[size + 1] = 0;
}


