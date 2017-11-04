##
## Makefile for bistromathique in ~/c/rendu/projs/bistromathique
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Mon Oct  8 19:37:43 2001 jean-daniel michaud
## Last update Sun Oct 28 16:19:06 2001 jonathan mimouni
##

CC	= cc
OFLAGS	= -c 
FLAGS	= -pipe
WFLAGS	= -ansi -pedantic
RM	= rm -fr

NAME	= bistromathique
SRC	= bistromathique.c parser.c errors.c eval_str.c print.c\
	my_atoi_base.c utils.c list.c utils_str.c eval_str_plus.c\
	pile.c pile2.c parser_pile.c eval_str_sub.c eval_str_sub2.c\
	eval_str_sub3.c my_printnbr_base.c utils2.c utils_parser.c order.c\
	order_hop.c free.c karatsuba.c eval_str_mul.c eval_str_div.c\
	my_strcmp.c utils3.c pile3.c eval_str_div2.c
OBJS	= $(SRC:.c=.o)

all:	$(OBJS)
	$(CC) $(OBJS) -o $(NAME)

.c.o:	$(SRC)
	$(CC) $(OFLAGS) $<

clean:	
	$(RM) *.o
	$(RM) *.*~
	$(RM) \#*
	$(RM) *~

fclean:	clean
	$(RM) $(NAME)



