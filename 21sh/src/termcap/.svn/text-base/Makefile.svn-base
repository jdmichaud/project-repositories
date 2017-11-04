#
# Makefile
#  
# Made by (Florent Monbillard)
# Login   <monbil_f@epita.fr>
#
# Started on Fri Nov 23 12:13:30 2001 Florent Monbillard
## Last update Mon Dec 31 13:01:43 2001 Florent Monbillard
# 
##############################
# Complete this to make it ! #
##############################
NAME 	= libtermcap_$(HOSTTYPE).a			# Name of executable file
SRC	=  termcap.c exec_char.c exec_arrow.c exec_ctrl.c exec_ctrl_sup_m.c \
	init_termcap.c x.c treat.c realloc.c change_line.c
INCL  	= # init_termcap.h  exec_char.h exec_arrow.h exec_ctrl.c x.h exec_ctrl_sup_m.h treat.h
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
WARNOPT_ = -Wstrict-prototypes -Wall -Wpointer-arith \
	-Waggregate-return -Wmissing-prototypes -Wnested-externs -ansi \
	-Wredundant-decls -Wparentheses -W -Wreturn-type -Wshadow \
	-Wtraditional
WARNOPT_NetBSD = -Wstrict-prototypes -Wall  -Wpointer-arith \
	 -Waggregate-return -Wmissing-prototypes -Wnested-externs -ansi \
	-Wparentheses -W -Wreturn-type -Wshadow -Wtraditional
WARNOPT_alpha = -w2 -std1 -warnprotos
WARNOPT_sun4 = #-Xc -xstrconst
WARNOPT = $(WARNOPT_$(HOSTTYPE))
OBJOPT  = $(OBJOPT_$(HOSTTYPE)) $(WARNOPT_$(HOSTTYPE)) 	# option for obj
EXEOPT  = $(EXEOPT_$(HOSTTYPE))	-ltermcap           	# option for exe (-O2 -g2 -w -lm ...)
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
#	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)
	$(MV) $(NAME) $(LIBPATH)

depend:	
	gcc $(IPATH) -MM $(SRC)

re:	clean all

clean:	
	-$(RM) $(OBJS) *~ *.core
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
