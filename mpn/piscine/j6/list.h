/*
** list.h aka sujet_j6.txt aka sujet_dur.txt
** 
** Made by (cyril diakhate & les acu)
** Login   ** 
** Started on  Tue Oct  2 09:55:29 2001 des gens chiants
** Last update Tue Oct  2 21:35:24 2001 jean-daniel michaud
*/

#ifndef		LIST_H_
# define LIST_H_

/*
** date de Rendu:          03/10/2001 a 08:30
** Groupe de News: epita.cours.c-unix.mini-projs
** Repertoire de Rendu:    ~/c/rendu/piscine/j6
** Droits:                 705 pour les repertoires.
** 			   604 pour le reste.
** Ne pas oublier:         Travailler a la norme.
** 			   Lire le sujet jusqu'au bout.
** 			   Etre en forme.
** 			   Faire un bisou a sa maman.
** 			   Se laver les dents avant d'aller se coucher.
** 			   
**
** ---------------------------------
**   IMPORTANT :: MODALITES DE RENDU
**  ---------------------------------
** **  Pour chaque exercice, vous devez bien entendu
**  respecter la norme. Votre repertoire doit contenir un Makefile
**  qui genere une bibliotheque nommee `liblist_$HOSTTYPE.a'.
**  Il sera ramasse dans son integralite et compile avec `make'.
**
**  Aucune fonction main() ne devra se trouver dans les fichiers
** que vous rendez. Mettez-les ailleurs.
**
**  Ce list.h sera mis, par nos SOINS, dans le meme repertoire que vos
**  sources (".c") et votre Makefile
**
** ----------------------
**   FONCTIONS AUTORISEES
** ----------------------
**
**  malloc(), my_printchar() et my_printstr() **  Ces deux dernieres fonctions seront fournies au moment de la
**  compilation de notre `main()'. Non, ca ne pose pas de problemes (il
**  n'y aura pas d'`undefined reference' sur ces deux symboles). Ca veut
**  aussi dire que vous ne devez pas laisser les fichiers contenant ces
**  fonctions dans votre repertoire de rendu.
**  Vous n'utiliserez pas votre libmy, vous n'en avez pas besoin.
** Vous avez droit a toutes les structures de controle du C autorisees
**  par la norme. C'est tout.
**
**  ------------------------------
** GENERALITES - FAUX PROBLEMES
** ------------------------------
**
**  Les cas particuliers sont purement le fruit de votre imagination.
**  Je ne plaisante pas.
** .
*/

struct		s_list {
  struct s_list	*next;
  void		*elem;
};
typedef struct s_list	t_list;
typedef int		(*t_cmpfunc)(void *e1, void *e2);

/*
** Ajoute l'element `elem' au "debut" de la liste `list' de telle
** sorte que :
** list->elem == elem
** .
*/
void		list_put(t_list **list, void *elem);

/*
** Ajoute l'element `elem' a la "fin" de la liste `list'
** .
*/ 

void		list_append(t_list **list, void *elem);

/*
** Inverse l'ordre des noeuds de la liste `list'
** .
*/

void		list_rev(t_list **list);

/*
** Trie la liste `list' selon la loi `cmp'
** .
*/
void		list_sort(t_list **list, t_cmpfunc cmp);

/*
** Applique le traitement `f' a chaque element de la liste en
** commencant par le "debut" et en finissant par la "fin"
** .
*/
void		list_apply(t_list **list, void (*f)(void *));

/*
** Applique le traitement `f' a chaque noeud de la liste en
** commencant par le "debut" et en finissant par la "fin"
** .
*/
void		list_apply_on_node(t_list *list, void (*f)(t_list *));

/*
** Renvoie le nombre de noeuds de la liste de telle sorte que :
** ** t_list	*l;
**
** l = 0;
** list_size(l) == 0
** list_size((list_put(&l, 1), l)) == 1
** .
*/
unsigned int	list_size(t_list *list);

/*
** Applique le traitment `f' a tous les elements egaux a `elem', selon
** la loi `cmp' en commencant par le "debut" et en finissant par la
** "fin"
** .
*/
void		list_apply_on_eq(t_list *list, void *elem, t_cmpfunc cmp,
				 void (*f)(void *));

/*
** Renvoie un pointeur sur le premier element de la liste `list'
** identique a `elem' selon la loi cmp. Renvoie le pointeur nul si
** aucun tel element n'est trouve
** .
*/
void		*list_find_elm_eq(t_list *list, void *elem, t_cmpfunc cmp);

/*
** Renvoie un pointeur sur le premier noeud de la liste `list' dont
** l'element est identique a `elem' selon la loi cmp. Renvoie le ** pointeur nul si aucun tel noeud n'est trouve
** .
*/
t_list		*list_find_node(t_list *list, void *elem, t_cmpfunc cmp);

/*
** Ajoute l'elment `elem' dans la liste triee `list' selon la loi
** `cmp'. Apres l'appel a cette fonction, la liste est toujours triee ** selon la loi `cmp'
** .
*/
void		list_put_in_sortlist(t_list **list, void *elem, t_cmpfunc cmp);

/*
** Ajoute la liste `src' a la "fin" de la liste `dest'
** .
*/
void list_add_to_list(t_list **dest, t_list *src);

/*
** Ajoute la liste triee `src' a la liste triee `dest'.
** A la suite de l'appel a cette fonction, la liste `dest'
** est triee selon la loi `cmp'
** .
*/
void		list_add_to_sortlist(t_list **dest, t_list *src, t_cmpfunc cmp);

/*
** Libere tous les noeuds de la liste `list'
** Apres l'appel a cette fonction, on a :
** *list == 0
** .
*/
void		list_free(t_list **list);

/*
** Affiche en tant que chaines de caracteres chaque element de la
** liste `list' en commencant par le "debut" et en finissant par la
** "fin"
** .
*/
void list_show_str(t_list *list);

/*
** Genere une liste de `ac' elements a patir du tableau `av' telle que
** chaque element du tableau soit contenu dans un noeud de la liste
** apres traitement, en conservant l'ordre
** .
*/
void list_from_params(t_list **list, int ac, char *av[]);

#endif
/*
** LIST_H_
*/
