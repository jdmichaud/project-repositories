/*
** my_sort_params.c for my_sort_params in ~/c/rendu/piscine/j5/my_sort_params
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 01:02:48 2001 jean-daniel michaud
** Last update Tue Oct  2 01:36:58 2001 jean-daniel michaud
*/

void	main(int argc, char *argv[])
{
  int	stop;
  int	i;
  char	*tmp;

  stop = 1;
  while (stop)
    {
      stop = 0;
      for (i = 1; i < argc - 1; ++i)
	if (strcmp(argv[i], argv[i + 1]) > 0)
	  {
	    tmp = argv[i];
	    argv[i] = argv[i + 1];
	    argv[i + 1] = tmp;
	    stop = 1;
	  }
    }
  for (i = 1; i < argc; ++i)
    {
      my_printstr(argv[i]);
      my_printstr("\n");
    }
}
