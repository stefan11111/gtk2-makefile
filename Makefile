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

all:
	cd gtk && make
	cd gdk && make

configure: configure.c
	${CC} ${CFLAGS} configure.c -o configure

clean:
	rm -f configure

.PHONY: all clean
