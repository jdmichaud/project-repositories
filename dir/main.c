/*
** main.c for dir in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Oct 17 13:03:59 2001 jean-daniel michaud
** Last update Wed Oct 17 13:32:52 2001 jean-daniel michaud
*/

#include "info_dir.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
  if (argc != 2)
    return (NULL);
  else
    return (info_dir(argv[1]));
}
