DESCRIPTION = "libsisegv 2.5"
SECTION = "libs"
PR = "r0"

DEPENDS = ""

SRC_URI = " \
  http://ftp.gnu.org/pub/gnu/libsigsegv/libsigsegv-2.5.tar.gz \
 "

inherit autotools
inherit patcher

#do_configure () {
#        CC="${BUILD_CC}" CPP="${BUILD_CPP}" LD="${BUILD_LD}" ${S}./configure --host=${TARGET_SYS} --prefix=/usr
#}

do_install () {
        oe_libinstall -a libsigsegv ${STAGING_LIBDIR}
        install -d ${STAGING_BINDIR}
        cp ${S}/src/sigsegv.h ${STAGING_DIR}/${TARGET_SYS}/include/
#        install -m 755 ${S}/libsigsegv-config ${STAGING_BINDIR}

#        perl -pi -e 's:\-L${libdir} :-L${STAGING_LIBDIR} :' ${STAGING_BINDIR}/libsigsegv-config

#        if [ "${STAGING_BINDIR}" != "${STAGING_BINDIR_CROSS}" ]; then
#                install -d ${STAGING_BINDIR_CROSS}/
#                mv ${STAGING_BINDIR}/libsigsegv-config ${STAGING_BINDIR_CROSS}/libsigsegv-config
#        fi

#        install -d ${STAGING_INCDIR}/
#        for X in usb.h
#        do
#                install -m 0644 ${S}/$X ${STAGING_INCDIR}/$X
#        done
           
}

#PACKAGES =+ "libsigsegv"

FILES_${PN} = "${bindir}/libsigsegv*.so.*"