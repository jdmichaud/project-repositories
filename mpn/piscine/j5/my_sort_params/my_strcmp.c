/*
** my_strcmp.c for my_strcmp in /c/rendu/piscine/j3/
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Sep 26 23:27:41 2001 jean-daniel michaud
** Last update Tue Oct  2 01:36:26 2001 jean-daniel michaud
*/
  
int	my_strcmp(char *s1, char *s2)
{
  unsigned char		c1;
  unsigned char		c2;

  while (*s1 && *s2)
    {
      c1 = *s1;
      c2 = *s2;
      if (c1 != c2)
        return (c1 - c2);
      s1++;
      s2++;
    }
  return (c1 - c2);
}
