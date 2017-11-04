##
## Makefile for 21sh in 
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Thu Dec  6 16:35:05 2001 jean-daniel michaud
## Last update Mon Dec 31 12:56:44 2001 Florent Monbillard
##

CC	= cc
RM	= rm -fr
AR	= ar -cr
#
NAME	= libutils_$(HOSTTYPE).a
SRC	= list.c	\
	xmalloc.c
OBJS	= $(SRC:.c=.o)
CFLAGS	= #-pipe
WFLAGS_NetBSD	= -Wstrict-prototypes -Wall -pedantic -Wpointer-arith  \
	-Waggregate-return -Wmissing-prototypes -Wnested-externs -ansi \
	-Wparentheses -W -Wreturn-type -Wshadow -Wtraditional -g
IPATH	= -I../../include
LPATH	= ../../lib/
#
all	: $(NAME)
	$(AR) $(NAME) $(OBJS)
	ranlib $(NAME)
	mv $(NAME) $(LPATH)
#	
$(NAME) : $(OBJS)
#
.c.o	:
	$(CC) $(IPATH) $(CFLAGS) $(WFLAGS_$(HOSTTYPE)) -c $<
#
clean	:
	$(RM) \#* *~ *o
	$(RM) $(LPATH)$(NAME)
#
re	: clean all


