##
## Makefile for le java c'est dla merde in 
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Mon Jun 17 14:12:31 2002 jean-daniel michaud
## Last update Fri Jun 21 17:16:34 2002 jean-daniel michaud
##

TEX	= latex
DVIPS	= dvips
RM	= rm -fr
JAR	= jar cvf
SRC	= rapport.tex
OBJ	= $(SRC:.tex=.dvi)
NAME	= rapport.ps
#
.SUFFIXES: .tex .dvi
#
all	: $(OBJ)
	$(TEX) $(SRC)
	$(TEX) $(SRC)
	$(DVIPS) $(OBJ) -o $(NAME)
#
show	: all
	gv $(NAME)
#
clean	:
	$(RM) *~
	$(RM) *core
	$(RM) \#*
	$(RM) missfont.log
	$(RM) rapport.log
#
fclean	: clean
	$(RM) $(NAME)
	$(RM) rapport.dvi
#
re	: clean all
