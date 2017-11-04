##
## Makefile for minimake in 
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Sat Feb 16 08:08:58 2002 jean-daniel michaud
## Last update Sat Feb 23 18:17:41 2002 jean-daniel michaud
##
#
NAME	= minimake
#
all:
	cd src && make && cp $(NAME) ../ && cd ..
#
clean:
	cd src && make clean && cd .. && rm -fr $(NAME) *~ \#*
#
re: clean all