/*
** dbg_dump.c for  in 
** 
** Made by romain bottier
** Login   <bottie_r@epita.fr>
** 
** Started on  Wed Jan  9 23:45:00 2002 romain bottier
** Last update Fri Jan 11 17:16:04 2002 GIZMO
*/

#include <fcntl.h>
#include <unistd.h>
#include "my_struct.h"
#include "dbg_cmd.h"
#include "my.h"
#include "my_print_error.h"

void	dbg_dump(t_vm *vm, t_list *args)
{
  if (args->elem)
    dbg_dump_exe(vm, args->elem);
  else
    my_print_error("No output-file selected.\n");
}

void	dbg_dump_exe(t_vm *vm, char *filename)
{
  int	fd;
  
  fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
  if (fd != -1)
    {
      my_showmem_dump(fd, vm);
      close(fd);
    }
  else
    my_print_error("Dump cannot be write into the file \"%s\".\n", filename);
}

void		my_showmem_dump(int fd, t_vm *vm)
{
  char		*str;
  char		c;
  unsigned int	cpt;
  unsigned int	i;

  str = vm->mem.area;
  cpt = 0;
  for (i = 0; i < vm->mem.size; ++i)
    {
      if (cpt > 15)
	{
	  write(fd, "\n", 1);
	  cpt = 0;
	}
      ++cpt;
      c = str[i];
      c &= 240;
      c /= 16;
      my_printnbr_base_dump(fd, c, "0123456789ABCDEF");
      c = str[i];
      c &= 15;
      my_printnbr_base_dump(fd, c, "0123456789ABCDEF");
      write(fd, " ", 1);
    }
  write(fd, "\n", 1);
}

void    my_printnbr_base_dump(int fd, int nbr, char *base)
{
  int	len;
  int	position;
  
  if (nbr < 0)
    nbr = -nbr;
  len = 0;
  while (base[len] != '\0')
    len++;
  position = nbr % len;
  nbr = nbr / len;
  if (nbr != 0)
    my_printnbr_base_dump(fd, nbr, base);
  write(fd, &base[position], 1);
}
