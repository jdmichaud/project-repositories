/*
** options.h for vm in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Jan  2 16:59:25 2002 jean-daniel michaud
** Last update Tue Jan  8 14:15:03 2002 jean-daniel michaud
*/

#ifndef OPTIONS_H_
# define OPTIONS_H_

int	get_option(char *argv[], int indice);
char	*get_char_option(char *argv[], int indice);
int	option_here(char *argv[], int indice);
int	noill_options(char *argv[]);
t_list	*get_filename(char *argv[]);

#endif
