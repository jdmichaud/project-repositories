##
## Makefile for le java c'est dla merde in 
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Mon Jun 17 14:12:31 2002 jean-daniel michaud
## Last update Fri Jun 28 16:28:41 2002 jean-daniel michaud
##

REP	= ../src/
JAVADOC	= javadoc
RM	= rm -fr
JAR	= jar cvf
SRC	= DBQuery.java          \
        DBQueryFactory.java     \
        DBQueryPerformer.java   \
        DBQueryPerformerLoader.java \
        JDBCPerformer.java      \
        StandardDBFactory.java  \
        TAction.java            \
	TBoard.java		\
	TCase.java 		\
	TClientGame.java        \
	TDBStandard.java        \
	TDefaultHistory.java    \
	TDisplayControler.java  \
	TDistLocation.java      \
	TDrawable.java          \
	TEat.java		\
        TEntity.java            \
	TGame.java 		\
	TGraphicContext.java	\
	THexagonBoard.java      \
	THexagonCase.java       \
	THexagonQueensFactory.java      \
        THexagonQueensRules.java        \
	THistory.java           \
        THit.java               \
	TLocation.java          \
	TNetServer.java		\
	TNet.java               \
	TNetServerThread.java	\
	TNetThread.java		\
	TPion.java		\
	TPlayer.java		\
	TRules.java		\
	TSet.java

OBJ	= $(SRC:.java=.class)
#
NAME	= Dames.jar
#
.SUFFIXES: .java .class
#
all	:
	cd $(REP) && $(JAVADOC) $(SRC) && mv *.html ../doc && mv *.css ../doc\
	&& mv package-list ../doc

#
#
clean	:
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) *core
	$(RM) \#*
	$(RM) *.html
	$(RM) *.css
	$(RM) package-list
#
fclean	: clean
	$(RM) $(NAME)
#
re	: clean all

