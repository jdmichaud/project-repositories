/*
** process.h for 21sh in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Dec  1 16:25:39 2001 jean-daniel michaud
** Last update Sun Dec 30 15:34:09 2001 jean-daniel michaud
*/

#ifndef PROCESS_H_
# define PROCESS_H_

#include "struct.h"
#include "list.h"

/*
** INITIALISATION
*/

void		procinit(void);

/*
** PROCESS
*/
t_process	*init_process(t_command *command);
int		exec_list(t_command *command);
int		execute(t_process *process);
int		waitson(void);
int		redir(int pfd, int fd);

/*
** SIGNALS
*/
void		init_signals(void);
void		handling(int idsignal, t_handler f);

/*
** PROCLIST
*/
void		delproc(t_list **glprocess, int pid);
t_process	*getproc(t_list *lprocess, int pid);
int		isfgprocrunning(t_list *lprocess);
void		free_elem(t_list *lprocess);
void		stopall(void);

/*
** HANDLERS
*/
void		hchld(int);
void		hint(int);
void		hterm(int);
void		hquit(int);
void		hstp(int);

#endif
