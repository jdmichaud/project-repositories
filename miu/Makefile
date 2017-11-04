OCAMLMAKEFILE=OcamlMakefile 
SOURCES := parser.mly lexer.mll problem_parser.mly problem_lexer.mll \
	type_t.ml clause_parser.mly clause_lexer.mll formal_system.mli \
	resolution_transform.ml resolution.ml interpreteur.mli \
	interpreteur.ml miu.ml
RESULT := miu
include $(OCAMLMAKEFILE)

TARBALL=michau_j-miu
RM=rm -fr

comp: clean
	cd .. && tar zcvf $(TARBALL).tgz $(TARBALL) && chmod 600 $(TARBALL).tgz
save: clean comp
	cd .. && mcopy $(TARBALL).tgz a:
