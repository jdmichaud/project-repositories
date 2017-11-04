/*
** sig.h for morpion in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Nov  3 22:28:18 2001 jean-daniel michaud
** Last update Sun Nov  4 10:28:37 2001 jean-daniel michaud
*/

#ifndef __SIG_H_
# define __SIG_H_

void	send_sig(int pid, int slot);
void	atomic_send_sig(int pid, int val);
void	reveive_usr1(int n);
void	reveive_usr2(int n);
int	wait4response(int pid, int game[3][3]);

#endif
