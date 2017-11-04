##
## Makefile for my_cat in ~/c/rendu/exos/cat
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Wed Oct 10 14:01:22 2001 jean-daniel michaud
## Last update Wed Oct 10 16:13:05 2001 jean-daniel michaud
##

CC	= cc
OFLAGS	= -c
FLAGS	= -pipe -ggdb3
WFLAGS	= -Wall -ansi -pedantic
NAME	= my_cat

RM	= rm -fr

SRC	= my_cat.c my_cat2.c my_cat3.c my_printnbr.c my_printchar.c
OBJS	= $(SRC:.c=.o) 

all:	$(OBJS)
	$(CC) $(FLAGS) $(WFLAGS) $(OBJS) -o $(NAME)

.c.o:	$(SRC)
	$(CC) $(WFLAGS) $(OFLAGS) $<

clean:
	$(RM) *.o
	$(RM) *.*~
	$(RM) *~
	$(RM) \#*

