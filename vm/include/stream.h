/*
** stream.h for vm in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sun Jan  6 09:32:25 2002 jean-daniel michaud
** Last update Thu Jan 10 08:52:11 2002 jean-daniel michaud
*/

#ifndef STREAM_H_
# define STREAM_H_

typedef struct		s_write_op
{
  t_process		*process;
  unsigned int		addr;
  unsigned short	quartet;
}			t_write_op;

int			bwrite(t_vm		*vm,
			       t_process	*process,
			       unsigned int	addr,
			       unsigned short	quartet);
int			_flush(t_vm *vm);
int			resolve(t_vm *vm);
int			vote(t_vm *vm, t_dlist *lcandidate);
unsigned short		elect(short		urn[2],
			      unsigned short	mask,
			      unsigned short	actual);

#endif
