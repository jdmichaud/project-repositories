/*
** explorer.h for sploum in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Nov 22 18:41:47 2001 jean-daniel michaud
** Last update Sun Nov 25 16:58:21 2001 jean-daniel michaud
*/

#ifndef EXPLORER_H_
# define EXPLORER_H_

char	*openfilebox(void);
int	explorer(char *path);
void	show(void);
void	explore(void);
void	buildlist(int whence);

#endif
