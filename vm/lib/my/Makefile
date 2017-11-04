##
## Makefile for  in 
## 
## Made by GIZMO
## Login   <grimau_r@epita.fr>
## 
## Started on  Wed Oct  3 20:40:23 2001 GIZMO
## Last update Thu Jan 10 17:37:42 2002 jean-daniel michaud
##
#
CC		= gcc
#
SRC		= my_atoi.c		\
		my_atoi_base.c		\
		my_factorielle.c	\
		my_is_prime.c		\
		my_isalpha.c		\
		my_isdigit.c		\
		my_islower.c		\
		my_isnum.c		\
		my_isprint.c		\
		my_isupper.c		\
		my_nbrcmp.c		\
		my_nbrlen.c		\
		my_power.c		\
		my_printchar.c		\
		my_printnbr.c		\
		my_printnbr_base.c	\
		my_printstr.c		\
		my_revstr.c		\
		my_showmem.c		\
		my_square.c		\
		my_strcat.c		\
		my_strcmp.c		\
		my_strcpy.c		\
		my_strdup.c		\
		my_strlen.c		\
		my_strlowcase.c		\
		my_strncmp.c		\
		my_strncpy.c		\
		my_strndup.c		\
		my_strupcase.c		\
		my_xmalloc.c

OBJS		= $(SRC:.c=.o)
#
LIB		= my
LNAME		= lib$(LIB)_$(HOSTTYPE).a
CFLAGS		= -O2 -Wall -pedantic -fstrict-prototypes -ansi -fsigned-char \
		-Wformat -Wimplicit -Wmissing-prototypes -Wparentheses -W     \
		-Wswitch -Wstrict-prototypes -Wpointer-arith -Wreturn-type    \
		-Wmissing-declarations -Wtraditional -Wunused -Wuninitialized \
		-fthis-is-variable -funsigned-char -Waggregate-return -Werror \
		-Wimplicit-int -Wcast-align -Wreturn-type		      \
		-Wimplicit-function-declaration	-g
#
all		: $(LNAME)
#
$(LNAME)	: $(OBJS)
		ar rc $(LNAME) $(OBJS)
		ranlib $(LNAME)
		chmod 600 $(LNAME) && mv $(LNAME) ../
		cp my.h ../../include/
#
clean		:
		rm -f *.core $(OBJS) *~ #*#
#
fclean		: clean
		rm -f ../$(LNAME) $(LNAME)





