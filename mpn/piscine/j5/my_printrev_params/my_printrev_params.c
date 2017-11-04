/*
** my_printrev_params.c for my_printrev_params in ~/c/rendu/piscine/j5/my_printrev_params
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 00:28:43 2001 jean-daniel michaud
** Last update Tue Oct  2 00:34:09 2001 jean-daniel michaud
*/

void	main(int argc, char *argv[])
{
  int	i;

  for (i = argc - 1; i > 0; --i)
    {
      my_printstr(argv[i]);
      my_printstr("\n");
    }
}
