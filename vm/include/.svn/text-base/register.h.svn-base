/*
** register.h for vm in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Jan  3 14:54:15 2002 jean-daniel michaud
** Last update Tue Jan  8 14:32:38 2002 jean-daniel michaud
*/

#ifndef REGISTER_H_
# define REGISTER_H_


/*
** Compatibilite
*/

# define _write_register	_write_register_
# define _read_register		_read_register_


/*
** reg <-> 0 - 15
** PC  <-> 16
** Z   <-> 17
** P   <-> 18
*/

int	_write_register(t_vm		*vm,
			t_process	*process, 
			unsigned short	reg, 
			unsigned short	quad);
int	_read_register(t_vm		*vm,
		       t_process	*process, 
		       unsigned short	reg, 
		       unsigned short	*quad);
void	upt_interface(t_vm		*vm,
		      t_process		*process, 
		      unsigned short	reg, 
		      unsigned short	quad);

#endif /* !REGISTER_H_ */
