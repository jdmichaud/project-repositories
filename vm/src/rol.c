/*
** rol.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Nov 29 15:29:23 2001 GIZMO
** Last update Thu Jan 10 16:26:49 2002 GIZMO
*/

#include "my.h"
#include "my_struct.h"
#include "my_print_error.h"
#include "op.h"
#include "process.h"
#include "register.h"

unsigned short		rol_pos(unsigned short	tmp,
				unsigned short	reg_p,
				unsigned short	n);

/*
** rol rx, n
** rotate left : Effectue une rotation vers la gauche de n bits des
** quartets 0 à P de rx. L'instruction ror qui effectue une rotation à
** droite n'existe pas car on peut la simuler grace à un rol avec une valeur
** appropriée de n.
*/ 

void			rol(t_vm		*v,
			    unsigned int	prid,
			    unsigned short	rx,
			    unsigned short	n)
{
  t_process		*pr;
  unsigned short	reg_p;
  unsigned short	reg_rx;
  unsigned short	mask;
  unsigned short	tmp;
  
  pr = get_process(v, prid);
  _read_register(v, pr, VAL_P, &reg_p);
  _read_register(v, pr, rx, &reg_rx);
  if (v->verbose)
    my_print_error("[%i]\t--> ROL r%i, %i <-- P=%d\n",
		   prid, rx, n, reg_p);
  mask = my_power(2, (reg_p + 1) * QSIZE) - 1;
  tmp = reg_rx & mask;
  reg_rx &= ~mask;
  reg_rx |= (mask = rol_pos(tmp, reg_p, n));
  update_reg_z(v, pr, mask);
  _write_register(v, pr, rx, reg_rx);
}

unsigned short		rol_pos(unsigned short	tmp,
				unsigned short	reg_p,
				unsigned short	n)
{
  unsigned short	mask_deca;
  unsigned short	bits_to_deca;
  unsigned short	i;
  unsigned short	bit;
  
  mask_deca = my_power(2, n) - 1;
  mask_deca = mask_deca << (QSIZE * (reg_p + 1) - n);
  bits_to_deca = (tmp & mask_deca) >> (QSIZE * (reg_p + 1) - n);
  tmp &= ~mask_deca;
  for (i = 0; i < n; i++)
    {
      bit = ((tmp & (8 * my_power(2, reg_p * QSIZE))) ==
	     (8 * my_power(2, reg_p * QSIZE)) ? 1 : 0);
      tmp = (tmp << 1);
      tmp |= bit;
    }
  tmp &= my_power(2, (reg_p + 1) * QSIZE) - 1;
  tmp |= bits_to_deca;
  return (tmp);
}
