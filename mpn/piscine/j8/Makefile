##
## Makefile for Makefile in ~/c/rendu/piscine/j6/
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Tue Oct  2 20:31:53 2001 jean-daniel michaud
## Last update Sat Oct  6 19:35:31 2001 jean-daniel michaud
##

CC	= cc
AR	= ar -cr
FLAGS	= -c
WFLAGS	= -Werror -Wstrict-prototypes -Wall -pedantic\
	-Wpointer-arith -Waggregate-return -Wmissing-prototypes\
	-Wnested-externs -ansi -Wredundant-decls -Wparentheses -W\
	-Wreturn-type -Wshadow -Wtraditional

RM	= rm -fr

NAME	= libbtree_${HOSTTYPE}.a

SRC	= btree_put.c btree_apply.c btree_size.c\
	btree_depth.c btree_apply_on_eq.c btree_find_node.c\
	btree_find_elem.c btree_rm_all_eq.c max_min.c btree_free.c\
	btree_add_btree.c btree_add_list.c list_put.c btree_to_sort_list.c

OBJS	= $(SRC:.c=.o)

all:	$(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	 $(RM) *.o
	 $(RM) *.*~
	 $(RM) \#*
	 $(RM) *~

.c.o:
	$(CC) $(FLAGS) $(WFLAGS) $<






































