##
## Makefile for 21sh in 
## 
## Made by Florent Monbillard
## Login   <monbil_f@epita.fr>
## 
## Started on  Thu Dec  6 14:57:40 2001 Florent Monbillard
## Last update Mon Dec 31 14:10:00 2001 jean-daniel michaud
##
NAME	= 21sh
SRC	= 21sh.c end.c init.c	
RM	= rm -fr
GZIP	= tar zcvf
#
OBJS 	= $(SRC:.c=.o)
LIBS	= -lbuiltins_$(HOSTTYPE) -lparser_line_$(HOSTTYPE) \
	-lparser_list_cmd_$(HOSTTYPE) -lcmdline_$(HOSTTYPE) \
	-lprocess_$(HOSTTYPE) -lutils_$(HOSTTYPE) \
	-lbuiltins_$(HOSTTYPE) -ltermcap_$(HOSTTYPE) -lhistoric_$(HOSTTYPE) \
	-lenv_var_$(HOSTTYPE) -lmeta_$(HOSTTYPE) -lformat_line_$(HOSTTYPE) \
	-ltermcap #-lefence
#
IPATH   = -I../include/  		        # path of include file
OBJOPT_ = -ggdb3
OBJOPT_NetBSD = -ggdb3
OBJOPT_alpha = -g2
OBJOPT_sun4 = 
EXEOPT_NetBSD = -ggdb3
EXEOPT_alpha = 
EXEOPT_sun4 = 
WARNOPT_ = -Wstrict-prototypes -Wall -pedantic -Wpointer-arith \
	-Waggregate-return -Wmissing-prototypes -Wnested-externs -ansi \
	-Wredundant-decls -Wparentheses -W -Wreturn-type -Wshadow -Wtraditional
WARNOPT_NetBSD = -Wstrict-prototypes -Wall -pedantic -Wpointer-arith \
	-Waggregate-return -Wmissing-prototypes -Wnested-externs -ansi \
	-Wparentheses -W -Wreturn-type -Wshadow -Wtraditional
WARNOPT_alpha = -w2 -std1 -warnprotos
WARNOPT_sun4 = #-Xc -xstrconst
OBJOPT  = $(OBJOPT_$(HOSTTYPE)) $(WARNOPT_$(HOSTTYPE)) 
EXEOPT  = $(EXEOPT_$(HOSTTYPE))
LPATH   = -L../lib -L/usr/pkg/lib           			# path for librairies ...
CFLAGS  = $(OBJOPT) $(IPATH)
LDFLAGS = $(EXEOPT) $(LPATH) $(LIBS)
#
all	: $(NAME)
#
$(NAME) : $(OBJS)
	cd builtins && make && cd ..
	cd env_var  && make && cd ..
	cd meta && make && cd ..
	cd parser_line && make && cd ..
	cd parser_list_cmd && make && cd ..
	cd cmdline && make && cd ..
	cd process && make && cd ..
	cd historic && make && cd ..
	cd utils && make && cd ..
	cd termcap && make && cd ..
	cd parser && make && cd ..
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)
#
clean	:
	cd builtins && make clean && cd ../meta && make clean && \
	cd ../cmdline && make clean && cd ../env_var && make clean \
	&& cd ../parser_list_cmd && make clean && cd ../parser_line && \
	make clean && cd ../process && make clean && cd ../utils && \
	make clean && cd ../termcap && make clean && cd ../historic && \
	make clean && cd .. && cd parser && make clean && cd ..
	$(RM) *~ *.core *.o $(NAME)
re	: clean all
#
comp    : clean
	cd .. && $(GZIP) 21sh.tgz 21sh && chmod 600 21sh.tgz && cd 21sh
#
.c.o:
	$(CC) $(CFLAGS) -c $<

