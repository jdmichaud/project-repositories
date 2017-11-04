CC	= g++
NAME	= nn
RM	= rm -fr
#
SRC	= particle.cc	\
	nn.cc	
OBJ	= $(SRC:.cc=.o)
#
LDLIBS	= 
CFLAGS	= -Wall -O3 #-ggdb3
#
all	: $(NAME)
#
$(NAME)	: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDLIBS)
#
.cc.o	:
	$(CC) $(CFLAGS) -c $<
#
clean	:
	$(RM) *o *~ *.~ \#* $(NAME) *.core
re	: clean all