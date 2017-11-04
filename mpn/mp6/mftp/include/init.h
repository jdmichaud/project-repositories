/*
** init.h for complètement_local in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Dec 13 10:37:28 2001 jean-daniel michaud
** Last update Thu Dec 13 15:19:56 2001 jean-daniel michaud
*/

#ifndef INIT_H_
# define INIT_H_

t_server		*init(t_options *options);
t_server		*init_connection(int port);

#endif
