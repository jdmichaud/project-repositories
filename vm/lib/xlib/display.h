/*
** vm_display.h for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Fri Jan  4 14:48:38 2002 julien gein
** Last update Sat Jan 12 16:44:06 2002 julien gein
*/

#ifndef VM_DISPLAY_H_
# define VM_DISPLAY_H_

# include <X11/Xlib.h>
# include "my_struct.h"
# include "my.h"

# define KEY_ESCAPE	9
# define KEY_UP		98
# define KEY_DOWN	104

# define HSIZE_CHAR	get_hsize()
# define VSIZE_CHAR	get_vsize()
# define HSIZE_MEM	512
# define VSIZE_MEM	512
# define HOFFSET	10
# define VOFFSET	10
# define HSIZE_Q	4
# define VSIZE_Q	2

# define READ_SIZE	4096

# define NB_COLORS	18

# define DV_SET		0
# define DV_GET		1

# define MD_MEM		0
# define MD_PC		1
# define MD_FLUSH	2
# define MD_UNPC	3

# define SET_USAGE	"Usage: set Var1[, Var2, ...] := Val1[, Val2, ...]\n"

# define MAX(Var1, Var2)	(Var1 > Var2 ? Var1 : Var2)

typedef struct	s_point
{
  int		col;
  int		line;
  int		mode;
  int		clr;
}		t_point;

typedef struct	s_var
{
  char		*name;
  char		*value[4];
}		t_var;

typedef enum	e_error
{
  CFG_VAREXP,
  CFG_COMAEXP,
  CFG_ENDEXP
}		t_error;

typedef unsigned int	(*t_endfct)(char c);

typedef enum	e_color
{
  BLACK		= 0,
  RED		= 1,
  GREEN		= 2,
  YELLOW	= 3,
  BLUE		= 4,
  MAGENTA	= 5,
  CYAN		= 6,
  WHITE		= 7,
  ORANGERED	= 8,
  PALEVIOLETRED	= 9,
  DARKORCHID	= 10,
  STEELBLUE1	= 11,
  SEAGREEN1	= 12,
  KHAKI1	= 13,
  ROSYBROWN1	= 14,
  GREY		= 15,
  DARKGREY	= 16,
  SOFTGREY	= 17
}		t_color;

typedef struct	s_font
{
  char		*name;
  int		h_size;
  int		v_size;
}		t_font;

typedef struct	s_win
{
  Window	win;
  Display	*dpy;
  GC		gc;
  XColor	cl[NB_COLORS];
  Colormap	cmap;
  t_font	font;
  int		offset;
  int		max;
}		t_win;

/*
** CFGFILE ::
**
** get_buffer.c, cfg_parsefunc.c, cfg_parsescan.c, cfg_parsefile.c, cfg_vars.c
**
*/

t_list		*init_file_buff(char *path);

unsigned int	isspc(char c);
unsigned int	ispar(char c);
unsigned int	issep(char c);
unsigned int	isid(char c);
void		spcjump(char **s);


t_list		*get_listargs(char **str, char *end);
t_list		*get_listerror(char *var, int err, t_list *list);
unsigned int	str_isalnum(char *s);
unsigned int	isalnum(char c);
char		*gettk(char **s);

t_dicl		*update_dcdpy(char *str, void *elem, int mode);
void		init_dcdpy(void);
void		set_func(char *str);
void		cfg_parseline(char *str);
void		cfg_parsefile(void);

int		cmp(void *e1, void *e2);
unsigned int	truc_is_def(char *var, char *val);

/*
** DISPLAY
**
** display_attr.c, display_infos.c, display_regs.c, display_mem.c,
** display_refresh.c, display_players.c, display_primitives.c, display_str.c
** display_getnotifies.c
*/

void	set_color(int color);
int	get_hsize(void);
int	get_vsize(void);

void	init_infodpy(t_vm *vm);
void	refresh_infodpy(t_vm *vm);
void	init_infoinsdpy(void);

void	change_regsowner(t_vm		*vm, 
			 unsigned char	*name, 
			 unsigned int	id, 
			 unsigned int	prid);
void	update_reg(int vx, int vy, unsigned int pos, unsigned short value);
void	init_regdpy(t_vm *vm);
void	init_display_reg(t_vm *vm, int vx, int vy);
void	display_tab(int *vx, int *vy, int nb, const char *idx);

void	init_memdpy(int mem_size, int mode);
void	update_memdpy(int mem_size, int player, int idx, int mode);
void	update_display_mem_grid(int mem_size, int player, int idx, int mode);
void	redisplay_mem(int mem_size, t_point *backbuff, t_point *p);

void	display_case(int x, int y, int clr, int mode);
t_point	*init_backbuff(int size, int val);
void	update_display_mem(int mem_size, int player, int idx, int mode);
void	init_display_mem_grid(int mem_size);
void	init_display_mem(int mem_size);

void	test_rgarrow(t_vm *vm, int x, int y);
void	test_lfarrow(t_vm *vm, int x, int y);
void	test_select_player(t_vm *vm, int x, int y);
void	test_keypress(t_vm *vm, unsigned int key);
void	refresh_if_exposed(t_vm *vm);

void	draw_hlplayer(int color, int rg, char **names, int *pid);
void	display_current_player(t_vm *vm, int id, int prid);
void	display_player(int x, int y, char *name, int id);
void	players_dpy(char **players, int *ids, unsigned int nb, int *y);
void	display_players(t_vm *vm);

void	display_title(char *str, int save);
char	**get_pname(t_vm *vm, unsigned int *nb, int dead);
int	*get_pid(t_vm *vm, unsigned int *nb, int dead);

void	draw_line(int x1, int y1, int x2, int y2);
void	draw_rectangle(int x1, int y1, int x2, int y2);
void	display_ltrg(int vx, int vy);
void	display_rtrg(int vx, int vy);
void	display_grid(t_win *w);

void		display_str(int x, int y, char *str);
unsigned int	get_nbchars(const char *str, ...);
void		win_printf(int x, int y, const char *str, ...);

void		get_map_notify(t_win *window);
int		test_events(t_vm *vm, t_win *w, long event_mask);

void	get_events(t_win *w, t_list *winners, int victory);
void	display_coders(t_win *w);
void	init_win_exit(t_win *w, t_list *winners, int victory);
void	dpy_exit(t_win *w);
void	test_mouse(int x, int y);
void	display_win_exit(t_list *winners, int victory);

unsigned int	update_disp_zombies(t_vm *v, t_player *player);
unsigned int	update_zombies(t_vm *v, unsigned int prid);

/*
** INITIALISATION :
** 
** display_init.c, init_xserver.c
**
*/

void		init_interface(t_vm *vm);

t_win		*update_stwin(t_win *in);
unsigned int	init_stwin_colors(t_win *w);
Display		*open_display(void);
void		init_GC(t_win *win, int bcl, int wcl);
void		init_window(void);

#endif /* VM_DISPLAY_H_ */
