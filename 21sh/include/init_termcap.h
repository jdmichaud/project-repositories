/*
** init.h for  in 
** 
** Made by Jonathan APELBAUM
** Login   <apelba_j@epita.fr>
** 
** Started on  Wed Dec 19 11:59:20 2001 Jonathan APELBAUM
** Last update Mon Dec 31 14:27:25 2001 jean-daniel michaud
*/

/*#ifndef __INIT_TERMCAP_H_*/
/*# define __INIT_TERMCAP_H_*/


#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#ifdef __NetBSD__
# include <termcap.h>
# include <termios.h>
#endif
#ifdef __alpha
# include <termio.h>
# include <term.h>
#endif
#ifdef __sun__
# define __lint
# include <curses.h>
# include <term.h>
# include <termio.h>  
#endif




#define LENGTH_MALLOC  	1024

#define CTRLA		1
#define CTRLC		3
#define CTRLE		5
#define BACKSPACE	8
#define TABE		9
#define ENTER		10
#define CTRLK		11
#define CTRLL		12
#define CTRLU		21
#define CTRLW		23
#define CTRLY		25
#define CTRLZ		26
#define ARROW		27

#define UP		65
#define DOWN		66
#define RIGHT		67
#define LEFT		68


#define define_list_of_char { \
	{CTRLA, exec_ctrla}, \
	{CTRLE, exec_ctrle}, \
	{BACKSPACE, exec_backspace}, \
	{TABE, exec_tabe}, \
	{ENTER, exec_enter}, \
	{CTRLK, exec_ctrlk}, \
	{CTRLL, exec_ctrll}, \
	{CTRLU, exec_ctrlu}, \
	{CTRLW, exec_ctrlw}, \
	{ARROW, 0}, \
	{0, exec_char} \
}

#define define_list_of_arrow { \
	{UP, exec_up}, \
	{DOWN, exec_down}, \
	{LEFT, exec_left}, \
	{RIGHT, exec_right}, \
	{0, exec_char} \
}



#ifdef __sun__
typedef struct termio	t_term_config; 
#else
typedef struct termios	t_term_config; 
#endif


struct		s_term_list
{
  int		rows;
  int		cols;
  int		num_of_cols;
  int		num;
  int		finish;
  int		curser;
  char		*prompt;
  char		cote;
  char		*chaine;
  char		*copy;
};
typedef struct	s_term_list		t_term_list;


struct		s_char
{
  int		value;
  void		(*func)(t_term_list *list);
};
typedef struct	s_char t_char;



void		treat_char(t_term_list *list);
int		my_write(int c);
t_term_list	*init_struct(void);
int		non_canonical_mode(t_term_config *original_term_config);
void		init_size_term(t_term_list *list);
char		recup_char(t_term_list *list);
void		print_prompt(t_term_list *list);
void		recup_arrow(t_term_list *list, int i);

/*#endif*/
