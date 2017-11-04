/*
** get_buffer.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Mon Nov 26 12:43:40 2001 julien gein
** Last update Fri Jan 11 11:36:38 2002 julien gein
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "display.h"
#include "my.h"
#include "my_print_error.h"

char	*my_get_expr(int fd)
{
  char	*buff;
  char	*expr;
  char	*expr_old;  
  int	nb_char_read;
  int	n;
  
  nb_char_read = READ_SIZE;
  buff = xmalloc(sizeof (char) * (READ_SIZE + 1));
  for (n = 1, expr_old = 0; nb_char_read == READ_SIZE; n++)
    {
      nb_char_read = read(fd, buff, READ_SIZE);
      expr = xmalloc(sizeof (char) * (n * READ_SIZE + 1));
      if (expr_old)
	{
	  my_strcpy(expr, expr_old);
	  free(expr_old);
	}
      if (nb_char_read) 
	my_strcpy(expr + (n - 1) * READ_SIZE, buff);
      expr_old = expr;
    }
  expr[(n - 2) * READ_SIZE + nb_char_read] = '\0';
  return (expr);
}

char		*get_line(char **buff)
{
  unsigned int	i;
  char		*res;
  char		*save;
  
  for (save = *buff, i = 0; **buff && **buff != '\n'; i++, (*buff)++)
    ;
  if (i == 0 && **buff == '\0')
    return (0);
  (*buff)++;
  res = xmalloc(sizeof (char) * (i + 1));
  res = my_strncpy(res, save, i);
  res[i] = '\0';
  return (res);
}

t_list		*erase_comment(t_list *src)
{
  t_list	*tmp;
  char		*line;
  char		*new_line;
  char		*save;
  t_list	*res;
  unsigned int	length;
  
  for (res = 0, tmp = src; tmp; tmp = tmp->next)
    {
      line = tmp->elem;
      for (length = 0, save = line; *line && *line != '#'; line++, length++)
	;
      if (length != 0)
	{
	  new_line = xmalloc(sizeof (char) * (length + 1));
	  my_strncpy(new_line, save, length);
	  new_line[length] = '\0';
	  list_append(&res, new_line);
	}
      free(save);
    }
  return (res);
}

t_list		*init_file_buff(char *path)
{
  int		file;
  char		*buff;
  t_list	*list;
  char		*line;
  char		*save;
  
  file = open(path, O_RDONLY, 0);
  if (file == -1)
    {
      my_print_error("Can't open file \'%s\'\n", path);
      return (0);
    }
  save = buff = my_get_expr(file);
  list = 0;
  while ((line = get_line(&buff)))
    list_append(&list, line);
  free(save);
  return (erase_comment(list));
  close(file);
}


