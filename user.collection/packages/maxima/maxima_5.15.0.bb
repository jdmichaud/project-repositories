DESCRIPTION = "Maxima, a Computer Algebra System"

PR = "r0"

DEPENDS = "clisp"

SRC_URI = " \
  http://switch.dl.sourceforge.net/sourceforge/maxima/maxima-5.15.0.tar.gz \
 "

inherit autotools

do_configure () {
        autotools_do_configure
}

do_install () {
    install -d ${D}${bindir}/
    install -m 0755 ${S}/maxima ${D}${bindir}/
}

FILES_${PN} = "${bindir}/maxima"