##
## Makefile for Makefile in 
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Wed Oct 24 16:19:46 2001 jean-daniel michaud
## Last update Thu Jan 10 17:37:55 2002 jean-daniel michaud
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
	my_printf.c
OBJS	= $(SRC:.c=.o)
#
NAME	= libprintf_${HOSTTYPE}.a
IPATH	= -I.
CFLAGS	= $(IPATH) -Wall -g -pedantic -fstrict-prototypes -ansi
#
all	: $(OBJS)
	$(AR) $(NAME) $(OBJS)
	chmod 600 $(NAME) && mv $(NAME) ../
	cp my_printf.h ../../include/
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


