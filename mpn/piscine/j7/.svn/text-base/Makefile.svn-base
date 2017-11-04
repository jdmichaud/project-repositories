##
## Makefile for Makefile in ~/c/rendu/piscine/j6/
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Tue Oct  2 20:31:53 2001 jean-daniel michaud
## Last update Thu Oct  4 04:31:43 2001 jean-daniel michaud
##

CC	= cc
AR	= ar -cr
FLAGS	= -c
WFLAGS	= -Werror -Wstrict-prototypes -Wall -pedantic\
	-Wpointer-arith -Waggregate-return -Wmissing-prototypes\
	-Wnested-externs -ansi -Wredundant-decls -Wparentheses -W\
	-Wreturn-type -Wshadow -Wtraditional

RM	= rm -fr

NAME	= libdlist_${HOSTTYPE}.a

SRC	= dlist_put.c dlist_append.c dlist_rev.c dlist_sort.c dlist_apply.c\
	dlist_apply_on_node.c dlist_size.c dlist_apply_on_eq.c\
	dlist_find_elm_eq.c dlist_find_node.c dlist_put_in_sortdlist.c\
	dlist_add_to_dlist.c dlist_add_to_sortdlist.c dlist_free.c\
	dlist_show_str.c dlist_from_params.c dlist_rm_on_eq.c\
	dlist_from_list.c dlist_to_list.c

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






































