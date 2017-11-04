##
## Makefile for sploum in 
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Thu Nov 22 17:29:32 2001 jean-daniel michaud
## Last update Tue Nov 27 22:42:53 2001 jean-daniel michaud
##
#
CC	= cc
AR	= ar -cr
RM	= rm -fr
GZIP	= tar zcvf
#
NAME	= sploum
IPATH	= -I../include
LPATH	= -L.
LNAME	= -lcurses -ltermcap
#
all	:
	cd src && make && cp $(NAME) ../ && cd ..
#
re	: clean all
#
clean	:
	cd src && make clean && cd .. && $(RM) sploum
#
comp	: clean
	cd .. && $(GZIP) sploum.tgz sploum && chmod 600 sploum.tgz && cd sploum



