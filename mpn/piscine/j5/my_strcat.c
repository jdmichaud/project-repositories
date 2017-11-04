/*
** my_strcat.c for my_strcat in ~/c/rendu/piscine/j5
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Mon Oct  1 20:02:58 2001 jean-daniel michaud
** Last update Tue Oct  2 02:46:42 2001 jean-daniel michaud
*/

unsigned int	my_strlen(char *str)
{
  int	i;

  for (i = 0; str[i] != 0; ++i)
    ;
  return (i);
}

char	*my_strcat(char *s, char *append)
{
  int	size;
  int	i;

  size = my_strlen(s);
  for (i = 0; append[i] != '\0'; ++i)
    s[size + i] = append[i];
  s[i] = '\0';
  return (s);
}
