/*
** beswitch.h for beswitch in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Nov  7 12:39:08 2001 jean-daniel michaud
** Last update Sun Nov 11 09:02:04 2001 jean-daniel michaud
*/

#ifndef BESWITCH_H_
# define BESWITCH_H_

#define W_STDIN	"l'entree est stdin"

void		errors(unsigned int err, char *f);
int		start(t_dico **tree, char *filename);

#endif
