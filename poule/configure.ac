# We want Autoconf 2.52 at least.
AC_PREREQ(2.52)
AC_INIT(poule, 0.1)

# Auxiliary files.
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_FILES(config/Makefile)

# Automake.
AM_INIT_AUTOMAKE(AC_PACKAGE_NAME, AC_PACKAGE_VERSION)

# We want no optimization (too slow), and a lot of debugging, for both
# C and C++.
CFLAGS="-ggdb -Wall"
CXXFLAGS=$CFLAGS

# Look for a C++ compiler.
AC_LANG_CPLUSPLUS
AC_PROG_CXX

# Look for a C compiler for lib/.
AC_LANG_C
AC_PROG_CC

# Look for auxiliary programs.
# AM_PROG_LEX
# AC_PROG_YACC
AC_PROG_RANLIB

## FOR OCAML
# Check for Ocaml compilers

# we first look for ocamlc in the path; if not present, we fail
AC_CHECK_PROG(OCAMLC,ocamlc,ocamlc,no)
if test "$OCAMLC" = no ; then
	AC_MSG_ERROR(Cannot find ocamlc.)
fi

# we extract Ocaml version number and library path
OCAMLVERSION=`$OCAMLC -v | sed -n -e 's|.*version *\(.*\)$|\1|p' `
echo "ocaml version is $OCAMLVERSION"
OCAMLLIB=`$OCAMLC -v | tail -1 | cut -f 4 -d " "`
echo "ocaml library path is $OCAMLLIB"

# then we look for ocamlopt; if not present, we issue a warning
# if the version is not the same, we also discard it
# we set OCAMLBEST to "opt" or "byte", whether ocamlopt is available or not
AC_CHECK_PROG(OCAMLOPT,ocamlopt,ocamlopt,no)
OCAMLBEST=byte
if test "$OCAMLOPT" = no ; then
	AC_MSG_WARN(Cannot find ocamlopt; bytecode compilation only.)
else
	AC_MSG_CHECKING(ocamlopt version)
	TMPVERSION=`$OCAMLOPT -v | sed -n -e 's|.*version *\(.*\)$|\1|p' `
	if test "$TMPVERSION" != "$OCAMLVERSION" ; then
	    AC_MSG_RESULT(differs from ocamlc; ocamlopt discarded.)
	    OCAMLOPT=no
	else
	    AC_MSG_RESULT(ok)
	    OCAMLBEST=opt
	fi
fi

# checking for ocamlc.opt
#AC_CHECK_PROG(OCAMLCDOTOPT,ocamlc.opt,ocamlc.opt,no)
#if test "$OCAMLCDOTOPT" != no ; then
#	AC_MSG_CHECKING(ocamlc.opt version)
#	TMPVERSION=`$OCAMLCDOTOPT -v | sed -n -e 's|.*version *\(.*\)$|\1|p' `
#	if test "$TMPVERSION" != "$OCAMLVERSION" ; then
#	    AC_MSG_RESULT(differs from ocamlc; ocamlc.opt discarded.)
#	else
#	    AC_MSG_RESULT(ok)
#	    OCAMLC=$OCAMLCDOTOPT
#	fi
#fi

# checking for ocamlopt.opt
#if test "$OCAMLOPT" != no ; then
#    AC_CHECK_PROG(OCAMLOPTDOTOPT,ocamlopt.opt,ocamlopt.opt,no)
#    if test "$OCAMLOPTDOTOPT" != no ; then
#	AC_MSG_CHECKING(ocamlc.opt version)
#	TMPVER=`$OCAMLOPTDOTOPT -v | sed -n -e 's|.*version *\(.*\)$|\1|p' `
#	if test "$TMPVER" != "$OCAMLVERSION" ; then
#	    AC_MSG_RESULT(differs from ocamlc; ocamlopt.opt discarded.)
#	else
#	    AC_MSG_RESULT(ok)
#	    OCAMLOPT=$OCAMLOPTDOTOPT
#	fi
#    fi
#fi

# ocamldep, ocamllex and ocamlyacc should also be present in the path
AC_CHECK_PROG(OCAMLDEP,ocamldep,ocamldep,no)
if test "$OCAMLDEP" = no ; then
	AC_MSG_ERROR(Cannot find ocamldep.)
fi

AC_CHECK_PROG(OCAMLLEX,ocamllex,ocamllex,no)
if test "$OCAMLLEX" = no ; then
    AC_MSG_ERROR(Cannot find ocamllex.)
else
    AC_CHECK_PROG(OCAMLLEXDOTOPT,ocamllex.opt,ocamllex.opt,no)
    if test "$OCAMLLEXDOTOPT" != no ; then
	OCAMLLEX=$OCAMLLEXDOTOPT
    fi
fi

AC_CHECK_PROG(OCAMLYACC,ocamlyacc,ocamlyacc,no)
if test "$OCAMLYACC" = no ; then
	AC_MSG_ERROR(Cannot find ocamlyacc.)
fi

#AC_CHECK_PROG(OCAMLWEB,ocamlweb,ocamlweb,true)

# Check for termcap library
AC_MSG_CHECKING(for to termcap library.)
AC_ARG_WITH(termcap,
  [--with-termcap=PATH         Compile with termcap lib])
  if test "x$with_termcap" = x
  then
    AC_CHECK_LIB(termcap, tgetent)
    TERMCAP="/usr"
  else
    LDFLAGS="-L${with_termcap}/lib ${LDFLAGS}"
    CPPFLAGS="-I${with_termcap}/include/ ${CFLAGS}"
    AC_CHECK_LIB(termcap, tgetent)
    TERMCAP="${with_termcap}"
  fi

# Check for readline library
AC_MSG_CHECKING(for to readline library.)
AC_ARG_WITH(readline,
  [--with-readline=PATH         Compile with readline lib])
  if test "x$with_readline" = x
  then
    AC_CHECK_LIB(readline, readline)
    READLINE="/usr"
  else
    LDFLAGS="-L${with_readline}/lib ${LDFLAGS}"
    CPPFLAGS="-I${with_readline}/include/readline ${CFLAGS}"
    AC_CHECK_LIB(readline, readline)
    AC_CHECK_HEADERS(readline.h,[CFLAGS="${CFLAGS} -I${with_readline}/include/readline"])    
    AC_CHECK_HEADERS(history.h,[CFLAGS="${CFLAGS} -I${with_readline}/include/readline"])
    READLINE="${with_readline}"
  fi

# substitutions to perform
AC_SUBST(OCAMLC)
AC_SUBST(OCAMLOPT)
AC_SUBST(OCAMLDEP)
AC_SUBST(OCAMLLEX)
AC_SUBST(OCAMLYACC)
AC_SUBST(OCAMLBEST)
AC_SUBST(OCAMLVERSION)
AC_SUBST(OCAMLLIB)
AC_SUBST(OCAMLWEB)
AC_SUBST(TERMCAP)
AC_SUBST(READLINE)

# Ask for config.h.
AM_CONFIG_HEADER(config.h)

# Ask for the Makefile creations.
AC_CONFIG_FILES(Makefile
	        src/Makefile
	        src/numeric/Makefile
	        src/parse/Makefile
		src/ast/Makefile
		src/env/Makefile
		src/cmd/Makefile
		src/algebra/Makefile
		src/computation/Makefile)

# Intantiate the output files.
AC_OUTPUT
