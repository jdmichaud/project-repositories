##
## Makefile for putain yen a marre de ces projs de daube in 
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Mon Jun 17 14:28:14 2002 jean-daniel michaud
## Last update Fri Jun 28 21:15:57 2002 jean-daniel michaud
##

DOC	= rapport.ps

all	:
	cd src && make
doc	:
	cd modelisation && make && mv $(DOC) ../
	cd doc && make
clean	:
	cd src && make clean
	cd modelisation && make clean
	cd doc && make clean
fclean	:
	cd src && make fclean
	cd modelisation && make fclean
	cd doc && make clean
re	:
	cd src && make re
	cd modelisation && make re
	cd doc && make clean
