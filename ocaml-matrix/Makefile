OCAMLMAKEFILE = OCamlMakefile

SOURCES = element.mli element.ml matrix.mli matrix.ml array_matrix.mli array_matrix.ml
RESULT  = matrix

LIBINSTALL_FILES = element.mli element.ml \
		   matrix.mli matrix.ml \
		   array_matrix.mli array_matrix.ml \
		   matrix.cmi matrix.cmxa matrix.a

all:

install:	libinstall
uninstall:	libuninstall

-include $(OCAMLMAKEFILE)
