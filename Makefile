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

ifeq ($(PRINT_SUPPORT), 1)
	XCFLAGS += -DHAVE_PRINT
endif

ifeq ($(CUPS_SUPPORT), 1)
	XCFLAGS += -DHAVE_CUPS -DHAVE_CUPS_API_1_2 -DHAVE_CUPS_API_1_6
endif

ifeq ($(XINERAMA_SUPPORT), 1)
	XCFLAGS += -DHAVE_XINERAMA
endif

ifeq ($(LANGINFO_SUPPORT), 1)
	XCFLAGS += -DHAVE__NL_TIME_FIRST_WEEKDAY -DHAVE__NL_MEASUREMENT_MEASUREMENT -DHAVE__NL_PAPER_HEIGHT -DHAVE__NL_PAPER_WIDTH
endif

ifeq ($(HTTP_AUTHSTRING_SUPPORT), 1)
	XCFLAGS += -DHAVE_HTTP_AUTHSTRING
endif

ifeq ($(PAPI_SUPPORT), 1)
	XCFLAGS += -DHAVE_PAPI
endif

ifeq ($(SHM_SUPPORT), 1)
	XCFLAGS += -DHAVE_SHM_H -DHAVE_XSHM_H -DHAVE_IPC_H
endif

ifeq ($(XKB_SUPPORT), 1)
	XCFLAGS += -DHAVE_XKB
endif

XINPUT_SUPPORT = 0

ifeq ($(XINPUT_SUPPORT), 0)
	XCFLAGS += -DXINPUT_NONE
endif

ifeq ($(XCURSOR_SUPPORT), 1)
	XCFLAGS += -DHAVE_XCURSOR
endif

ifeq ($(XFIXES_SUPPORT), 1)
	XCFALGS += -DHAVE_XFIXES
endif

ifeq ($(XCOMPOSITE_SUPPORT), 1)
	XCFLAGS += -DHAVE_XCOMPOSITE
endif

ifeq ($(XDAMAGE_SUPPORT), 1)
	XCFLAGS += -DHAVE_XDAMAGE
endif

ifeq ($(X11R6_SUPPORT), 1)
	XCFLAGS += -DHAVE_X11R6 -DHAVE_XCONVERTCASE -DHAVE_XINTERNATOMS
endif

ifeq ($(XSYNC_SUPPORT), 1)
	XCFLAGS += -DHAVE_XSYNC
endif

ifeq ($(XRANDR_SUPPORT), 1)
	XCFLAGS += -DHAVE_RANDR -DHAVE_RANDR15
endif

XCFLAGS += -lXrender -lXrandr -lXcursor -lXext -lgmodule-2.0 -lpangocairo-1.0 -lX11 -lXcomposite -lXdamage -lXfixes -lcairo -lgdk_pixbuf-2.0 -lgio-2.0 -lpangoft2-1.0 -lpango-1.0 -lgobject-2.0 -lglib-2.0 -lharfbuzz -lfontconfig -lfreetype -lm

all:

configure: configure.c
	${CC} ${CFLAGS} configure.c -o configure

clean:
	rm -f configure

.PHONY: all clean
