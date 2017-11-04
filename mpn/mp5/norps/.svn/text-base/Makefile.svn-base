##
## Makefile for lddump in 
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Thu Nov 29 21:01:55 2001 jean-daniel michaud
## Last update Tue Dec  4 16:36:56 2001 jean-daniel michaud
##

CC	= cc
RM	= rm -fr
CFLAGS	= -ggdb3
#
SRC	= cmd_func.c		\
	format_params.c		\
	io.c			\
	is_func.c		\
	libs.c			\
	libs_error.c		\
	list.c			\
	my_ctype.c		\
	my_ctype2.c		\
	my_xmalloc.c		\
	norps.c			\
	parser.c		\
	parse_error.c		\
	parse_func.c		\
	sub_parsing.c		\
	utils.c			\
	vars.c
OBJS	= $(SRC:.c=.o)
#
NAME	= norps
#
all	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L/usr/pkg/lib -lefence
#
.c.o	:
	$(CC) -c $(CFLAGS) $<
#
clean	:
	$(RM) *.o *~ \#* Makefile~ $(NAME)
#
re	: clean all

