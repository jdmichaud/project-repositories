##
## Makefile for Makefile in 
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Wed Oct 24 16:19:46 2001 jean-daniel michaud
## Last update Mon Nov 12 15:10:55 2001 jean-daniel michaud
##
#
CC		= gcc
AR		= ar -cr
RM		= rm -fr
LEX		= flex
#
LEXIC		= parser.l
PARSER		= $(LEXIC:.l=.c)
SRC		= beswitch.c				\
		errors.c				\
		list.c					\
		utils.c					\
		my_strdup.c				\
		output.c				\
		tree.c					\
		$(PARSER)				
OBJS		= $(SRC:.c=.o)
#
NAME		= beswitch
LIBS		= libprintf_${HOSTTYPE}.a libprint_error_${HOSTTYPE}.a
IPATH		= -I.
LPATH		= -L.
CFLAGS		= $(IPATH) -Wstrict-prototypes
#
all	: $(PARSER) $(OBJS)
	$(CC) $(LPATH) $(OBJS) -o $(NAME) $(LIBS)
#
lib	: mlib all
#
.c.o	:
	$(CC) $(CFLAGS) -c $<
#
.l.c	:
	$(LEX) < $<
	mv lex.yy.c $(PARSER)
#
re	: clean all
#
mlib	:
	cd my_printf && make && cd ..
	cd my_print_error && make && cd ..
#
clean	:
	$(RM) *.core $(OBJS) *.*~ *~ \#* Makefile~ $(PARSER)
#
cleanl	:
	cd my_printf && make fclean && cd ..
	cd my_print_error && make fclean && cd ..
#
fclean	: clean cleanl
	$(RM) $(NAME)
	$(RM) $(PARSER)
	$(RM) *.a

