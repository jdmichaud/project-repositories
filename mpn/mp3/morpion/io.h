/*
** io.h for morpion in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Nov  3 15:18:38 2001 jean-daniel michaud
** Last update Sun Nov  4 17:21:18 2001 jean-daniel michaud
*/

#ifndef __IO_H_
# define __IO_H_

#define PRINT	"print"
#define EXIT	"exit"

#define CROSS_CHAR	"X"
#define CIRCLE_CHAR	"0"
#define VOID_CHAR	" "
#define LINE		"-------\n"
#define SEPARATOR	"|"

void	my_get(char *str);
void	print_game(int game[3][3]);
void	prompt(int pid, char *cmd, int game[3][3]);

#endif
