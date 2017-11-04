#
# sample Makefile for Objective Caml
# Copyright (C) 2001 Jean-Christophe FILLIATRE
# 
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Library General Public
# License version 2, as published by the Free Software Foundation.
# 
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# 
# See the GNU Library General Public License version 2 for more details
# (enclosed in the file LGPL).

# where to install the binaries


SHELL = /bin/sh

prefix=/usr/local
exec_prefix=${prefix}
BINDIR=${exec_prefix}/bin

# where to install the man page
MANDIR=${prefix}/man

# other variables set by ./configure
OCAMLC   = ocamlc
OCAMLOPT = ocamlopt
OCAMLDEP = ocamldep
OCAMLLEX = ocamllex
OCAMLYACC= ocamlyacc
OCAMLLIB = /usr/pkg/lib/ocaml
OCAMLBEST= opt
OCAMLVERSION = 3.04
OCAMLWEB = 

SRC =  parser_line.mly lexer_line.mll \
	parser_toplevel.mly lexer_toplevel.mll\
	parser_conf.mly lexer_conf.mll
SUBDIRS = 

MLY2ML	= $(SRC:.mly=.ml)
MLL2ML	= $(SRC:.mll=.ml) 
MLI = #parser_line.mli parser_toplevel.mli 
MLI2 = lexer_toplevel.mli

CMO = $(MLI:.mli=.cmi) $(MLY2ML:.ml=.cmo)  $(MLI2:.mli=.cmi) $(MLL2ML:.ml=.cmo)
CMX = $(MLI:.mli=.cmi) $(MLY2ML:.ml=.cmx) $(MLI2:.mli=.cmi) $(MLL2ML:.ml=.cmx)

CMXajon = $(MLI:.mli=.cmx) $(MLI2:.mli=.cmx) lexer_line.cmx lexer_conf.cmx
CMOajon = $(MLI:.mli=.cmo) $(MLI2:.mli=.cmo) lexer_line.cmo lexer_conf.cmo

CMXajd 	= parser_line.cmx lexer_line.cmx \
	parser_toplevel.cmx lexer_toplevel.cmx\
	parser_conf.cmx lexer_conf.cmx
CMOajd 	= parser_line.cmo lexer_line.cmo \
	parser_toplevel.cmo lexer_toplevel.cmo \
	parser_conf.cmo lexer_conf.cmo

am_math_OBJECTS = 

LIBS = 
LIBNAME = parse.cma
LIBNAMEOPT = parse.cmxa
INCLUDESOPT = ../ast/*.cmx
INCLUDES = ../ast/*.cmo
INCLUDE = -I ../ast 
BFLAGS = -g $(INCLUDES)
OFLAGS = $(INCLUDES)

DIST_SOURCES = $(SRC)
DIST_COMMON = Makefile.in
DIST_SUBDIRS = $(SUBDIRS)

MAKE = gmake
GMAKEFILE = GMakefile

# main target
#############

opt: subopt $(MLY2ML) $(MLL2ML) $(CMX) 
	$(OCAMLOPT) $(INCLUDESOPT) -a $(CMXajd) -o lib$(LIBNAMEOPT)

subopt :
	@set fnord $$MAKEFLAGS; amf=$$2; \
	dot_seen=no; \
	target=`echo $@ | sed s/-recursive//`; \
	list='$(SUBDIRS)'; for subdir in $$list; do \
	  echo "Making opt in $$subdir"; \
	  if test -e "$$subdir/Makefile.am"; then \
	    dot_seen=yes; \
	    local_target=all; \
	  else \
	    local_target=opt; \
	  fi; \
	  (cd $$subdir && $(MAKE) $$local_target) \
	   || case "$$amf" in *=*) exit 1;; *k*) fail=yes;; *) exit 1;; esac; \
	done


all: subbc $(MLY2ML) $(MLL2ML) $(CMO)
	$(OCAMLC) $(INCLUDE) -a $(CMOajd) -o lib$(LIBNAME)

subbc:
	@set fnord $$MAKEFLAGS; amf=$$2; \
	dot_seen=no; \
	target=`echo $@ | sed s/-recursive//`; \
	list='$(SUBDIRS)'; for subdir in $$list; do \
	  echo "Making all in $$subdir"; \
	  if test "$$subdir" = "."; then \
	    dot_seen=yes; \
	    local_target=all-am; \
	  else \
	    local_target=all; \
	  fi; \
	  (cd $$subdir && $(MAKE) $$local_target) \
	   || case "$$amf" in *=*) exit 1;; *k*) fail=yes;; *) exit 1;; esac; \
	done


# bytecode and native-code compilation
######################################


GENERATED = version.ml

#byte: $(NAME).byte
#opt: $(NAME).opt

#$(NAME).byte: $(CMO)
#	$(OCAMLC) $(BFLAGS) -o $@ $^

#$(NAME).opt: $(CMX)
#	$(OCAMLOPT) $(OFLAGS) -o $@ $^

VERSION=0.1

version.ml: Makefile
	echo "let version = \""$(VERSION)"\"" > version.ml
	echo "let date = \""`date`"\"" >> version.ml

# installation
##############

install:
	mkdir -p $(BINDIR)
	cp -f $(NAME).$(OCAMLBEST) $(BINDIR)/$(NAME)
	mkdir -p $(MANDIR)/man1
	cp -f $(NAME).1 $(MANDIR)/man1

# documentation
###############

DOCFILES=manual.ps manual.html

doc: $(DOCFILES)

# export
########

EXPORTDIR=$(NAME)-$(VERSION)
TAR=$(EXPORTDIR).tar

FTP = $$HOME/ftp/$(NAME)
WWW = $$HOME/WWW/$(NAME)

FILES = *.ml* $(NAME).1 manual.tex	     \
	Makefile.in configure configure.in   \
	.depend README INSTALL COPYING GPL CHANGES

#export: source binary export-doc
#	cp README COPYING GPL CHANGES $(FTP)

#source: 
#	mkdir -p export/$(EXPORTDIR)
#	cp $(FILES) export/$(EXPORTDIR)
#	cd export ; tar cf $(TAR) $(EXPORTDIR) ; gzip -f --best $(TAR)
#	cp export/$(TAR).gz $(FTP)

export-doc: $(DOCFILES)
	gzip -c manual.ps > $(FTP)/manual.ps.gz
	cp manual.html $(WWW)

BINARY = $(EXPORTDIR)-$(OSTYPE)
BINARYTAR=$(BINARY).tar

BINARYFILES = README INSTALL COPYING GPL $(NAME).1

#binary: $(NAME).$(OCAMLBEST) $(DOCFILES)
#	mkdir -p export/$(BINARY)
#	cp $(BINARYFILES) $(DOCFILES) export/$(BINARY)
#	cp $(NAME).$(OCAMLBEST) export/$(BINARY)/$(NAME)
#	(cd export; tar czf $(BINARY).tar.gz $(BINARY))
#	cp export/$(BINARY).tar.gz $(FTP)

# literate programming
######################

SOURCES =

$(NAME).tex: $(SOURCES)
	$(OCAMLWEB) -o $@ $^

# generic rules
###############

.SUFFIXES: .mli .ml .cmi .cmo .cmx .mll .mly .tex .dvi .ps .html

.mli.cmi:
	$(OCAMLC) -c $(INCLUDE) $<

.ml.cmo:
	$(OCAMLC) -c $(INCLUDE) $<

.ml.o:
	$(OCAMLC) -c $(INCLUDE) $<

.ml.cmx:
	$(OCAMLOPT) -c $(INCLUDE) $<

.mll.ml:
	$(OCAMLLEX) $<

.mly.ml:
	$(OCAMLYACC) -v $<
	rm -f parser_line.mli parser_toplevel.mli parser_conf.mli

.mly.mli:
	$(OCAMLYACC) -v $<

.tex.dvi:
	latex $< && latex $<

.dvi.ps:
	dvips $< -o $@ 

.tex.html:
	hevea $<

# Emacs tags
############

tags:
	find . -name "*.ml*" | sort -r | xargs \
	etags "--regex=/let[ \t]+\([^ \t]+\)/\1/" \
	      "--regex=/let[ \t]+rec[ \t]+\([^ \t]+\)/\1/" \
	      "--regex=/and[ \t]+\([^ \t]+\)/\1/" \
	      "--regex=/type[ \t]+\([^ \t]+\)/\1/" \
              "--regex=/exception[ \t]+\([^ \t]+\)/\1/" \
	      "--regex=/val[ \t]+\([^ \t]+\)/\1/" \
	      "--regex=/module[ \t]+\([^ \t]+\)/\1/"

# Makefile is rebuilt whenever Makefile.in or configure.in is modified
######################################################################

Makefile: Makefile.in config.status
	./config.status

config.status: configure
	./config.status --recheck

configure: configure.in
	autoconf 

# clean
#######

clean::
	@set fnord $$MAKEFLAGS; amf=$$2; \
	dot_seen=no; \
	target=`echo $@ | sed s/-recursive//`; \
	list='$(SUBDIRS)'; for subdir in $$list; do \
	  echo "Making $$target in $$subdir"; \
	  if test "$$subdir" = "."; then \
	    dot_seen=yes; \
	    local_target="$$target-am"; \
	  else \
	    local_target="$$target"; \
	  fi; \
	  (cd $$subdir && $(MAKE) $$local_target) \
	   || case "$$amf" in *=*) exit 1;; *k*) fail=yes;; *) exit 1;; esac; \
	done; \
	rm -f *.cm[iox] *.o *~
	rm -f $(GENERATED) parser.output
	rm -f $(NAME).byte $(NAME).opt
	rm -f *.aux *.log $(NAME).tex $(NAME).dvi $(NAME).ps
	rm -f *o *~ *core
	rm -f parser_line.ml
	rm -f lexer_line.ml
	rm -f parser_toplevel.ml
	rm -f parser_conf.ml
	rm -f lexer_conf.ml
	rm -fr *.cma
	rm -fr *.cmxa

dist-clean distclean:: clean
	rm -f Makefile config.cache config.log config.status

# depend
########

.deps depend:: $(GENERATED)
	rm -f .deps
	$(OCAMLDEP) $(INCLUDES) *.ml *.mli > .deps

# dist
######
distclean-tags:
	-rm -f TAGS ID GTAGS GRTAGS GSYMS GPATH
DISTFILES = $(DIST_COMMON) $(DIST_SOURCES) $(TEXINFOS) $(EXTRA_DIST)

top_distdir = ..
distdir = $(top_distdir)/$(PACKAGE)-$(VERSION)


distdir: $(DISTFILES)
	@for file in $(DISTFILES); do \
	  if test -f $$file || test -d $$file; then d=.; else d=$(srcdir); fi; \
	  dir=`echo "$$file" | sed -e 's,/[^/]*$$,,'`; \
	  if test "$$dir" != "$$file" && test "$$dir" != "."; then \
	    dir="/$$dir"; \
	    $(mkinstalldirs) "$(distdir)$$dir"; \
	  else \
	    dir=''; \
	  fi; \
	  if test -d $$d/$$file; then \
	    cp -pR $$d/$$file $(distdir)$$dir \
	    || exit 1; \
	  else \
	    test -f $(distdir)/$$file \
	    || cp -p $$d/$$file $(distdir)/$$file \
	    || exit 1; \
	  fi; \
	done
	list='$(SUBDIRS)'; for subdir in $$list; do \
	  if test "$$subdir" = .; then :; else \
	    test -d $(distdir)/$$subdir \
	    || mkdir $(distdir)/$$subdir \
	    || exit 1; \
	    (cd $$subdir && \
	      $(MAKE) $(AM_MAKEFLAGS) \
	        top_distdir="$(top_distdir)" \
	        distdir=../$(distdir)/$$subdir \
	        distdir) \
	      || exit 1; \
	  fi; \
	done
