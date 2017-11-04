/*
** tree.h for beswitch in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Nov  8 09:40:24 2001 jean-daniel michaud
** Last update Sun Nov 11 07:40:05 2001 jean-daniel michaud
*/

#ifndef TREE_H_
# define TREE_H_

struct			s_dico
{
  char			c;
  struct s_dico		*bros;
  struct s_dico		*son;
};

typedef struct s_dico	t_dico;

int	add_word(t_dico **root, char *word);
void	add_char(t_dico **sub_tree, char c);
int	add_first_word(t_dico **root, char *word);
void	free_tree(t_dico *tree);
t_dico	*is_known(t_dico *tree, char **word);

#endif
