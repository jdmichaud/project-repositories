/*
** mem.c for vm in ~/c/rendu/projs/corewar/vm
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Nov 28 17:25:11 2001 jean-daniel michaud
** Last update Sat Jan 12 12:24:55 2002 julien gein
*/

#include <stdio.h>

#include "my_print_error.h"
#include "my_defs_err.h"
#include "my_struct.h"
#include "display.h"
#include "player.h"
#include "mem.h"
#include "my.h"

static const unsigned short	wshift[] =
{
  4095,
  61695,
  65295,
  65520
};

static const unsigned short	rshift[] =
{
  61440,
  3840,
  240,
  15
};

/*
** Ecrit les 4 premiers bits de quartet
** a l'adresse memoire addr de la machine vm

** Cette fonction effectue des verifications
** de portee.
** Retoune 0 en cas de reussite.
** Retourne une valeure non nulle en cas d'echec.
*/
int			_write_(t_vm		*vm,
				t_process	*process,
				unsigned int	addr, 
				unsigned short	quartet)
{
  unsigned short	*area;
  unsigned short	mask;
  
  if (addr > vm->mem.size)
    return (1);
  if (vm->interface)
    if (process)
      update_memdpy(vm->mem.size,
		    get_id_from_prid(vm, process->prid), addr, MD_MEM);
  area = vm->mem.area;
  mask = wshift[addr % QSIZE];
  area[addr / QSIZE] &= mask;
  quartet *= my_power(2, ((QSIZE - (addr % QSIZE) - 1) * QSIZE));
  area[addr / QSIZE] |= quartet;
  return (0);
}

/*
** Lit les 4 premiers bits situe a l'adresse
** de la machine vm, et les place dans les
** 4 premiers bits du quartet.

** Cette fonction effectue des verifications
** de portee.
** Retoune 0 en cas de reussite.
** Retourne une valeure non nulle en cas d'echec.
*/
int			_read_(t_vm		*vm,
			       t_process	*process,
			       unsigned int	addr,
			       unsigned short	*quartet)
{
  unsigned short	*area;
  
  if (addr > vm->mem.size)
    return (1);
  area = vm->mem.area;
  *quartet = 0;
  *quartet = area[addr / QSIZE];
  *quartet &= rshift[addr % QSIZE];
  *quartet /= my_power(2, ((QSIZE - (addr % QSIZE)) - 1) * QSIZE);
  return (0);
}

/*
** Ecrit les donnees contenues dans buf
** a l'adresse memoire addr de la machine vm
** (size est en quartet)

** Cette fonction effectue des verifications
** de portee.
** Retoune 0 en cas de reussite.
** Retourne une valeure non nulle en cas d'echec.
*/
int		_write_buffer_(t_vm		*vm, 
			       unsigned int	size,
			       unsigned int	addr, 
			       void		*buf)
{
  unsigned int	i;
  unsigned char	*str;
  unsigned char	c;
  
  if (addr + size > vm->mem.size)
    {
      my_print_error("_write_buffer_:warning, buffer exeed memory capacity\n");
      return (1);
    }
  str = buf;
  for (i = 0; i < (size / 2) + (size % 2); ++i)
    {
      c = str[i];
      c &= 240;
      c /= 16;
      if (vm->interface)
	update_memdpy(vm->mem.size, DARKGREY, (i + (addr / 2)) * 2, MD_MEM);
      _write_(vm, NULL, (i + (addr / 2)) * 2, c);
      c = str[i];
      c &= 15;
      if (vm->interface)
	update_memdpy(vm->mem.size,
		      DARKGREY, ((i + (addr / 2)) * 2) + 1, MD_MEM);
      _write_(vm, NULL, ((i + (addr / 2)) * 2) + 1, c);
    }
  return (0);
}

/*
** lit les donnees a l'adresse memoire addr
** de la machine vm est les copies dans buf
** (size est en quartet)

** Cette fonction effectue des verifications
** de portee.
** Retoune 0 en cas de reussite.
** Retourne une valeure non nulle en cas d'echec.
*/
int	_read_buffer_(t_vm		*vm,
		      unsigned int	addr,
		      unsigned int	size,
		      void		*buf)
{
  if (addr + size > vm->mem.size)
    return (1);
  
  return (0);
}



