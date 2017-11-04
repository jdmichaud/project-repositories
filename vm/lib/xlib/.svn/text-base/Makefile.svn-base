##
## Makefile for  in 
## 
## Made by julien gein
## Login   <gein_j@epita.fr>
## 
## Started on  Fri Jan  4 13:38:54 2002 julien gein
## Last update Sat Jan 12 12:07:52 2002 julien gein
##
#
CC	= gcc
RM	= rm -rf
#
SRC	= display_init.c	\
	display_str.c		\
	display_primitives.c	\
	display_regs.c		\
	display_mem.c		\
	display_memfunc.c	\
	display_infos.c		\
	display_players.c	\
	display_playersfunc.c	\
	display_attr.c		\
	display_refresh.c	\
	display_getnotifies.c	\
	display_misc.c		\
	display_exit.c		\
	display_update.c	\
	cfg_parsefile.c		\
	cfg_parsefunc.c		\
	cfg_parsescan.c		\
	cfg_vars.c		\
	init_xserver.c		\
	get_buffer.c
OBJS	= $(SRC:.c=.o)
#
IPATH	= -I/usr/X11R6/include/ -I../../include
CFLAGS	= -Wall $(IPATH) -g
#
LNAME	= libxvm_$(HOSTTYPE).a
#
all	: $(OBJS)
	ar rc $(LNAME) $(OBJS)
	ranlib $(LNAME)
	chmod 600 $(LNAME) && cp $(LNAME) ../
	cp display.h ../../include
#
clean	:
	$(RM) $(OBJS) $(NAME) *.o *~
#
re	: clean all
#
fclean	: clean all

