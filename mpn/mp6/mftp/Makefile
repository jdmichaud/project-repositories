##
## Makefile for regis in 
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Wed Dec  5 14:04:58 2001 jean-daniel michaud

##

CC	= gcc
RM	= rm -fr
#
NAME	= mftp
#
all	:
	cd src && make && mv $(NAME) ../ && cd ..
#
clean	:
	cd src && make clean && cd .. && $(RM) $(NAME) *~
#
re	: clean all
