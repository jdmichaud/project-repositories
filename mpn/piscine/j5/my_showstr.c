/*
** my_showstr.c for my_showstr in ~/c/rendu/piscine/j5
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Mon Oct  1 23:14:13 2001 jean-daniel michaud
** Last update Tue Oct  2 02:39:36 2001 jean-daniel michaud
*/

void	my_printchar(char c)
{
  write(1, &c, 1);
}

void    my_showstr(char *str, unsigned int size)
{
  int	i;
  
  for (i = 0; ((str[i] != 0) && (i < size)); ++i)
    my_printchar(str[i]);
}
