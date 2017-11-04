/*
** vm_load_map.c for  in 
** 
** Made by 
** Login   <bottie_r@epita.fr>
** 
** Started on  Thu Jan  3 23:56:40 2002 
** Last update Fri Jan 11 16:05:50 2002 romain bottier
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_struct.h"
#include "decode.h"
#include "my.h"
#include "my_print_error.h"
#include "player.h"
#include "process.h"

unsigned char	*pname(t_vm *vm, t_process *process)
{
  t_player	*pl;
  unsigned char *ptr;
  
  pl = get_player_from_prid(vm, process->prid);
  ptr = pl->name;
  return (ptr);
}

void		error_loading(int fd, void *filename)
{
  my_print_error("Le fichier %s n'est pas executable.\n", filename);
  close(fd);
}

unsigned char		*vm_load_map(int fd, int code_size)
{
  unsigned char		*buffer;
  int			nb_octets;
  
  nb_octets = (code_size / 2) + (code_size % 2);
  buffer = my_xmalloc(sizeof (char) * nb_octets);
  cor_bzero(buffer, nb_octets);
  if (read(fd, buffer, nb_octets) < nb_octets)
    my_print_error("Warning: file corrupted\n");
  return (buffer);
}
