/*
** my_strlowcase.c for my_strlowcase in ~/c/rendu/piscine/j5
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Mon Oct  1 21:46:32 2001 jean-daniel michaud
** Last update Mon Oct  1 22:08:10 2001 jean-daniel michaud
*/

void	my_strlowcase(char *dest, char *src)
{
  for (; *src != '\0'; ++src, ++dest)
    {
      if ((*src > 65) && (*src < 91))
	*dest = *src + 32;
      else
	*dest = *src;
    }
}
