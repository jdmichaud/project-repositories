#
# Makefile
#  
# Made by (Florent Monbillard)
# Login   <monbil_f@epita.fr>
#
# Started on Fri Nov 23 12:13:30 2001 Florent Monbillard
## Last update Mon Dec 31 10:09:20 2001 jonathan mimouni
# 
##############################
# Complete this to make it ! #
##############################
NAME 	= libenv_var_$(HOSTTYPE).a		# Name of executable file
SRC	= parser_env_var.c parser_env_var_2.c
# List of *.c
INCL  	= #struct.h env_var.h list_env_var.h my_malloc.h	# List of *.h
LIBPATH	= ../../lib/
################
# Optional add #
################
IPATH   = -I../../include/		        # path of include file
OBJOPT_ = -ggdb3
OBJOPT_NetBSD = -ggdb3
OBJOPT_alpha = -g2
OBJOPT_sun4 = 
EXEOPT_NetBSD = -ggdb3
EXEOPT_alpha = 
EXEOPT_sun4 = 
WARNOPT_ = -Wstrict-prototypes -Wall -pedantic -Wpointer-arith \
	-Waggregate-return -Wmissing-prototypes -Wnested-externs -ansi \
	-Wredundant-decls -Wparentheses -W -Wreturn-type -Wshadow \
	-Wtraditional
WARNOPT_NetBSD = -Wstrict-prototypes -Wall -pedantic -Wpointer-arith \
	 -Waggregate-return -Wmissing-prototypes -Wnested-externs -ansi \
	-Wparentheses -W -Wreturn-type -Wshadow -Wtraditional
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
AR	= ar
RANLIB	= ranlib
MAKE 	= make
SHELL	= /bin/sh
OBJS 	= $(SRC:.c=.o)
RM 	= /bin/rm -f
COMP	= gzip -9v
UNCOMP	= gzip -df
STRIP	= strip
MV	= mv

ARFLAGS = -rc
CFLAGS  = $(OBJOPT) $(IPATH)
LDFLAGS = $(EXEOPT) $(LPATH)

.SUFFIXES: .h.Z .c.Z .h.gz .c.gz .c.z .h.z

##############################
# Basic Compile Instructions #
##############################

all:	$(NAME)

$(NAME): $(OBJS) $(SRC) $(INCL)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)
	$(MV) $(NAME) $(LIBPATH)

depend:	
	gcc $(IPATH) -MM $(SRC)

re:	clean all

clean:	
	-$(RM) $(OBJS) a.out main.o *~ *.core 

fclean:	clean
	-$(RM) $(LIBPATH)$(NAME)

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
