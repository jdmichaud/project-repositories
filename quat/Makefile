##
## Makefile for quaternion in 
## 
## Made by Jean-Daniel Michaud
## Login   <JeDi@epita.fr>
## 
## Started on  Fri Feb  1 15:09:06 2002 Jean-Daniel Michaud
## Last update Wed Feb 13 13:43:26 2002 jean-daniel michaud
##
#
CC	= g++
RM	= rm -fr
AR	= ar -cr
#
NAME	= quat
SRC	= euler.cc	\
	main.cc		\
	matrix.cc	\
	quaternion.cc	\
	slerp.cc
OBJ	= $(SRC:.cc=.o)
#
CFLAGS	= -Wall -ansi -ggdb
#
all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
#
.cc.o:
	$(CC) $(CFLAGS) -c $<
#
clean:
	$(RM) *.o *~ *.~ *.core $(NAME) \#*
#
re: clean all