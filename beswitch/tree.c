/*
** tree.c for beswitch in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Nov  8 09:40:01 2001 jean-daniel michaud
** Last update Mon Nov 12 08:57:50 2001 jean-daniel michaud
*/

#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "my_printf.h"
#include "my_print_error.h"
#include "beswitch.h"

void	add_char(t_dico **sub_tree, char c)
{
  if ((*sub_tree = malloc(sizeof (t_dico))) == NULL)
    errors(42, NULL);
  (*sub_tree)->c = c;
  (*sub_tree)->bros = NULL;
  (*sub_tree)->son = NULL;
}
int	cmp(t_dico *tree, char c)
{
  if (!tree)
    return (0);
  return (tree->c == c);
}

t_dico		*is_known(t_dico *tree, char **word)
{
  if ((!tree->c) && (!**word))
    return (NULL);
  if (cmp(tree, **word))
    {
      if (tree->son)
	{
	  ++(*word);
	  return (is_known(tree->son, word));
	}
      return (tree);      
    }
  if (tree->bros) 
    return (is_known(tree->bros, word));
  return (tree);
}

int		add_first_word(t_dico **root, char *word)
{
  t_dico	*tree;

  add_char(root, *word);
  ++word;
  for (tree = *root; *word; ++word, tree = tree->son) 
    add_char(&(tree->son), *word);
  add_char(&(tree->son), '\0');
  return (1);
}

int		add_word(t_dico **root, char *word)
{
  t_dico	*tree;
  
  if (!word)
    return (1);
  if (!*root)
    return (add_first_word(root, word)); 
  if ((tree = is_known(*root, &word)) == NULL)
    return (0);
  add_char(&(tree->bros), *word++);
  for (tree = tree->bros; *word; ++word, tree = tree->son)
    add_char(&(tree->son), *word);
  add_char(&(tree->son), '\0');
  return (1);
}

void	free_tree(t_dico *tree)
{
  if (tree)
    {
      free_tree(tree->son);
      free_tree(tree->bros);
      free(tree);
    }
}

