##
## Makefile for minimake in 
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Sat Feb 16 07:05:19 2002 jean-daniel michaud
## Last update Sat Feb 23 18:17:17 2002 jean-daniel michaud
#
CC	= g++
LEX	= flex
YACC	= bison
RM	= rm -fr
#
NAME	= minimake
#
SRC	= graph.cc	\
	main.cc		\
	node.cc		\
	options.cc	\
	parse.cc	\
	rules.cc	\
	stat.cc		\
	$(OLEX)		\
	$(OYACC)
ILEX	= scan_make.ll
IYACC	= parse_make.yy
OBJ	= $(SRC:.cc=.o)
OLEX	= $(ILEX:.ll=.cc)
OYACC	= $(IYACC:.yy=.cc)
#
IPATH	= -I ../include
CFLAGS	= $(IPATH) -Wall -ggdb3 -pedantic -fstrict-prototypes -ansi	\
	-pipe -Wimplicit -Wmissing-prototypes -Wparentheses   		\
	-Wswitch -Wstrict-prototypes -Wpointer-arith -Wreturn-type    	\
	-Wmissing-declarations -Wtraditional -Wreturn-type   		\
	-funsigned-char -Wimplicit-int
#
.PHONY:	clean re all
.SUFFIXES: .cc .ll .o .yy
#
all: $(NAME)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
#
$(NAME): $(OLEX) $(OYACC) $(OBJ)
#
.cc.o:
	$(CC) $(CFLAGS) -c $<
#
.ll.cc:
	$(LEX) $< && mv lex.yy.c $(OLEX)
#
.yy.cc:
	$(YACC) $< -o $(OYACC)
#
clean:
	$(RM) *o *.o *~ *.~ *core *.core $(NAME) $(OLEX) $(OYACC) \
	\#* *.output *.tab.c ../include/*~ ../include/\#*
#
re: clean all
#
debug:
	echo "fuck"