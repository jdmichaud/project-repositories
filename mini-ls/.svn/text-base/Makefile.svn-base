##
## Makefile for my_cat in ~/c/rendu/exos/cat
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Wed Oct 10 14:01:22 2001 jean-daniel michaud
## Last update Tue Nov 20 02:35:27 2001 jean-daniel michaud
##

CC	= cc
NAME	= mini-ls
RM	= rm -fr
#
SRC	= error.c		\
	get_option.c		\
	get_type.c		\
	list_args.c		\
	list_file.c		\
	ls.c			\
	mini-ls.c		\
	my_ctype.c		\
	my_printf.c		\
	my_printfchar.c		\
	my_printfnbr.c		\
	my_printfnbr_base.c	\
	my_printfstr.c		\
	my_strcmp.c		\
	my_strdup.c		\
	sort.c			\
	show.c			\
	utils.c
OBJS	= $(SRC:.c=.o)
#
PPATH	= ${HOME}/c/rendu/mini-ls
WFLAGS	= 
CFLAGS	= $(WFLAGS) $(IPATH)
#
all	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)
#
.c.o	:
	$(CC) -c $(CFLAGS) $(LPATH) $<
#
lib	: mlib all
#
mlib	:
	cd my_printf && make && cd ..
	cd my_print_error && make && cd ..
#
clean	:
	$(RM) *.o
	$(RM) *.*~
	$(RM) *~
	$(RM) \#*
#
re	: clean all
#
fclean	: clean
	$(RM) $(NAME)
#
cleanl	:
	cd my_printf && make fclean && cd ..
	cd my_print_error && make fclean && cd ..

