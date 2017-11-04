##
## Makefile for  in 
## 
## Made by julien gein
## Login   <gein_j@epita.fr>
## 
## Started on  Tue Oct  2 22:29:02 2001 julien gein
## Last update Thu Jan 10 17:38:17 2002 jean-daniel michaud
##
#
CC	= gcc
IPATH	= 
CFLAGS	= -Wall $(IPATH) -g
#
SRC	= xmalloc.c		\
	vchar_from_list.c	\
	vchar_to_list.c		\
	list_append.c		\
	list_find_node.c	\
	list_free.c		\
	list_put.c		\
	list_size.c		\
	list_sort.c		\
	list_free.c		\
	list_create.c		\
	list_push.c		\
	list_delhead.c		\
	list_append_list.c	\
	ntree_create.c		\
	ntree_find_node.c	\
	ntree_free.c		\
	df_create_elt.c		\
	df_ins_elt.c		\
	df_list_elt.c		\
	df_get_elt.c		\
	df_remove_elt.c		\
	df_genlist.c		\
	df_genlist_pref.c	\
	df_free.c		\
	xprintf.c
#
OBJS	= $(SRC:.c=.o)
#
LNAME	= libsdata_${HOSTTYPE}.a
#
all	: $(OBJS)
	ar rc $(LNAME) $(OBJS)
	ranlib $(LNAME)
	chmod 600 $(LNAME) && mv $(LNAME) ../
	cp data_struct.h ../../include
#
clean	:
	rm -f $(OBJS) *~
#
fclean	: clean
	rm -f $(LNAME) ../$(LNAME)
#
re	: fclean all


