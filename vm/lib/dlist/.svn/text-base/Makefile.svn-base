##
## Makefile for  in 
## 
## Made by GIZMO
## Login   <grimau_r@epita.fr>
## 
## Started on  Wed Oct  3 20:40:23 2001 GIZMO
## Last update Sat Jan 12 12:45:52 2002 julien gein
##
#
SRC		= dlist_put.c		\
		dlist_append.c		\
		dlist_rev.c		\
		dlist_size.c		\
		dlist_sort.c		\
		dlist_apply.c		\
		dlist_apply_on_node.c	\
		dlist_apply_on_eq.c	\
		dlist_rm_on_eq.c	\
		dlist_find_elm_eq.c	\
		dlist_find_node.c	\
		dlist_put_in_sortdlist.c \
		dlist_add_to_dlist.c	\
		dlist_add_to_sortdlist.c \
		dlist_free.c		\
		dlist_free_from_list.c	\
		dlist_show_str.c	\
		dlist_from_params.c	\
		dlist_from_list.c	\
		dlist_to_list.c
#
OBJS		= $(SRC:.c=.o)
LIB		= dlist
LNAME		= lib$(LIB)_$(HOSTTYPE).a
CC		= gcc
CFLAGS		= -O2 -Wall -pedantic -fstrict-prototypes -ansi -fsigned-char \
		-Wformat -Wimplicit -Wmissing-prototypes -Wparentheses -W     \
		-Wswitch -Wstrict-prototypes -Wpointer-arith -Wreturn-type    \
		-Wmissing-declarations -Wtraditional -Wunused -Wuninitialized \
		-fthis-is-variable -funsigned-char -Waggregate-return -Werror \
		-Wimplicit-int -Wcast-align -Wreturn-type		      \
		-Wimplicit-function-declaration -g
#
all		: $(LNAME)
#
$(LNAME)	: $(OBJS)
		ar rc $(LNAME) $(OBJS)
		ranlib $(LNAME)
		chmod 600 $(LNAME) && mv $(LNAME) ../
		cp dlist.h ../../include/
#
clean		:
		rm -f *.core $(OBJS) *~ #*#
#
fclean		: clean
		rm -f ../$(LNAME) $(LNAME)




