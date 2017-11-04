/*
** init.h for 21sh in ~/c/rendu/projs/21sh
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Nov 29 11:38:35 2001 jean-daniel michaud
** Last update Mon Dec 31 11:08:56 2001 jonathan mimouni
*/

#ifndef INIT_H_
# define INIT_H_

/*
** Initialise le shell
** Cette fonction verifie ke
** l'utilisateur est dans un terminal
** et arrete l'execution du shell sinon
*/

void		init_21sh(t_list_cmd **list_cmd);
t_term_list	*init_term(void);

#endif
