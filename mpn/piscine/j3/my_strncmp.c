/*
** my_strncmp.c for my_strncmp in ~/c/rendu/piscine/j3/
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Sep 26 23:59:13 2001 jean-daniel michaud
** Last update Thu Sep 27 01:19:50 2001 jean-daniel michaud
*/

unsigned int	my_strlen(char *str)
{
  int	i;

  for (i = 0; str[i] != 0; ++i)
    ;
  return (i);
}
  
int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;
  int	size;
  int	stop;

  if (my_strlen(s1) >= my_strlen(s2))
    size = my_strlen(s2);
  else
    size = my_strlen(s1);
  size = (size > n) ? n : size;
  for (i = 0; ((i < size) && (s1[i] == s2[i]) && stop); ++i)
      stop = ((s1[i + 1] != 0) && (s2[i + 1] != 0));
  if (s1 == s2)
    return (0);
  else
    if (!stop)
      --i;
    return (s1[i] - s2[i]);
}
