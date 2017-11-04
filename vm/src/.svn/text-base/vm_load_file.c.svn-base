/*
** vm_load_file.c for  in 
** 
** Made by romain bottier
** Login   <bottie_r@epita.fr>
** 
** Started on  Thu Jan  3 16:03:51 2002 romain bottier
** Last update Fri Jan 11 16:04:49 2002 romain bottier
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my_struct.h"
#include "decode.h"
#include "mem.h"
#include "my_defs.h"
#include "my_print_error.h"
#include "my_printf.h"
#include "process.h"
#include "player.h"
#include "register.h"
#include "my_printf.h"
#include "my.h"

void		cor_bzero(unsigned char *str, int size)
{
  int		i;
  
  for (i = 0; i < size; str[i] = 0, i++)
    ;
}

unsigned char	*read_string(int fd, int size)
{
  unsigned char	*buffer;
  
  buffer = my_xmalloc(sizeof (unsigned char) * (size + 1));
  cor_bzero(buffer, size + 1);
  if (read(fd, buffer, size) < size)
    my_print_error("Warning: file corrupted\n");
  return (buffer);
}

int		get_magic_number(int fd)
{
  unsigned char	*buffer;
  unsigned int	res;
  int		i;
  
  buffer = my_xmalloc(sizeof (unsigned char) * 10);
  cor_bzero(buffer, 10);
  if (read(fd, buffer, 4) < 4)
    my_print_error("Warning: file corrupted\n");    
  for (i = res = 0; i < 4; i++)
    {
      res = res << 8;
      res += buffer[3 - i];
    }
  free(buffer);
  return (res);
}


int		get_code_size(int fd)
{
  unsigned char	*buffer;
  unsigned int	res;
  int		i;
  
  buffer = my_xmalloc(sizeof (unsigned char) * 4);
  cor_bzero(buffer, 4);
  if (read(fd, buffer, 4) < 4)
    my_print_error("Warning: file corrupted\n");
  for (i = res = 0; i < 4; i++)
    {
      res = res << 8;
      res += buffer[3 - i];
    }
  free(buffer);
  return (res);
}


int		load_cor_file(t_vm *vm, t_list *filenames)
{
  unsigned char *dotname;
  t_process	*process;
  unsigned int	size;  
  unsigned int	i;
  int		nb_player;
  int		fd;
  short		nbpl;
  
  nbpl = list_size(filenames);
  for (i = 0, size = 0, nb_player = 1; filenames;
       filenames = filenames->next, i += (vm->mem.size / nbpl), nb_player++)
    if ((fd = open(filenames->elem, O_RDONLY, 0666)) > 0)
      {
	if (get_magic_number(fd) != COREWAR_EXEC_MAGIC)
	  error_loading(fd, filenames->elem);
	else
	  {
	    dotname = end_of_loading(vm, fd, i);
	    process = new_process(vm, new_player(vm, nb_player, dotname));
	    _write_register_(vm, process, VAL_PC, i);
	    if (vm->verbose)
	      my_printf("process %s\t\tmapped @ %i\n", dotname, i);
	  }
      }
  return (0);
}
