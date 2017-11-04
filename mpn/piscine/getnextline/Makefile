##
## Makefile for Makefile in 
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Sat Oct  6 19:53:03 2001 jean-daniel michaud
## Last update Sun Oct  7 15:20:44 2001 jean-daniel michaud
##

CC	= cc
FLAGS	= -c
WFLAGS	= -Wall -ansi -pedantic
RM	= rm -fr
NAME	= get_next_line
AR	= ar
ARFLAGS	= -cr
SRC	= get_next_line.c my_strcpy_cr.c my_strlen_cr.c my_strndup_cr.c\
	need_read.c read_block.c my_realloc_str.c list_put.c list_free.c\
	list_find_node.c list_find_elm_eq.c main.c

OBJS	= $(SRC:.c=.o)

all:	$(OBJS)
	$(CC) $(OBJS) -o $(NAME)

.c.o:
	$(CC) $(FLAGS) $(WFLAGS) $<

clean:
	$(RM) *.o
	$(RM) *.*~
	$(RM) \#*
	$(RM) *~


