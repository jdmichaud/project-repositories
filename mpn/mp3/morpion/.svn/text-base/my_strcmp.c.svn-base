/*
** my_strcmp.c for my_strcmp in /c/rendu/piscine/j3/
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Sep 26 23:27:41 2001 jean-daniel michaud
** Last update Sat Nov  3 16:19:22 2001 jean-daniel michaud
*/

unsigned int	my_strlen(char *str)
{
  int	i;

  for (i = 0; str[i] != 0; ++i)
    ;
  return (i);
}
  
int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	size;

  if (my_strlen(s1) >= my_strlen(s2))
    size = my_strlen(s2);
  else
    size = my_strlen(s1);
  for (i = 0; ((i < size) && (s1[i] == s2[i])); ++i)
    ;
  if (s1 == s2)
    return (0);
  else
    return (s1[i] - s2[i]);
}
