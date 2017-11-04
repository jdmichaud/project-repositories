OCAMLMAKEFILE=OcamlMakefile

OCAMLFLAGS:=-i

 
LIBS:= str unix

SOURCES := \
	createnn.ml\
	nnconf.mly\
	nnconfscan.mll\
	nndesc.mly\
	nndescscan.mll\
	network.mli\
	printnn.ml\
	activnn.ml\
	apprentnn.ml\
	phoneme.ml\
	letters.ml\
	makein.ml\
	learn.ml\
	csv.ml\
	save.ml\
	main.ml

RESULT := bobTalk

include $(OCAMLMAKEFILE)

.PHONY : test

test : bc 
	test/test.sh ${PWD}/${RESULT} ${PWD}/test
