##
## Makefile for 21sh in 
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Thu Dec  6 16:35:05 2001 jean-daniel michaud
## Last update Thu Dec  6 17:21:40 2001 jean-daniel michaud
##

CC	= cc
RM	= rm -fr
AR	= ar -cr
#
NAME	= liberror_$(HOSTTYPE).a
SRC	= error.c
OBJS	= $(SRC:.c=.o)
CFLAGS	= -pipe
WFLAGS	= -Wstrict-prototypes -Wall -pedantic -Wpointer-arith  \
	-Waggregate-return -Wmissing-prototypes -Wnested-externs -ansi \
	-Wparentheses -W -Wreturn-type -Wshadow -Wtraditional
IPATH	= -I../../include
LPATH	= ../../lib/
#
all	: $(OBJS)
	$(AR) $(NAME) $(OBJS)
	ranlib $(NAME)
	mv $(NAME) $(LPATH)
#
.c.o	:
	$(CC) $(IPATH) $(CFLAGS) $(WFLAGS_$(HOSTTYPE)) -c $<
#
clean	:
	$(RM) \#* *~ *o
	$(RM) $(LPATH)$(NAME)
#
re	: clean all
