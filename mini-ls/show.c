/*
** show.c for mini-ls in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Fri Nov 16 09:07:50 2001 jean-daniel michaud
** Last update Tue Nov 20 02:06:12 2001 jean-daniel michaud
*/

#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "get_option.h"
#include "list_file.h"
#include "show.h"
#include "my_strcmp.h"
#include "my_printf.h"
#include "utils.h"
#include "get_type.h"

void		show(t_list_file *list, int option)
{
  if ((option & HIDE_FILE) || (option & NO_SPEC_DIR))
    show_hide(list, option);
  else
    show_no_hide(list, option);
}    

void		show_hide(t_list_file *list, int option)
{
  t_list_file	*file;
  unsigned int	max;

  file = list;
  max = get_max_size(file);
  if ((option & LONG_FORMAT) && is_directory(list->name))
    my_printf("total %i\n", count_sblks(list, 0));
  while (file)
    {
      if ((option & NO_SPEC_DIR) && (!(option & HIDE_FILE)))
	{
	  if (my_strcmp(file->name, ".") && my_strcmp(file->name, ".."))
	    show_file(file, option, max);
	}
      else
	show_file(file, option, max);
      file = file->next;
    }
}

void		show_no_hide(t_list_file *list, int option)
{
  t_list_file	*file;
  unsigned int	max;

  file = list;
  if ((option & LONG_FORMAT) && is_directory(list->name))
    my_printf("total %i\n", count_sblks(list, 1));
  max = get_max_size(file);
  while (file)
    {
      if (file->name[0] != '.')
	show_file(file, option, max);
      file = file->next;
    }
}
	  
void		show_file(t_list_file *file, int option, unsigned int max)
{
  unsigned int	i;
  char		*tmp;
  char		link[1024];

  if (!(option & LONG_FORMAT))
    my_printf("%s\n", file->name);
  else
    {
      show_right(file->sb->st_mode);
      my_printf("%i %s  %s", file->sb->st_nlink, file->owner, file->group);
      for (i = 0; i < (my_nbrlen(max) - my_nbrlen(file->sb->st_size) + 2); ++i)
	my_printf(" ");
      tmp = show_date(file->sb->st_mtime);
      my_printf("%i ", file->sb->st_size);
      my_printf("%s ", tmp);
      my_printf("%s ", file->name); 
      if ((file->sb->st_mode & S_IFMT) == S_IFLNK)
	{
	  link[readlink(make_filename(file->path, file->name), 
			link, 1023)] = '\0';
	  my_printf("-> %s", link);
	}
      my_printf("\n");
      free(tmp);
    }
}

void	show_right(mode_t mode)
{
  char	*str;

  str = malloc(11 * sizeof (char));
  str[0] = ((mode & S_IFMT) == S_IFDIR) ? 'd' : '-';
  if ((mode & S_IFMT) == S_IFCHR)
    str[0] = 'c';
  if ((mode & S_IFMT) == S_IFLNK)
    str[0] = 'l';
  if ((mode & S_IFMT) == S_IFBLK)
    str[0] = 'b';
  str[1] = (mode & S_IRUSR) ? 'r' : '-';
  str[2] = (mode & S_IWUSR) ? 'w' : '-';
  str[3] = (mode & S_IXUSR) ? 'x' : '-';
  str[4] = (mode & S_IRGRP) ? 'r' : '-';
  str[5] = (mode & S_IWGRP) ? 'w' : '-';
  str[6] = (mode & S_IXGRP) ? 'x' : '-';
  str[7] = (mode & S_IROTH) ? 'r' : '-';
  str[8] = (mode & S_IWOTH) ? 'w' : '-';
  str[9] = (mode & S_IXOTH) ? 'x' : '-';
  str[10] = '\0';
  my_printf("%s  ", str);
  free(str);
}
