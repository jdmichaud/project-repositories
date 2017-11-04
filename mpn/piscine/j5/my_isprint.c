/*
** my_isprint.c for my_isprint in ~/c/rendu/piscine/j5
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Mon Oct  1 19:33:10 2001 jean-daniel michaud
** Last update Mon Oct  1 20:02:09 2001 jean-daniel michaud
*/

int	my_isprint(char c)
{
  if ((c > 31) && (c < 127))
    return (1);
  else
    return (0);
}
