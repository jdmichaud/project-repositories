##
## Makefile for Makefile in 
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Wed Oct 24 16:19:46 2001 jean-daniel michaud
## Last update Mon Nov  5 16:17:21 2001 jean-daniel michaud
##
#
CC	= gcc
AR	= ar -cr
RM	= rm -fr
#
SRC	= my_ctype.c\
	my_printchar.c\
	my_printnbr.c\
	my_printnbr_base.c\
	my_printstr.c\
	my_printf.c
OBJS	= $(SRC:.c=.o)
#
NAME	= libprintf_${HOSTTYPE}.a
IPATH	= -I.
CFLAGS	= $(IPATH) -Wall -Wstrict-prototypes
#
all	: $(OBJS)
	$(AR) $(NAME) $(OBJS)
#
.c.o	:
	$(CC) $(CFLAGS) -c $<
#
re	:
	$(RM) *.core $(OBJS) *.*~ *~ \#* Makefile~ $(NAME)
	$(CC) $(CFLAGS) -c $(SRC)
	$(AR) $(NAME) $(OBJS)
#
clean	:
	$(RM) *.core $(OBJS) *.*~ *~ \#* Makefile~
#
fclean	:
	$(RM) *.core $(OBJS) *.*~ *~ \#* Makefile~ $(NAME)


