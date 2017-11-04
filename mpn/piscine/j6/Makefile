##
## Makefile for Makefile in ~/c/rendu/piscine/j6/
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Tue Oct  2 20:31:53 2001 jean-daniel michaud
## Last update Wed Oct  3 15:33:48 2001 jean-daniel michaud
##

CC	= cc
AR	= ar -cr
FLAGS	= -c
RM	= rm -fr

NAME	= liblist_${HOSTTYPE}.a

SRC	= list_put.c list_append.c list_rev.c list_sort.c list_apply.c\
	list_apply_on_node.c list_size.c list_apply_on_eq.c list_find_elm_eq.c\
	list_find_node.c list_put_in_sortlist.c list_add_to_list.c\
	list_add_to_sortlist.c list_free.c list_show_str.c list_from_params.c

OBJS	= $(SRC:.c=.o)

all:	$(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	 $(RM) *.o
	 $(RM) *.*~
	 $(RM) \#*
	 $(RM) *~

.c.o:
	$(CC) $(FLAGS) $<