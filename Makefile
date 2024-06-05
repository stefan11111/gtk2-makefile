.POSIX:

XCFLAGS = ${CFLAGS} -DG_DISABLE_SINGLE_INCLUDES -DGDK_PIXBUF_DISABLE_SINGLE_INCLUDES -DGTK_DISABLE_SINGLE_INCLUDES
GTK_MAJOR_VERSION = 2
GTK_MINOR_VERSION = 24
GTK_MICRO_VERSION = 33
GTK_INTERFACE_AGE = 33
GTK_BINARY_AGE = ${GTK_MINOR_VERSION}${GTK_MICRO_VERSION}
GTK_VERSION = ${GTK_MAJOR_VERSION}.${GTK_MINOR_VERSION}.${GTK_MICRO_VERSION}
GTK_API_VERSION = 2.0
GTK_BINARY_VERSION = 2.10.0

GDKTARGET = x11

## Copy .pc files to target-specific names
#gtk+-$(GDKTARGET)-2.0.pc: gtk+-2.0.pc
#	rm -f gtk+-$(GDKTARGET)-2.0.pc && \
#	cp gtk+-2.0.pc gtk+-$(GDKTARGET)-2.0.pc

#gdk-$(GDKTARGET)-2.0.pc: gdk-2.0.pc
#	rm -f gdk-$(GDKTARGET)-2.0.pc && \
#	cp gdk-2.0.pc gdk-$(GDKTARGET)-2.0.pc

#gtk+-$(GDKTARGET)-2.0-uninstalled.pc: gtk+-2.0-uninstalled.pc
#	rm -f gtk+-$(GDKTARGET)-2.0-uninstalled.pc && \
#	cp gtk+-2.0-uninstalled.pc gtk+-$(GDKTARGET)-2.0-uninstalled.pc

#gdk-$(GDKTARGET)-2.0-uninstalled.pc: gdk-2.0-uninstalled.pc
#	rm -f gdk-$(GDKTARGET)-2.0-uninstalled.pc && \
#	cp gdk-2.0-uninstalled.pc gdk-$(GDKTARGET)-2.0-uninstalled.pc

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA= gdk-$(GDKTARGET)-2.0.pc gtk+-$(GDKTARGET)-2.0.pc pkgconfig_DATA += gtk+-unix-print-2.0.pc

DISTCLEANFILES =                                \
	gtk+-unix-print-2.0.pc                  \
	gtk+-$(GDKTARGET)-2.0.pc                \
	gdk-$(GDKTARGET)-2.0.pc                 \
	gtk+-$(GDKTARGET)-2.0-uninstalled.pc    \
	gdk-$(GDKTARGET)-2.0-uninstalled.pc

ifeq ($(GDKTARGET), x11)
	XCFLAGS += -DGDK_WINDOWING_X11
endif

ifeq ($(GDKTARGET), directfb)
        XCFLAGS += -DGDK_WINDOWING_DIRECTFB
endif

all:

configure: configure.c
	${CC} ${CFLAGS} configure.c -o configure

clean:
	rm -f configure

.PHONY: all clean
