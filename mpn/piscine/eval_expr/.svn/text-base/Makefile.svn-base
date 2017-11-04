##
## Makefile for Makefile in 
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Sun Oct  7 15:17:50 2001 jean-daniel michaud
## Last update Sun Oct  7 23:18:15 2001 jean-daniel michaud
##

CC	= cc
FLAGS	= -c -pipe
WFLAGS	= -Wall -ansi -pedantic
RM	= rm -fr
NAME	= my_eval_expr
AR	= ar
ARFLAGS	= -cr
SRC	= main.c eval_expr.c pile.c is_op.c my_is_digit.c signe.c my_atoi.c\
	get_number.c my_printnbr.c my_printchar.c

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


