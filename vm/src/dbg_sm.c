/*
** dbg_sm.c for  in 
** 
** Made by romain bottier
** Login   <bottie_r@epita.fr>
** 
** Started on  Thu Jan 10 21:52:03 2002 romain bottier
** Last update Fri Jan 11 17:15:53 2002 GIZMO
*/

#include <unistd.h>
#include "my_struct.h"
#include "dbg_cmd.h"
#include "my.h"
#include "my_print_error.h"

void		dbg_sm(t_vm *vm, t_list *args)
{
  unsigned int	tab[2];
  
  if (args)
    {
      tab[0] = my_atoi(args->elem);
      if (args->next && my_atoi(args->next->elem) < vm->mem.size)
	tab[1] = my_atoi(args->next->elem);
      else
	tab[1] = vm->mem.size;
    }
  else
    {
      tab[0] = 0;
      tab[1] = vm->mem.size;
    }
  dbg_sm_exe(vm, tab[0], tab[1]);
}

void		dbg_sm_exe(t_vm *vm,
			   unsigned int start_mem,
			   unsigned int end_mem)
{
  char		*str;
  char		c;
  unsigned int	cpt;
  unsigned int	i;

  str = vm->mem.area;
  cpt = 0;
  for (i = start_mem; i <= end_mem; i++)
    {
      if (cpt > 15)
	{
	  write(1, "\n", 1);
	  cpt = 0;
	}
      ++cpt;
      c = str[i];
      c &= 240;
      c /= 16;
      my_printnbr_base_sm(c, "0123456789ABCDEF");
      c = str[i];
      c &= 15;
      my_printnbr_base_sm(c, "0123456789ABCDEF");
      write(1, " ", 1);
    }
  write(1, "\n", 1);
}

void    my_printnbr_base_sm(int nbr, char *base)
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
    my_printnbr_base_dump(1, nbr, base);
  write(1, &base[position], 1);
}
