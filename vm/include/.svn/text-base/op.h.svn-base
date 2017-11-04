/*
** op.h for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Jan  3 14:54:49 2002 GIZMO
** Last update Sat Jan 12 12:47:23 2002 julien gein
*/

#ifndef OP_H_
# define OP_H_

unsigned short	copy_reg(unsigned short		reg_src,
			 unsigned short		reg_dst,
			 unsigned short		reg_p);
void		update_reg_z(t_vm		*v,
			     t_process		*pr,
			     unsigned short	val);
void		flush_die(t_vm			*v);
void		flush_fork(t_vm			*v);
void		do_fork(t_vm			*v,
			t_player		*p);
void		put_info(t_vm			*v,
			 unsigned int		prid,
			 unsigned short		rx,
			 unsigned short		n);
void		fl_print_debug(t_vm		*v,
			       unsigned int	prid,
			       unsigned short	rx,
			       unsigned short	ry);
void		ld_print_debug(t_vm		*v,
			       unsigned int	prid,
			       unsigned short	rx,
			       unsigned short	ry);
void		st_print_debug(t_vm		*v,
			       unsigned int	prid,
			       unsigned short	rx,
			       unsigned short	ry);


/* -------------- Instruction of kasm -------------- */
void	die(t_vm		*vm,
	    unsigned int	prid);
void	live(t_vm		*v,
	     unsigned int	prid,
	     unsigned short	n);
void	mov(t_vm		*v,
	    unsigned int	prid,
	    unsigned short	rx,
	    unsigned short	ry);
void	swp(t_vm		*v,
	    unsigned int	prid,
	    unsigned short	rx,
	    unsigned short	ry);
void	not(t_vm		*v,
	    unsigned int	prid,
	    unsigned short	rx,
	    unsigned short	ry);
void	and(t_vm		*v,
	    unsigned int	prid,
	    unsigned short	rx,
	    unsigned short	ry);
void	or(t_vm			*v,
	   unsigned int		prid,
	   unsigned short	rx,
	   unsigned short	ry);
void	xor(t_vm		*v,
	    unsigned int	prid,
	    unsigned short	rx,
	    unsigned short	ry);
void	rol(t_vm		*v,
	    unsigned int	prid,
	    unsigned short	rx,
	    unsigned short	n);
void	asr(t_vm		*v,
	    unsigned int	prid,
	    unsigned short	rx,
	    unsigned short	n);
void	add(t_vm		*v,
	    unsigned int	prid,
	    unsigned short	rx,
	    unsigned short	ry);
void	sub(t_vm		*v,
	    unsigned int	prid,
	    unsigned short	rx,
	    unsigned short	ry);
void	rsb(t_vm		*v,
	    unsigned int	prid,
	    unsigned short	rx,
	    unsigned short	ry);
void	neg(t_vm		*v,
	    unsigned int	prid,
	    unsigned short	rx,
	    unsigned short	ry);
void	inc(t_vm		*v,
	    unsigned int	prid,
	    unsigned short	rx,
	    unsigned short	n);
void	dec(t_vm		*v,
	    unsigned int	prid,
	    unsigned short	rx,
	    unsigned short	n);
void	lsl(t_vm		*v,
	    unsigned int	prid,
	    unsigned short	rx,
	    unsigned int	n);
void	lsr(t_vm		*v,
	    unsigned int	prid,
	    unsigned short	rx,
	    unsigned int	n);
void	lp(t_vm			*v,
	   unsigned int		prid,
	   unsigned short	n);
void	bnz(t_vm		*v,
	    unsigned int	prid,
	    unsigned short	rx);
void	bz(t_vm			*v,
	   unsigned int		prid,
	   unsigned short	rx);
void	ld(t_vm			*v,
	   unsigned int		prid,
	   unsigned short	rx,
	   unsigned short	ry);
void	st(t_vm			*v,
	   unsigned int		prid,
	   unsigned short	rx,
	   unsigned short	ry);
void	lc(t_vm			*vm,
	   unsigned int		prid,
	   unsigned short	rx,
	   short		n);
void	ll(t_vm			*v,
	   unsigned int		prid,
	   unsigned short	rx,
	   unsigned short	n);
void	my_fork(t_vm		*v,
		unsigned int	prid);
void	push(t_vm		*v,
	     unsigned int	prid,
	     unsigned short	rx);
void	pop(t_vm		*v,
	    unsigned int	prid,
	    unsigned short	rx);
void	jmp(t_vm		*v,
	    unsigned int	prid,
	    unsigned short	rx);
void	fl(t_vm			*v,
	   unsigned int		prid,
	   unsigned short	rx,
	   unsigned short	ry);
void	my_write(t_vm		*v,
		 unsigned int	prid,
		 unsigned short	rx);
void	my_stat(t_vm		*v,
		unsigned int	prid,
		unsigned short	rx,
		unsigned short	n);

unsigned int	dlist_rm_process(t_vm *v, unsigned int prid);
unsigned short	is_virtualy_alive(t_player *player);
unsigned int	process_free(t_process **process, t_dlist **tmp);

#endif /* OP_H_ */
