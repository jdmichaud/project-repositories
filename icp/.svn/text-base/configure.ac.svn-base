# We want Autoconf 2.52 at least.
AC_PREREQ(2.52)
AC_INIT(michau_j, 1)

# Auxiliary files.
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_FILES(config/Makefile)

# Automake.
AM_INIT_AUTOMAKE(AC_PACKAGE_NAME, AC_PACKAGE_VERSION)

# We want optimization, and a lot of debugging, for both
# C and C++.
CFLAGS="-Wall -O3"
CXXFLAGS=$CFLAGS

# Look for a C++ compiler.
AC_LANG_CPLUSPLUS
AC_PROG_CXX

# Look for a C compiler for lib/.
AC_LANG_C
AC_PROG_CC

# Look for auxiliary programs.
AM_PROG_LEX
AC_PROG_RANLIB

# checking lib
AC_ARG_WITH(,[Math Lib:])

AC_MSG_CHECKING(Path to lib PGM)

AC_ARG_WITH(pgm,
  [  --with-pgm=PATH         Compile with PGM lib.])
  if test "x$with_pgm" = x
  then
    AC_MSG_ERROR([--with-pgm not defined])
  else
    LDFLAGS="-L${with_pgm}/lib ${LDFLAGS}"
    CPPFLAGS="-I${with_pgm}/include ${CFLAGS}"
    AC_CHECK_HEADERS(pgm.h, [CFLAGS="${CFLAGS} -I${with_pgm}/include"])
    AC_CHECK_LIB(pbm, pbm_init)
    AC_CHECK_LIB(pgm, pgm_init)
  fi

AC_MSG_CHECKING(Path to lib GL for OpenGL)
AC_ARG_WITH(GL,	
  [  --with-GL=PATH         Compile with OpenGL lib.])
  if test "x$with_GL" = x
  then
   AC_MSG_ERROR([--with-GL not defined
])
  else
    LDFLAGS="-L${with_GL}/lib ${LDFLAGS} -lGL -lGLU -lglut -lXmu -lm"
    CPPFLAGS="-I${with_GL}/include ${CFLAGS}"
    AC_CHECK_HEADERS(GL/glut.h, [CFLAGS="${CFLAGS} -I${with_GL}/include"])
    AC_CHECK_HEADERS(GL/gl.h, [CFLAGS="${CFLAGS} -I${with_GL}/include"])
    AC_CHECK_LIB(X11, XFlush)
  fi

# Ask for config.h.
AM_CONFIG_HEADER(config.h)

# Ask for the Makefile creations.
AC_CONFIG_FILES(Makefile
                src/Makefile)

# Intantiate the output files.
AC_OUTPUT
