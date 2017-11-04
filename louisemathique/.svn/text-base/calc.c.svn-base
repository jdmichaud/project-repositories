/*
** calc.c for louisemathique in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Mon Oct 29 10:17:58 2001 jean-daniel michaud
** Last update Mon Oct 29 19:08:40 2001 jean-daniel michaud
*/

#include <stdio.h>
#include "errors.h"
#include "gmp.h"
#include "tree.h"
#include "calc.h"

void	addm(mpq_t res, t_node *left, t_node *right)
{
  mpq_add(res, left->elm.num.value, right->elm.num.value);
}

void	subm(mpq_t res, t_node *left, t_node *right)
{
  mpq_sub(res, left->elm.num.value, right->elm.num.value);  
}

void	mulm(mpq_t res, t_node *left, t_node *right)
{
  mpq_mul(res, left->elm.num.value, right->elm.num.value);
}

void	divm(mpq_t res, t_node *left, t_node *right)
{
  if (!mpq_sgn(right->elm.num.value))
    errors(CAL_ERR_VAL);
  mpq_div(res, left->elm.num.value, right->elm.num.value);
}
