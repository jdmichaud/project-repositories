/*
** connect.h for complètement_local in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Dec 13 09:23:05 2001 jean-daniel michaud

*/

#ifndef CONNECT_H_
# define CONNECT_H_

#define BACKLOG 5

int	waitfor(t_server *server);
int	fconnect(int fd, char *host, int pport);

#endif /* !CONNECT_H_ */
