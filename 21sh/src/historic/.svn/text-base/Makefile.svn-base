##
## Makefile for 21sh in 
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Thu Dec  6 16:35:05 2001 jean-daniel michaud
## Last update Sun Dec 30 23:25:47 2001 jean-daniel michaud
##

CC	= gcc
RM	= rm -fr
AR	= ar -cr
#
NAME	= libhistoric_$(HOSTTYPE).a
SRC	= historic.c
OBJS	= $(SRC:.c=.o)
CFLAGS_NetBSD	= -pipe -ggdb3
WFLAGS_NetBSD	= -Wstrict-prototypes -Wall -pedantic 			\
	-Wpointer-arith -Waggregate-return -Wmissing-prototypes 	\
	-Wnested-externs -ansi -Wparentheses -W -Wreturn-type -Wshadow
WFLAGS_FreeBSD	= -Wstrict-prototypes -Wall -pedantic 			\
	-Wpointer-arith -Waggregate-return -Wmissing-prototypes 	\
	-Wnested-externs -ansi -Wparentheses -W -Wreturn-type -Wshadow
IPATH	= -I../../include
LPATH	= -L../../lib/
LIBPATH	= ../../lib/
#
all	: $(OBJS)
	$(AR) $(NAME) $(OBJS)
	mv $(NAME) $(LIBPATH)

#
.c.o	:
	$(CC) $(IPATH) $(CFLAGS) $(WFLAGS_$(HOSTTYPE)) -c $<
#
clean	:
	$(RM) \#* *~ *o
	$(RM) $(LIBPATH)$(NAME)
#
re	: clean all
