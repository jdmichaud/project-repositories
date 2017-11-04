/*
** data_struct.h for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Wed Dec 19 11:58:29 2001 julien gein
** Last update Sun Jan  6 17:18:19 2002 jean-daniel michaud
*/

#ifndef DATA_STRUCT_H_
# define DATA_STRUCT_H_

typedef void	(*t_printfunc)(void *);
typedef void	*(*t_listfunc)(void *);
typedef void	(*t_df_free)(void *);
typedef void	*(*t_createfct)(void *);

/*
** ------------------------< TYPES DE DONNEES >------------------------
*/

typedef struct	s_list
{
  void		*elem;
  struct s_list	*next;
}		t_list;
typedef int	(*t_cmpfunc)(void *, void *);

typedef struct	s_ntree
{
  void		*elem;
  t_list	*childs;
}		t_ntree;

typedef struct	s_dicl
{
  char		c;
  void		*elt;
  struct s_dicl	*bros;
  struct s_dicl	*child;
}		t_dicl;

/*
** ---------------------------< PROTOTYPES >---------------------------
*/

void		*xmalloc(int);
void		xprintf(const int	out,
			const int	val,
			const char	*mess,
			...);

void		list_append(t_list **list, void *elem);
t_list		*list_find_node(t_list *list, void *elem, t_cmpfunc cmp);
void		list_free(t_list **list);
void		list_put(t_list **list, void *elem);
unsigned int	list_size(t_list *list);
void		list_sort(t_list **list,t_cmpfunc);
void		*list_push(t_list **list);
void		list_delhead(t_list **head, t_list *pos);
void		list_append_list(t_list **list, t_list *add);

int		cmp_node(void *elem, void *node);
t_ntree		*ntree_create(void *elem, t_list *childs);
t_ntree		*ntree_find_node(t_ntree *root, void *elem, t_cmpfunc fct);
void		ntree_free(t_ntree **);

t_dicl		*df_create_elt(char c, t_dicl *bros, t_dicl *child);
t_dicl		*df_ins_elt(t_dicl *, char *, void *);
void		df_list_elt(t_dicl *, t_printfunc);
void		*df_get_elt(t_dicl *, char *);
t_dicl		*df_remove_elt(t_dicl *, char *);
t_list		*df_genlist(t_dicl *);
t_list		*df_genlist_pref(t_dicl *, char *, t_listfunc);
void		df_free(t_dicl **, t_df_free);

t_list		*vchar_to_list(char **, unsigned int, t_createfct);
char		**vchar_from_list(t_list *);


#endif /* DATA_STRUCT_H_ */
