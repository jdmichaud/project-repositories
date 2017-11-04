/*
** inpiou.h for inpiou in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Fri Nov  2 18:28:25 2001 jean-daniel michaud
** Last update Sat Nov  3 14:30:47 2001 jean-daniel michaud
*/

#ifndef __INPIOU_H_
# define __INPIOU_H_

#define RET_VAL_FILE	256
#define RET_VAL_CMD	512

int	fisrt_son_action(int p[2], char **argv);
int	sec_son_action(int p[2], char **argv);

#endif
