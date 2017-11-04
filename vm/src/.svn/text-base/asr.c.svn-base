/*
** asr.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Nov 29 15:33:12 2001 GIZMO
** Last update Thu Jan 10 15:18:38 2002 GIZMO
*/

#include "my.h"
#include "my_struct.h"
#include "my_print_error.h"
#include "op.h"
#include "process.h"
#include "register.h"

/*
** asr rx, n
** arithmetic shift right : Effectue un décalage arithmétique à droite
** de n bits des quartets 0 à P de rx. Ce décalage a pour caractéristique
** de faire entrer des bits identiques au bit de signe (conservation du signe).
*/

void			asr(t_vm		*v,
			    unsigned int	prid,
			    unsigned short	rx,
			    unsigned short	n)
{
  t_process		*pr;
  unsigned short	reg_p;
  unsigned short	reg_rx;
  unsigned short	mask;
  unsigned short	tmp;
  unsigned short	mask_deca;
  unsigned short	sign_bit;
  unsigned short	i;
  
  pr = get_process(v, prid);
  _read_register(v, pr, VAL_P, &reg_p);
  _read_register(v, pr, rx, &reg_rx);
  if ((mask = my_power(2, (reg_p + 1) * QSIZE) - 1) && v->verbose)
    my_print_error("[%i]\t--> ASR r%i, %i <-- P=%d\n", prid, rx, n, reg_p);
  tmp = reg_rx & mask;
  sign_bit = ((reg_rx & 32768) == 32768 ? 1 : 0);
  for (mask_deca = my_power(2, n) - 1, i = 1; sign_bit > 0 && i <= n; i++)
    sign_bit += my_power(2, i);
  tmp &= ~mask_deca;
  tmp = tmp >> n;
  tmp |= (sign_bit = sign_bit << (QSIZE * (reg_p + 1) - n));
  update_reg_z(v, pr, tmp);
  reg_rx &= ~mask;
  reg_rx |= tmp;
  _write_register(v, pr, rx, reg_rx);
}
