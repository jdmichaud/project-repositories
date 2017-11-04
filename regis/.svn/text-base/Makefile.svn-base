##
## Makefile for regis in 
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Wed Dec  5 14:04:58 2001 jean-daniel michaud
## Last update Mon Dec 10 18:10:11 2001 jean-daniel michaud
##

CC	= gcc
RM	= rm -fr
#
NAME	= regis
LEXIC	= parser.l
PARSER	= $(LEXIC:.l=.c)
SRC	= algo.c	\
	debug.c		\
	graph.c		\
	list.c		\
	list_utils.c	\
	mkgraph.c	\
	regis.c		\
	tab.c		\
	utils.c		\
	xmalloc.c	\
	$(PARSER)
OBJS	= $(SRC:.c=.o)
#
CFLAGS	= -pipe -Wall
#
all	: $(PARSER) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
#
.l.c	:
	$(LEX) < $<
	mv lex.yy.c $(PARSER)
#
.c.o	:
	$(CC) $(CFLAGS) -c $<
#
clean	: fclean
	$(RM) *o *c~ *~ Makefile~ \#* $(PARSER)
#
fclean	:
	$(RM) $(NAME)
#
re	: clean all
