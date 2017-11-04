/*
** my_strlcat.c for my_strlcat in ~/c/rendu/piscine/j5
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Mon Oct  1 20:10:45 2001 jean-daniel michaud
** Last update Tue Oct  2 02:45:23 2001 jean-daniel michaud
*/

unsigned int	my_strlen(char *str)
{
  int	i;

  for (i = 0; str[i] != 0; ++i)
    ;
  return (i);
}


unsigned int	my_strlcat(char *dst, char *src, unsigned int size)
{
  int	size_dst;
  int	i;

  size_dst = my_strlen(dst);
  if (!(size) && (size < size_dst))
    return (size + my_strlen(src));
  for (i = 0; (((i + size_dst) < size) && (src[i] != '\0')); ++i)
    dst[i + size_dst] = src[i];
  if ((i + size_dst) < size)
    dst[i + size_dst] = '\0';
  else
    dst[i + size_dst - 1] = '\0';
  return (size_dst + my_strlen(src));
}
