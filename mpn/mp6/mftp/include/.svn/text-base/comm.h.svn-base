/*
** comm.h for complètement_local in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Dec 13 21:24:26 2001 jean-daniel michaud
** Last update Mon Dec 17 14:16:23 2001 jean-daniel michaud
*/

#ifndef COMM_H_
# define COMM_H_

#define BLOCKSIZE	16

int	send2cl(t_user *user, void *buf);
int	senddata2cl(t_user *user, void *buf, unsigned int ssize);
void	sendfile2cl(t_user *user, char *file);
int	getfromcl(t_user *user, char **buff);
void	freeport(int pport);

#endif
