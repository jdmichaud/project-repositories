##
## Makefile for Makefile in 
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Wed Oct 24 16:19:46 2001 jean-daniel michaud
## Last update Thu Jan 10 16:46:52 2002 jean-daniel michaud
##
#
CC	= gcc
AR	= ar -cr
RM	= rm -fr
#
SRC	= my_ctype.c\
	my_printfchar.c\
	my_printfnbr.c\
	my_printfnbr_base.c\
	my_printfstr.c\
	my_print_error.c
OBJS	= $(SRC:.c=.o)
#
NAME	= libmy_print_error_${HOSTTYPE}.a
IPATH	= -I.
CFLAGS	= $(IPATH) -Wall -g -pedantic -fstrict-prototypes -ansi -g
#
all	: $(OBJS)
	$(AR) $(NAME) $(OBJS)
	chmod 600 $(NAME) && mv $(NAME) ../
	cp my_print_error.h ../../include/
#
.c.o	:
	$(CC) $(CFLAGS) -c $<
#
re	: clean all
#
clean	:
	$(RM) *.core $(OBJS) *.*~ *~ \#* Makefile~
#
fclean	:
	$(RM) *.core $(OBJS) *.*~ *~ \#* Makefile~ $(NAME)


