/*
** my_printstr.c for my_printstr in ~/c/rendu/piscine/j2
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Sep 25 20:45:20 2001 jean-daniel michaud
** Last update Wed Oct 17 13:39:21 2001 jean-daniel michaud
*/

void	my_printstr(char *str)
{
  int	cpt;

  cpt = 0;
  while (str[cpt] != 0)
    {
      write(1, &str[cpt], 1);
      ++cpt;
    }
}
