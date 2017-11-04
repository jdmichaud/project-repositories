##
## Makefile for sploum in 
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Thu Nov 22 17:29:32 2001 jean-daniel michaud
## Last update Tue Nov 27 22:38:36 2001 jean-daniel michaud
##
#
CC	= cc
AR	= ar -cr
RM	= rm -fr
#
SRC	= colors.c	\
	ed_error.c	\
	ed_events.c	\
	ed_events2.c	\
	ed_show.c	\
	ex_error.c	\
	ex_events.c	\
	explorer.c	\
	format.c	\
	get_type.c	\
	help.c		\
	hexaeditor.c	\
	ls.c		\
	my_xmalloc.c	\
	retrace.c	\
	sploum.c	\
	utils.c
OBJS	= $(SRC:.c=.o)
#
NAME	= sploum
IPATH	= -I../include
LPATH	= -L.
LNAME	= -lcurses -ltermcap
CFLAGS	= $(IPATH)
#
all	: $(OBJS)
	$(CC) $(LPATH) $(OBJS) -o $(NAME) $(LNAME)
#
.c.o	:
	$(CC) $(CFLAGS) -c $<
#
re	: fclean all
#
clean	:
	$(RM) *.core $(OBJS) *.*~ *~ \#* Makefile~ $(NAME)



