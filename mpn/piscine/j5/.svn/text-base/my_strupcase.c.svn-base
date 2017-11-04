/*
** my_strupcase.c for my_strupcase in ~/c/rendu/piscine/j5
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Mon Oct  1 21:28:23 2001 jean-daniel michaud
** Last update Mon Oct  1 21:54:03 2001 jean-daniel michaud
*/

void	my_strupcase(char *dest, char *src)
{
  for (; *src != '\0'; ++src, ++dest)
    {
      if ((*src > 96) && (*src < 123))
	*dest = *src - 32;
      else
	*dest = *src;
    }
}
