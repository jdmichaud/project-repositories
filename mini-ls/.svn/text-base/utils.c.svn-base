/*
** utils.c for mini-ls in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Fri Nov 16 15:41:05 2001 jean-daniel michaud
** Last update Tue Nov 20 02:02:30 2001 jean-daniel michaud
*/

#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>

#include "list_file.h"
#include "utils.h"
#include "my_printf.h"
#include "my_strcmp.h"

unsigned int	get_max_size(t_list_file *list)
{
  unsigned int	max;

  max = 0;
  while (list)
    {
      if (max < list->sb->st_size)
	max = list->sb->st_size;
      list = list->next;
    }
  return (max);
}

unsigned int	my_nbrlen(unsigned int nbr)
{
  unsigned int	i;
  unsigned int	size;

  for (i = 1, size = 1; (nbr / i) >= 10; i *= 10, size++)
    ;
  return (size);
}

 
char			*show_date(time_t date)
{
  char			*otnd;
  char			*tnd;
  unsigned int		i;
  struct timeval	time;

  gettimeofday(&time, NULL);
  otnd = ctime(&date);
  tnd = malloc(my_strlen(otnd));
  if ((time.tv_sec - date > SIX_MONTH) || (time.tv_sec - date < -ONE_HOURE))
    {
      for (i = 4; i < 11; ++i)
	tnd[i - 4] = otnd[i];
      tnd[i - 4] = ' ';
      for (i = 19; i < 24; ++i)
	tnd[i - 12] = otnd[i];
      tnd[i - 6]= '\0';
    }
  else
    {
      for (i = 4; otnd[i - 3] != ':'; ++i)
	tnd[i - 4] = otnd[i];
      tnd[i - 4] = '\0';
    }
  return (tnd);
}

char	*make_filename(char *path, char *filename)
{
  char	*result;
  int	i;

  result = malloc(my_strlen(filename) + my_strlen(path) + 1);
  for (i = 0; *path; ++i)
    result[i] = *path++;
  for (; *filename; ++i)
    result[i] = *filename++;
  result[i] = '\0';
  return (result);
}
  
int	count_sblks(t_list_file *file, int whence)
{
  int	sum;

  sum = 0;
  while (file)
    {
      if ((whence && file->name[0] != '.') || !whence)
	sum += file->sb->st_blocks;
      file = file->next;
    }
  return (sum);
}
