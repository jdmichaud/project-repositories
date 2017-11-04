/*
** error.h for mini-ls in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Nov 20 00:12:07 2001 jean-daniel michaud
** Last update Tue Nov 20 00:23:23 2001 jean-daniel michaud
*/

#ifndef __ERROR_H_
# define __ERROR_H_

void	NoPerm(char *file);
void	NoFile(char *file);
void	IllOptn(char c);
void	Usage(void);

#endif
