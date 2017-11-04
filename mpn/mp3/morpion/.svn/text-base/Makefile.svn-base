##
## Makefile for Makefile in 
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Wed Oct 24 16:19:46 2001 jean-daniel michaud
## Last update Mon Nov  5 17:23:02 2001 jean-daniel michaud
##
#
CC	= gcc
AR	= ar -cr
RM	= rm -fr
#
SRC	= morpion.c\
	io.c\
	my_atoi.c\
	my_strcmp.c\
	game.c\
	sig.c\
	my_ctype.c\
	my_printnbr.c\
	my_printscreen.c\
	my_printchar.c\
	my_printnbr_base.c\
	my_printstr.c
OBJS	= $(SRC:.c=.o)
#
NAME	= morpion
IPATH	= -I.
LPATH	= -L.
CFLAGS	= $(IPATH) -Wall -Wstrict-prototypes
#
all	: $(OBJS)
	$(CC) $(LPATH) $(OBJS) -o $(NAME) $(LNAME)
#
.c.o	:
	$(CC) $(CFLAGS) -c $<
#
re	:
	$(RM) *.core $(OBJS) *.*~ *~ \#* Makefile~ $(NAME)
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(LPATH) $(OBJS) -o $(NAME) $(LNAME)
#
clean	:
	$(RM) *.core $(OBJS) *.*~ *~ \#* Makefile~
#
fclean	:
	$(RM) *.core $(OBJS) *.*~ *~ \#* Makefile~ $(NAME)



