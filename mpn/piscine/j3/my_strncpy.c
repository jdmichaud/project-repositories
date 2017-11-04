/*
** my_strncpy.c for my_strncpy in ~/c/rendu/piscine/j3/
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Sep 26 21:38:17 2001 jean-daniel michaud
** Last update Thu Sep 27 01:11:35 2001 jean-daniel michaud
*/

char *my_strncpy(char *dest, char *src, int n)
{
  int	i;

  for (i = 0; ((i < n) && (src[i] != 0)); ++i)
      dest[i] = src[i];
  for (; (i + 1) < n; ++i)
    dest[i] = 0;
  return (dest);
}

