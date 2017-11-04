/*
** get_next_line.c for get_next_line in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Oct  6 20:05:58 2001 jean-daniel michaud
** Last update Sun Oct  7 15:19:26 2001 jean-daniel michaud
*/

#include "get_next_line.h"

void		my_free(void *tmp)
{
  if (tmp);
}

char		*update(char *buf)
{
  for (; ((*buf != '\n') && (*buf != '\0')); ++buf)
    ;
  ++buf;
  return (buf);
}

char		*get_next_line(int fd)
{
  static char		*buf;
  char		*tmp;
  char		*tmp2;
  unsigned int	i;

  tmp2 = NULL;
  while (need_read(buf))
    {
      tmp = buf;
      if ((buf = read_block(fd)) == NULL)
	return (tmp2);
      i = my_strlen_cr(tmp2);
      tmp2 = my_realloc_str(tmp2, my_strlen_cr(tmp));
      my_strcpy_cr(&tmp2[i], tmp);
      my_free(tmp);
    }
  i = my_strlen_cr(tmp2);
  tmp2 = my_realloc_str(tmp2, my_strlen_cr(buf));
  my_strcpy_cr(&tmp2[i], buf);
  buf = update(buf);
  return (tmp2);
}
