/*
** output.h for beswitch in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Nov  7 15:34:20 2001 jean-daniel michaud
** Last update Sun Nov 11 11:10:58 2001 jean-daniel michaud
*/

#ifndef OUTPUT_H_
# define OUTPUT_H_

#define INCLUDE	"#include <stdio.h>\n"
#define FNC_PRT	"const char *in_word_set (const char *str, size_t len)\n"
#define STC_TAB	"static const char * wordlist[] ="

void	make_indent(int	nb);
int	make_code(t_dico *tree);
int	make_code_from_son(t_dico *tree, int i, int index);
int	make_code_from_bros(t_dico *tree, int i, int index);

#endif
