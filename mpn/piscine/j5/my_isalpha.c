/*
** my_isalpha.c for my_isalpha in ~/c/rendu/piscine/j5
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Mon Oct  1 19:15:08 2001 jean-daniel michaud
** Last update Tue Oct  2 00:18:34 2001 jean-daniel michaud
*/

int	my_isalpha(int c)
{
  if (((c > 64) && (c < 91)) || (c > 96) && (c < 123))
    return (1);
  else
    return (0);
}
