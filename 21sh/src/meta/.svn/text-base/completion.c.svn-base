/*
** completion.c
** 
** Made by (Florent Monbillard)
** Login   <monbil_f@epita.fr>
** 
** Started on  Sun Dec 30 18:42:03 2001 Florent Monbillard
** Last update Mon Dec 31 03:36:36 2001 Florent Monbillard
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include "meta.h"
#include "match.h"
#include "size.h"
#include "xmalloc.h"
#include "completion.h"

unsigned int	get_nb_files_in_dir(char *path)
{
  struct dirent *file;
  DIR *		directory;
  unsigned int	size;

  directory = opendir(path);
  for (size = 0; directory && (file = readdir(directory)); )
    if ((strcmp(file->d_name, ".")) && (strcmp(file->d_name, "..")))
      ++size;
  return (size);
}

char		**get_filelist()
{
  struct dirent *file;
  DIR *		directory;
  char		**result;
  char		*path;
  int		i;
  int		tabsize;
  int		size;
  
  path = getcwd(NULL, 255);
  tabsize = get_nb_files_in_dir(path);
  result = xmalloc((tabsize + 1) * sizeof (char *));
  directory = opendir(path);
  for (i = 0; directory && (file = readdir(directory)); )
    if ((strcmp(file->d_name, ".")) && (strcmp(file->d_name, "..")))
      {
	size = strlen(file->d_name);
	result[i] = xmalloc((size + 1) * sizeof (char));
	bcopy(file->d_name, result[i], size);
	result[i++][size] = '\0';
      }
  result[i] = NULL;
  return (result);
}

int	completion(char *string, char *pattern)
{
  int	test;

  while (*string && *pattern && (test = is_equal(string, pattern)))
    {
      if (test == 2)
	++pattern;
      ++pattern;
      ++string;
    }
  if (!(*pattern))
    return (1);
  if (*pattern == '*')
    return (got_a_star(string, pattern, completion));
  if (*pattern == '?')
    return (got_an_ip(string, pattern, completion));
  if (*pattern == '[')
    return (got_a_bracket(string, pattern + 1, completion));
  if (*pattern == '{')
    return (got_a_braces(string, pattern + 1, completion));
  return (0);
}

char	**get_completion(char *pattern)
{
  char	**result;
  char	**filelist;
  int	i;
  int	j;
  int	size;
  
  result = NULL;
  filelist = get_filelist();
  for (i = 0, j = 0; filelist && filelist[i]; ++i)
    {
      if (completion(filelist[i], pattern))
	{
	  if (!result)
	    result = xmalloc((get_tabsize(filelist) + 1) * sizeof (char *));
	  size = strlen(filelist[i]);
	  result[j] = xmalloc((size + 1) * sizeof (char));
	  bcopy(filelist[i], result[j], size);
	  result[j++][size] = '\0';
	}
    }
  if (result)
    result[j] = NULL;
  return (result);
}
