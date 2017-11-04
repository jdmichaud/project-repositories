/*
** decode.h for  in 
** 
** Made by romain bottier
** Login   <bottie_r@epita.fr>
** 
** Started on  Sat Jan  5 22:04:23 2002 romain bottier
** Last update Fri Jan 11 16:07:52 2002 romain bottier
*/

#ifndef DECODE_H_
# define DECODE_H_

/*
** functions in vm_load_file.c && vm_load_file2.c
*/
void		cor_bzero(unsigned char *str, int size);
unsigned char	*read_string(int fd, int size);
int		get_magic_number(int fd);
int		get_code_size(int fd);
int		load_cor_file(t_vm *vm, t_list *filenames);
unsigned char	*end_of_loading(t_vm *vm, int fd, int i);

/*
** functions in vm_load_map.c
*/
void		error_loading(int fd, void *filename);
unsigned char	*vm_load_map(int fd, int code_size);
unsigned char	*pname(t_vm *vm, t_process *process);

/*
** functions in dc_decode_instr.c
*/
int		dc_lp(t_vm *vm, t_process *process);
int		dc_bnz(t_vm *vm, t_process *process);
int		dc_ld(t_vm *vm, t_process *process);
int	       	get_inst(t_vm *vm, t_process *process);
int	       	cycle_instr(t_vm *vm, t_process *process);

/*
** functions in dc_decode_instr2.c
*/
int		dc_st(t_vm *vm, t_process *process);
int		dc_lc(t_vm *vm, t_process *process);
int		dc_ll(t_vm *vm, t_process *process);
int		dc_live(t_vm *vm, t_process *process);
int		dc_die(t_vm *vm, t_process *process);

/*
** functions in dc_little_endian.c
*/
int		little_endian2(char *tab);
int		little_endian4(char *tab);

/*
** functions in dc_op1.c
*/
int    		dc_op1_d1(t_vm *vm, t_process *process, unsigned short reg[2]);
int    		dc_op1_d2(t_vm *vm, t_process *process, unsigned short reg[2]);
int	       	dc_op1(t_vm *vm, t_process *process);

/*
** functions in dc_op2.c
*/
int		dc_fork(t_vm *vm, t_process *process);
int	       	dc_type1(t_vm *vm, t_process *process, unsigned short id);
int	       	dc_type2(t_vm *vm, t_process *process, unsigned short id);
int	       	dc_op2_d1(t_vm *vm, t_process *process);
int	       	dc_op2(t_vm *vm, t_process *process);


/*
** functions in vm_op3.c
*/
int		dc_fork(t_vm *vm, t_process *process);
int		dc_push(t_vm *vm, t_process *process, unsigned short id);
int		dc_pop(t_vm *vm, t_process *process, unsigned short id);
int		dc_jmp(t_vm *vm, t_process *process, unsigned short id);
int		dc_write(t_vm *vm, t_process *process, unsigned short id);

/*
** functions in vm_op4.c
*/
int		dc_not(t_vm *vm, t_process *process, unsigned short reg[2]);
int		dc_swp(t_vm *vm, t_process *process, unsigned short reg[2]);
int		dc_mov(t_vm *vm, t_process *process, unsigned short reg[2]);
int		dc_stat(t_vm *vm, t_process *process, unsigned short value[2]);
int		dc_fl(t_vm *vm, t_process *process, unsigned short value[2]);

/*
** functions in vm_op5.c
*/
int		dc_add(t_vm *vm, t_process *process, unsigned short reg[2]);
int		dc_rol(t_vm *vm, t_process *process, unsigned short reg[2]);
int		dc_xor(t_vm *vm, t_process *process, unsigned short reg[2]);
int		dc_and(t_vm *vm, t_process *process, unsigned short reg[2]);
int		dc_or(t_vm *vm, t_process *process, unsigned short reg[2]);

/*
** functions in vm_op6.c
*/
int		dc_lsr(t_vm *vm, t_process *process, unsigned short reg[2]);
int		dc_lsl(t_vm *vm, t_process *process, unsigned short reg[2]);
int		dc_asr(t_vm *vm, t_process *process, unsigned short reg[2]);
int		dc_sub(t_vm *vm, t_process *process, unsigned short reg[2]);
int		dc_bz(t_vm *vm, t_process *process);

/*
** functions in vm_op7.c
*/
int		dc_rsb(t_vm *vm, t_process *process, unsigned short reg[2]);
int		dc_neg(t_vm *vm, t_process *process, unsigned short reg[2]);
int		dc_inc(t_vm *vm, t_process *process, unsigned short reg[2]);
int		dc_dec(t_vm *vm, t_process *process, unsigned short reg[2]);

/*
** functions in cycle.c
*/
void		make_delay(t_process *process, int delay);
void		check_state_vm(t_vm *vm, t_process *process);

/*
** functions in dbg_call.c
*/
int		have_to_debug(t_vm *vm, unsigned int prid);
int		debug_call(t_vm *vm, t_process *process);

#endif /* DECODE_H_ */
