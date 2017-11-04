/*
** write.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Jan  3 14:40:00 2002 GIZMO
** Last update Sat Jan 12 12:27:37 2002 julien gein
*/

#include <unistd.h>
#include "my.h"
#include "my_struct.h"
#include "my_print_error.h"
#include "op.h"
#include "process.h"
#include "register.h"

/*
** write rx
** write : Ecrit sur la sortie standard le caractère contenu dans les
** 2 quartets de poids faible de rx.
** Le fonctionnement est indépedendant de P et n'affecte pas Z.
*/

void			my_write(t_vm		*v,
				 unsigned int	prid,
				 unsigned short	rx)
{
  t_process		*pr;
  unsigned short	reg_rx;
  unsigned short	mask;
  unsigned char		c;
  
  pr = get_process(v, prid);
  _read_register(v, pr, rx, &reg_rx);
  if (v->verbose)
    my_print_error("[%i]\t--> WRITE r%i <--\n", prid, rx);
  mask = my_power(2, 8) - 1;
  c = reg_rx & mask;
  write(1, &c, 1);
}
