##
## Makefile for Makefile in 
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Wed Oct 24 16:19:46 2001 jean-daniel michaud
## Last update Mon Nov 12 11:43:30 2001 jean-daniel michaud
##
#
CC	= gcc
AR	= ar rc
RM	= rm -f
#
SRC	= my_ctype.c		\
	my_printfchar.c		\
	my_printfnbr.c		\
	my_printfnbr_base.c	\
	my_printfstr.c		\
	my_printf.c
OBJS	= $(SRC:.c=.o)
#
LIB	= printf
LNAME	= lib$(LIB)_${HOSTTYPE}.a
IPATH	= -I.
CFLAGS	= -Wall -fstrict-prototypes $(IPATH)
#
all	: $(OBJS)
	$(AR) $(LNAME) $(OBJS)
	ranlib $(LNAME)
	chmod 600 $(LNAME) && mv $(LNAME) ../
	cp my_printf.h ../
#
re	: clean all
#
clean	:
	$(RM) *.core $(OBJS) *.*~ *~ \#* Makefile~
#
fclean	: clean
	$(RM) $(LNAME)


