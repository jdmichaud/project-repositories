##
## Makefile for Makefile in 
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Wed Oct 24 16:19:46 2001 jean-daniel michaud
## Last update Mon Nov  5 16:18:46 2001 jean-daniel michaud
##
#
CC	= gcc
AR	= ar -cr
RM	= rm -fr
#
SRC	= inpiou.c
OBJS	= $(SRC:.c=.o)
#
NAME	= inpiou
IPATH	= -I.
CFLAGS	= $(IPATH) -Wall -Wstrict-prototypes
#
all	: $(OBJS)
	$(CC) $(SRC) -o $(NAME)
#
.c.o	:
	$(CC) $(CFLAGS) -c $<
#
re	:
	$(RM) *.core $(OBJS) *.*~ *~ \#* Makefile~ $(NAME)
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(SRC) -o $(NAME)
#
clean	:
	$(RM) *.core $(OBJS) *.*~ *~ \#* Makefile~
#
fclean	:
	$(RM) *.core $(OBJS) *.*~ *~ \#* Makefile~ $(NAME)


