##
## Makefile for my_cat in ~/c/rendu/exos/cat
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Wed Oct 10 14:01:22 2001 jean-daniel michaud
## Last update Tue Oct 23 21:02:19 2001 Jean-Daniel Michaudf
##

CC	= gcc
OFLAGS	= -c
FLAGS	= -pipe -g
WFLAGS	= -Wall -fstrict-prototypes

AM	= ar 
ARFLAGS	= -cr
RM	= rm -fr
RANLIB	= ranlib

NAME	= libstream_${HOSTTYPE}.a
SRC	= my_fopen.c my_fclose.c my_fwrite.c my_fread.c my_fputc.c my_fputs.c\
	my_fflush.c my_fgetc.c my_fdopen.c my_fgetpos.c my_fpurge.c my_fgets.c\
	my_freopen.c my_fseek.c my_fsetpos.c my_rewind.c \
	my_ftell.c my_strlen.c 
OBJS	= $(SRC:.c=.o) 

all:	$(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	cc -L. main.c libstream_${HOSTTYPE}.a

.c.o:	$(SRC)
	$(CC) $(FLAGS) $(WFLAGS) $(OFLAGS) $<

clean:
	$(RM) *.o
	$(RM) *.*~
	$(RM) *~
	$(RM) \#*
#	$(RM) *.a


