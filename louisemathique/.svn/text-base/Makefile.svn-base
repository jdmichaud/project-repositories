##
## Makefile for louisemathique in 
## 
## Made by Jean-Daniel Michaudf
## Login   <jedi@epita.fr>
## 
## Started on  Thu Oct 25 22:58:56 2001 Jean-Daniel Michaudf
## Last update Mon Oct 29 19:24:34 2001 jean-daniel michaud
##

CC		= cc
FLAGS		= -pipe -ggdb
WFLAGS		= -Wall -ansi -pedantic
GMPPREFIX	= /u/prof/akim
INCL		= -I$(GMPPREFIX)/include
LIBS		= -L$(GMPPREFIX)/lib
#
GMP		= -lgmp
#
NAME		= louisemathique
#
RM		= rm -fr
#
SRC		= calc.c\
		compute.c\
		errors.c\
		io.c\
		louise.c\
		my_ctype.c\
		my_stdlib.c\
		stack.c\
		tree.c

#
OBJS		= $(SRC:.c=.o)
#

all:	$(OBJS)
	$(CC) $(INCL) $(LIBS) $(FLAGS) $(WFLAGS) $(OBJS) -o $(NAME) $(GMP)

.c.o:
	$(CC) $(INCL) $(LIBS) $(FLAGS) $(WFLAGS) -c $<

clean:
	$(RM) *.o
	$(RM) *.c~
	$(RM) *.h~
	$(RM) \#*

