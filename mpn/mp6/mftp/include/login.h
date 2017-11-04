/*
** login.h for complètement_local in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Fri Dec 14 12:42:50 2001 jean-daniel michaud

*/

#ifndef LOGIN_H_
# define LOGIN_H_

void	dupserver(t_server *server, int csocket);
t_user	*login(t_server *server, int csocket);
t_user	*authorize(t_server *server, int csocket);

#endif
