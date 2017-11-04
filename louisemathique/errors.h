/*
** errors.h for louisemathique in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sun Oct 28 18:15:28 2001 jean-daniel michaud
** Last update Sun Oct 28 21:34:57 2001 jean-daniel michaud
*/

#ifndef __ERRORS_H_
# define __ERRORS_H_

#define SYS_ERR "erreur\n"
#define SYS_ERR_VAL 1
#define SYN_ERR "syntaxe error\n"
#define SYN_ERR_VAL 2
#define ARG_ERR "argument manquant\n"
#define ARG_ERR_VAL 3
#define STK_ERR "trop arguments\n"
#define STK_ERR_VAL 4
#define CAL_ERR "erreur de calcul\n"
#define CAL_ERR_VAL 5

void	errors(int i);

#endif
