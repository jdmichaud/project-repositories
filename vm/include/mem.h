/*
** mem.h for vm in ~/c/rendu/projs/corewar/vm
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Nov 28 17:36:47 2001 jean-daniel michaud
** Last update Sun Jan  6 12:36:25 2002 jean-daniel michaud
*/

#ifndef	MEM_H_
# define MEM_H_

int	_write_(t_vm		*vm,
		t_process	*process,
		unsigned int	addr,
		unsigned short	quartet);
int	_read_(t_vm		*vm,
	       t_process	*process,
	       unsigned int	addr,
	       unsigned short	*quartet);
int	_write_buffer_(t_vm		*vm,
		       unsigned int	size,
		       unsigned int	addr, 
		       void		*buf);
int	_read_buffer_(t_vm		*vm,
		      unsigned int	addr,
		      unsigned int	size,
		      void		*buf);

#endif /* !MEM_H_ */
