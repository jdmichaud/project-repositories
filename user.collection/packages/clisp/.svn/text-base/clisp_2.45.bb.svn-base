DESCRIPTION = "Clisp, an ANSI Common Lisp Implementation"

PR = "r0"

DEPENDS = "readline ncurses libsigsegv"

SRC_URI = " \
  http://switch.dl.sourceforge.net/sourceforge/clisp/clisp-2.45.tar.gz \
#  file://configure.patch;patch=1 \
 "

inherit autotools
inherit patcher

#do_patch () {
#   cd ${S} && patch < ${GUMSTIXTOP}/user.collection/packages/clisp/files/configure.patch
#}

do_configure () {
        env
        CC="${CCLD}" CPP="${CPP}" LD="${LD} ${STAGING_LIBDIR}" LDFLAGS="-L${STAGING_LIBDIR} ${LDFLAGS} -lsigsegv -lreadline -lncurses" ${S}/configure --build=${BUILD_SYS} --host=${TARGET_SYS} \
            --prefix=/usr --exec_prefix=/usr --bindir=${bindir} --datadir=/usr/share --libdir=/usr/lib \
            --includedir=/usr/include --mandir=/usr/share/man --with-libsigsegv-prefix=${STAGING_LIBDIR} --with-libreadline-prefix=${STAGING_LIBDIR}
}

do_compile () {
        cd ${S}/src && make
}

do_install () {
    install -d ${D}${bindir}/
    install -m 0755 ${S}/clisp ${D}${bindir}/
}

FILES_${PN} = "${bindir}/clisp"