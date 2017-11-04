##
## Makefile for regis in 
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Wed Dec  5 14:04:58 2001 jean-daniel michaud

##

CC	= gcc -ggdb3
RM	= rm -fr
#
NAME	= mftp
SRC	= cmdline.c	\
	connect.c	\
	comm.c		\
	dcmd.c		\
	error.c		\
	ftp1.c		\
	ftp2.c		\
	ftp3.c		\
	ftp4.c		\
	ftp5.c		\
	ftp6.c		\
	ftp7.c		\
	ftp8.c		\
	init.c		\
	list.c		\
	log.c		\
	login.c		\
	main.c		\
	option.c	\
	services.c	\
	signals.c	\
	user.c		\
	utils.c		\
	xmalloc.c
OBJS	= $(SRC:.c=.o)
#
CFLAGS_NetBSD	= -pipe -Wstrict-prototypes -pedantic 			\
	-Wpointer-arith -Waggregate-return -Wmissing-prototypes 	\
	-Wnested-externs -ansi -Wparentheses -W -Wreturn-type 		\
	-Wshadow -Wtraditional
CFLAGS_alpha	=  -Wstrict-prototypes -pedantic 			\
	-Wpointer-arith -Waggregate-return -Wmissing-prototypes 	\
	-Wnested-externs -ansi -Wparentheses -W -Wreturn-type 		\
	-Wshadow -Wtraditional
CFLAGS_sun4	= -Wstrict-prototypes -pedantic 			\
	-Wpointer-arith -Waggregate-return -Wmissing-prototypes 	\
	-Wnested-externs -Wparentheses -W -Wreturn-type 		\
	-Wshadow -Wtraditional
IPATH	= -I../include
LPATH	= -L.
LIB_NetBSD 	= -lcrypt
LIB_alpha	=
LIB_sun4	= -lsocket -lnsl

#
all	: $(OBJS)
	$(CC) $(IPATH) $(LPATH) $(CFLAGS_$(HOSTTYPE)) $(OBJS) -o $(NAME) \
	$(LIB_$(HOSTTYPE))
.c.o	:
	$(CC) $(IPATH) $(CFLAGS_$(HOSTTYPE)) -c $<
#
clean	: fclean
	$(RM) *o *c~ *~ Makefile~ \#* $(PARSER)
#
fclean	:
	$(RM) $(NAME)
#
re	: clean all
