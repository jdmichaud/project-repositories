/*
** vm_load_file2.c for  in 
** 
** Made by romain bottier
** Login   <bottie_r@epita.fr>
** 
** Started on  Thu Jan 10 19:16:43 2002 romain bottier
** Last update Fri Jan 11 16:07:53 2002 romain bottier
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

unsigned char	*end_of_loading(t_vm *vm, int fd, int i)
{
  unsigned int	size;
  unsigned char	*dotname;
  unsigned char	*dotcomment;

  size = get_code_size(fd);
  dotname = read_string(fd, PROG_NAME_LENGTH);
  dotcomment = read_string(fd, PROG_COMMENT_LENGTH); 
  free(dotcomment);
  _write_buffer_(vm, size, i, vm_load_map(fd, size));
  close(fd);
  return (dotname);
}
