/*
** my_struct.h for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Tue Oct 30 17:30:06 2001 GIZMO
** Last update Fri Jan 11 19:31:30 2002 jean-daniel michaud
*/

#ifndef MY_STRUCT_H_
# define MY_STRUCT_H_

# include "my_defs.h"
# include "data_struct.h"
# include "dlist.h"

typedef enum		e_state
{
  DECODE = 1,
  DELAY = 2,
  EXECUTE = 3
}			t_state;

typedef struct		s_process
{
  unsigned short	regs[18];
  unsigned short	stack[16];
  unsigned short	stack_pos;
  short			is_die;
  short			ctw;
  short			ctd;
  unsigned int		prid;
  char			instr[6];
  unsigned short	cpt;
  unsigned short	nb_call;
  t_state		state;
}			t_process;

typedef struct	s_mem_area
{
  void		*area;
  unsigned int	size;
}		t_mem_area;

typedef struct	s_player
{
  short		id;
  unsigned char	*name;
  unsigned long	live_cycle;
  t_dlist	*die;
  t_list	*forks;
  t_dlist	*process;
}		t_player;

typedef struct		s_vm
{
  t_dlist		*list_player;
  t_mem_area		mem;
  int			max_proc;
  int			idx_mod;
  int			ctd;
  int			nbr_live;
  int			cycle_delta;
  short			is_trace;
  short			interface;
  short			in_debug;
  int			cst_nbr_live;
  unsigned long		cpt_cycles;
  unsigned short	follow_id;
  unsigned short	follow_prid;
  unsigned short	follow_rg;
  short			verbose;
  short			dec_ctd;
  unsigned int		dbg_lvl;
  unsigned int		dbg_cycle;
  unsigned int		delay;
}			t_vm;

#endif /* !MY_STRUCT_H_ */
