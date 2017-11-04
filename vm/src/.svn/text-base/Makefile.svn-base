##
## Makefile for Makefile in 
## 
## Made by romain bottier
## Login   <bottie_r@epita.fr>
## 
## Last update Sat Jan 12 12:47:27 2002 julien gein
#
CC	= gcc
#
SRC	= add.c			\
	and.c			\
	asr.c			\
	bnz.c			\
	boot.c			\
	bz.c			\
	cycle.c			\
	dbg_call.c		\
	dbg_cmd.c		\
	dbg_dump.c		\
	dbg_get_cmd.c		\
	dbg_parse.c		\
	dbg_print.c		\
	dbg_sm.c		\
	debug.c			\
	dec.c			\
	die.c			\
	fl.c			\
	fork.c			\
	inc.c			\
	init.c			\
	jmp.c			\
	kvm.c			\
	live.c			\
	lc.c			\
	ld.c			\
	ll.c			\
	lp.c			\
	lsl.c			\
	lsr.c			\
	mov.c			\
	mem.c			\
	neg.c			\
	not.c			\
	op_fct.c		\
	options.c		\
	or.c			\
	player.c		\
	pop.c			\
	proc_access.c		\
	process.c		\
	push.c			\
	register.c		\
	rol.c			\
	rsb.c			\
	st.c			\
	run.c			\
	stack.c			\
	stat.c			\
	stream.c		\
	sub.c			\
	swp.c			\
	xor.c			\
	write.c			\
	vm_load_file.c		\
	vm_load_file2.c		\
	vm_load_map.c		\
	vm_little_endian.c	\
	vm_decode_instr.c	\
	vm_decode_instr2.c	\
	vm_op1.c		\
	vm_op2.c		\
	vm_op3.c		\
	vm_op4.c		\
	vm_op5.c		\
	vm_op6.c		\
	vm_op7.c
#
OBJS	= $(SRC:.c=.o)
#
NAME	= kvm
IPATH	= -I../include -I../ -I/usr/X11R6/include
#
DFLAGS		= #-DDEBUG___
CFLAGS_NetBSD	= $(IPATH) -Wall -g -pedantic -fstrict-prototypes -ansi -pipe \
		-Wimplicit -Wmissing-prototypes -Wparentheses 	\
		-Wswitch -Wstrict-prototypes -Wpointer-arith -Wreturn-type    \
		-Wmissing-declarations -Wtraditional -Wreturn-type   \
		-funsigned-char -Wimplicit-int
#
CFLAGS_alpha	= $(IPATH) -Wall -g -pedantic -fstrict-prototypes -ansi
CFLAGS_sun4	= $(IPATH) -Wall -g -pedantic -fstrict-prototypes
#
LDLIBS_NetBSD	= #-lefence_$(HOSTTYPE)
LDLIBS_alpha	= 
LDLIBS_sun4	= 
#
CFLAGS	= $(CFLAGS_$(HOSTTYPE)) $(DFLAGS)
LDLIBS	= -lxvm_$(HOSTTYPE) -lsdata_$(HOSTTYPE) -lprintf_$(HOSTTYPE) \
	-lmy_$(HOSTTYPE) -lmy_print_error_${HOSTTYPE} \
	-ldlist_$(HOSTTYPE) -lX11 $(LDLIBS_$(HOSTTYPE))
LDFLAGS	= -L${HOME}/pub -L../lib -L/usr/X11R6/lib/
#
RM	= rm -f
#
all	: $(NAME)
#
$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(NAME) $(LDLIBS)
#
clean	: 
	$(RM) *.core $(OBJS) *~ \#* $(NAME)
#
re	: clean all


