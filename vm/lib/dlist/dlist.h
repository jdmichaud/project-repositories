/*
** dlist.h aka sujet_j7.txt aka sujet_super_dur.txt aka nijuhanji no NEWS.txt
** 
** Made by (cyril diakhate & les acu)
** Login   </dev/random@epita.fr>
** 
** Started on  Tue Oct  2 09:55:29 2001 des gens chiants
** Last update Sat Jan 12 12:46:12 2002 julien gein
*/

#ifndef		DLIST_H_
# define	DLIST_H_

#include "data_struct.h"

# ifndef DATA_STRUCT_H_
typedef struct s_list	t_list;
typedef int		(*t_cmpfunc)(void *e1, void *e2);
# endif

struct			s_dlist
{
  struct s_dlist	*next;
  void			*elem;
  struct s_dlist	*prev;
};
typedef struct s_dlist	t_dlist;

/*
** Ajoute l'element `elem' au "debut" de la dliste `dlist' de telle
** sorte que :
** dlist_put(&dlist, elem)
** dlist->elem == elem
** .
*/
void		dlist_put(t_dlist **dlist, void *elem);

/*
** Ajoute l'element `elem' a la "fin" de la dliste `dlist'
** .
*/
void		dlist_append(t_dlist **dlist, void *elem);

/*
** Inverse l'ordre des noeuds de la dliste `dlist'
** .
*/
void		dlist_rev(t_dlist **dlist);

/*
** Trie la dliste `dlist' selon la loi `cmp' par ordre croissant.
** .
*/
void		dlist_sort(t_dlist **dlist, t_cmpfunc cmp);

/*
** Applique le traitement `f' a chaque element de la dliste en
** commencant par le "debut" et en finissant par la "fin"
** .
*/
void		dlist_apply(t_dlist *dlist, void (*f)(void *));

/*
** Applique le traitement `f' a chaque noeud de la dliste en
** commencant par le "debut" et en finissant par la "fin"
** .
*/
void		dlist_apply_on_node(t_dlist *dlist, void (*f)(t_dlist *));

/*
** Renvoie le nombre de noeuds de la dliste de telle sorte que :
** 
** t_dlist	*l;
**
** l = 0;
** dlist_size(l) == 0
** dlist_size((dlist_put(&l, 1), l)) == 1
** .
*/
unsigned int	dlist_size(t_dlist *dlist);

/*
** Applique le traitment `f' a tous les elements egaux a `elem' selon
** la loi `cmp' en commencant par le "debut" et en finissant par la
** "fin"
** .
*/
void		dlist_apply_on_eq(t_dlist *dlist, void *elem, t_cmpfunc cmp,
				  void (*f)(void *));

/*
** Supprime de la dliste tous les elements egaux a `elem' selon
** la loi `cmp'
** .
*/
void		dlist_rm_on_eq(t_dlist **dlist, void *elem, t_cmpfunc cmp);

/*
** Renvoie un pointeur sur le premier element de la dliste `dlist'
** identique a `elem' selon la loi cmp. Renvoie le pointeur nul si
** aucun tel element n'est trouve
** .
*/
void		*dlist_find_elm_eq(t_dlist *dlist, void *elem, t_cmpfunc cmp);

/*
** Renvoie un pointeur sur le premier noeud de la dliste `dlist' dont
** l'element est identique a `elem' selon la loi cmp. Renvoie le
** pointeur nul si aucun tel noeud n'est trouve
** .
*/
t_dlist		*dlist_find_node(t_dlist *dlist, void *elem, t_cmpfunc cmp);

/*
** Ajoute l'elment `elem' dans la dliste triee `dlist' selon la loi
** `cmp'. Apres l'appel a cette fonction, la dliste est toujours triee
** selon la loi `cmp'
** .
*/
void		dlist_put_in_sortdlist(t_dlist		**dlist,
				       void		*elem,
				       t_cmpfunc	cmp);

/*
** Ajoute la dliste `src' a la "fin" de la dliste `dest'
** .
*/
void		dlist_add_to_dlist(t_dlist **dest, t_dlist *src);

/*
** Ajoute la dliste triee `src' a la dliste triee `dest'.
** A la suite de l'appel a cette fonction, la dliste `dest'
** est triee selon la loi `cmp'
** .
*/
void		dlist_add_to_sortdlist(t_dlist		**dest,
				       t_dlist		*src,
				       t_cmpfunc	cmp);

/*
** Libere tous les NOEUDS de la dliste `dlist'
** Apres l'appel a cette fonction, on a :
** *dlist == 0
** .
*/
void		dlist_free(t_dlist **dlist);

/*
** Affiche en tant que chaine de caracteres chaque element de la
** dliste `dlist' en commencant par le "debut" et en finissant par la
** "fin" sans separateur et sans trier la liste et sans recoder
** windows(TM)
** .
*/
void		dlist_show_str(t_dlist *dlist);

/*
** Genere une dliste de `ac' elements a patir du tableau `av' telle que
** CHAQUE element du tableau soit contenu dans un noeud de la dliste
** apres traitement, en conservant l'ordre
** .
*/
void		dlist_from_params(t_dlist **dlist, int ac, char *av[]);

/*
** Genere une dliste a partir d'une liste en conservant l'ordre et
** sans ajouter de retours chariot ni de nouvelle ligne
** .
*/
t_dlist		*dlist_from_list(t_list *list);

/*
** Genere une liste a partir d'une dliste en conservant l'ordre et
** sans ajouter d'elephants ni de girafe dans le frigo
** .
*/
t_list		*dlist_to_list(t_dlist *list);

/*
** Supprime les element de la liste from de la liste list
*/

void			dlist_free_from_list(t_dlist **list, t_dlist *from);


#endif /* DLIST_H_ */
