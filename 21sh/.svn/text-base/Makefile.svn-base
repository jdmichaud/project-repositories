#
#
# Makefile
#  
# Made by (Florent Monbillard)
# Login   <monbil_f@epita.fr>
#
# Started on Fri Dec  7 04:04:37 2001 Florent Monbillard
## Last update Mon Dec 31 15:31:48 2001 jean-daniel michaud
# 
##############################
# Complete this to make it ! #
##############################
NAME 	= 21sh			# Name of executable file
SRC	=			# List of *.c
INCL  	=			# List of *.h
################
# Optional add #
################
IPATH   = -I.  		        # path of include file
OBJOPT_ = -ggdb3
OBJOPT_NetBSD = -ggdb3
OBJOPT_alpha = -g2
OBJOPT_sun4 = 
EXEOPT_NetBSD = -ggdb3
EXEOPT_alpha = 
EXEOPT_sun4 = 
WARNOPT_ = -Werror -Wstrict-prototypes -Wall -pedantic -Wpointer-arith -Waggregate-return -Wmissing-prototypes -Wnested-externs -ansi -Wredundant-decls -Wparentheses -W -Wreturn-type -Wshadow -Wtraditional
WARNOPT_NetBSD = -Werror -Wstrict-prototypes -Wall -pedantic -Wpointer-arith -Waggregate-return -Wmissing-prototypes -Wnested-externs -ansi -Wparentheses -W -Wreturn-type -Wshadow -Wtraditional
WARNOPT_alpha = -w2 -std1 -warnprotos
WARNOPT_sun4 = -Xc -xstrconst  
WARNOPT = $(WARNOPT_$(HOSTTYPE))
OBJOPT  = $(OBJOPT_$(HOSTTYPE)) $(WARNOPT_$(HOSTTYPE)) 	# option for obj
EXEOPT  = $(EXEOPT_$(HOSTTYPE))		           	# option for exe (-O2 -g2 -w -lm ...)
LPATH   = -L.           	# path for librairies ...

#####################
# Macro Definitions #
#####################
CC 	= cc
MAKE 	= make
SHELL	= /bin/sh
OBJS 	= $(SRC:.c=.o)
RM 	= /bin/rm -f
COMP	= gzip -9v
UNCOMP	= gzip -df
STRIP	= strip

CFLAGS  = $(OBJOPT) $(IPATH)
LDFLAGS = $(EXEOPT) $(LPATH)

.SUFFIXES: .h.Z .c.Z .h.gz .c.gz .c.z .h.z

##############################
# Basic Compile Instructions #
##############################

all:	$(NAME)

$(NAME): 
	cd src && make && cp 21sh ..
depend:	
	gcc $(IPATH) -MM $(SRC)

re:	clean all

clean:	
	cd lib && rm -fr *a && cd ..
	cd src && make clean
	-$(RM) $(NAME) *~ *.core

comp: clean
	$(COMP) $(INCL) $(SRC)
ucomp: 
	$(UNCOMP) $(SRC) $(INCL)

.c.Z.c .h.Z.h .c.gz.c .h.gz.h .c.z.c .h.z.h :
	 -$(UNCOMP) $<

.c.o:
	$(CC) $(CFLAGS) -c $< 
################
# Dependencies #
################
