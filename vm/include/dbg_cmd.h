/*
** dbg_cmd.h for  in 
** 
** Made by romain bottier
** Login   <bottie_r@epita.fr>
** 
** Started on  Thu Jan 10 00:05:06 2002 romain bottier
** Last update Sat Jan 12 12:53:38 2002 julien gein
*/

#ifndef DBG_CMD_H_
# define DBG_CMD_H_

void	dbg_dump(t_vm *vm, t_list *args);
void	dbg_help(t_vm *v, t_list *args);
void	dbg_info(t_vm *v, t_list *args);
void	dbg_list_child(t_vm *v, t_list *args);
void	dbg_next(t_vm *v, t_list *args);
void	dbg_player(t_vm *v, t_list *args);
void	dbg_print_solo(t_vm *v, t_list *args);
void	dbg_print(t_vm *v, t_list *args);
void	dbg_purchase(t_vm *v, t_list *args);
void	dbg_quit(t_vm *v, t_list *args);
void	dbg_sm(t_vm *vm, t_list *args);


void	dbg_dump_exe(t_vm *vm, char *filename);
void	dbg_sm_exe(t_vm *vm, unsigned int start_mem,
		   unsigned int end_mem);
void	my_showmem_dump(int fd, t_vm *vm);
void	my_printnbr_base_dump(int fd, int nbr, char *base);
void	my_printnbr_base_sm(int nbr, char *base);

void	wait_for_cmd(t_vm *v, t_player *p);
char    *readcmd(void);
void	show_prompt(void);

void	print_all_regs(t_vm *v, unsigned int prid);
void	print_reg(t_vm *v, int reg, int prid);
int	parse_reg(char *arg);

#endif /* DBG_CMD_H_ */
