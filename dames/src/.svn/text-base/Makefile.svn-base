##
## Makefile for le java c'est dla merde in 
## 
## Made by jean-daniel michaud
## Login   <michau_j@epita.fr>
## 
## Started on  Mon Jun 17 14:12:31 2002 jean-daniel michaud

##

JC	= javac
RM	= rm -fr
JAR	= jar cmf
SRC	= DBQuery.java		\
	DBQueryFactory.java	\
	DBQueryPerformer.java	\
	DBQueryPerformerLoader.java \
	JDBCPerformer.java	\
	StandardDBFactory.java	\
	TAction.java		\
	TBoard.java		\
	TCase.java 		\
	TClientGame.java	\
	TCondition.java		\
	TDB.java		\
	TDBLoader.java		\
	TDBStandard.java	\
	TDefaultHistory.java	\
	TDefaultMove.java	\
	TDisplayControler.java	\
	TDistLocation.java	\
	TDrawable.java		\
	TEat.java		\
	TEntity.java		\
	TGame.java 		\
	TGraphicContext.java	\
	THexagonBoard.java	\
	THexagonCase.java	\
	THexagonQueensFactory.java	\
	THexagonQueensRules.java	\
	THistory.java		\
	THit.java		\
	TLocation.java		\
	TNet.java		\
	TNetServer.java		\
	TNetServerThread.java	\
	TNetThread.java		\
	TPion.java		\
	TPlayer.java		\
	TQueensFactory.java	\
	TQueensRules.java	\
	TRules.java		\
	TRulesFactory.java	\
	TServerGame.java	\
	TSet.java		\
	TSquareBoard.java	\
	TSquareCase.java	\
	TThreadHit.java

SRV	= DBQuery.java		\
	DBQueryFactory.java	\
	DBQueryPerformer.java	\
	DBQueryPerformerLoader.java \
	JDBCPerformer.java	\
	StandardDBFactory.java	\
	TAction.java		\
	TBoard.java		\
	TCase.java 		\
	TCondition.java		\
	TDB.java		\
	TDBLoader.java		\
	TDBStandard.java	\
	TDefaultHistory.java	\
	TDefaultMove.java	\
	TDisplayControler.java	\
	TDistLocation.java	\
	TDrawable.java		\
	TEat.java		\
	TEntity.java		\
	TGame.java 		\
	TGraphicContext.java	\
	THexagonBoard.java	\
	THexagonCase.java	\
	THexagonQueensFactory.java	\
	THexagonQueensRules.java	\
	THistory.java		\
	THit.java		\
	TLocation.java		\
	TNet.java		\
	TNetServer.java		\
	TNetServerThread.java	\
	TNetThread.java		\
	TPion.java		\
	TPlayer.java		\
	TQueensFactory.java	\
	TQueensRules.java	\
	TRules.java		\
	TRulesFactory.java	\
	TServerGame.java	\
	TSet.java		\
	TSquareBoard.java	\
	TSquareCase.java	\
	TThreadHit.java

CLT	= DBQuery.java		\
	DBQueryFactory.java	\
	DBQueryPerformer.java	\
	DBQueryPerformerLoader.java \
	JDBCPerformer.java	\
	StandardDBFactory.java	\
	TAction.java		\
	TBoard.java		\
	TCase.java 		\
	TClientGame.java	\
	TCondition.java		\
	TDB.java		\
	TDBLoader.java		\
	TDBStandard.java	\
	TDefaultHistory.java	\
	TDefaultMove.java	\
	TDisplayControler.java	\
	TDistLocation.java	\
	TDrawable.java		\
	TEat.java		\
	TEntity.java		\
	TGame.java 		\
	TGraphicContext.java	\
	THexagonBoard.java	\
	THexagonCase.java	\
	THexagonQueensFactory.java	\
	THexagonQueensRules.java	\
	THistory.java		\
	THit.java		\
	TLocation.java		\
	TNet.java		\
	TNetClient.java		\
	TNetServerThread.java	\
	TNetThread.java		\
	TPion.java		\
	TPlayer.java		\
	TQueensFactory.java	\
	TQueensRules.java	\
	TRules.java		\
	TRulesFactory.java	\
	TServerGame.java	\
	TSet.java		\
	TSquareBoard.java	\
	TSquareCase.java	\
	TThreadHit.java



OBJ	= $(SRC:.java=.class)
OBJSRV	= $(SRV:.java=.class)
OBJCLT	= $(CLT:.java=.class)
#
NAME	= Dames.jar
NAMECLT	= Client.jar
#
MANIFEST= smanifest
MANCLT	= cmanifest
#
.SUFFIXES: .java .class
#
all	: $(OBJ)
	$(JAR) $(MANIFEST) $(NAME) $(OBJSRV)
	$(JAR) $(MANCLT) $(NAMECLT) *.class
#
.java.class	:
	$(JC) $<
#
clean	:
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) *core
	$(RM) \#*
#
fclean	:
	$(RM) $(NAME)
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) *core
	$(RM) \#*
#
re	: clean all
