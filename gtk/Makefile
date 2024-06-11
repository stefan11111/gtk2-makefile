top_builddir=..

GTK_PRINT_BACKENDS=

GTK_PRINT_PREVIEW_COMMAND="evince --unlink-tempfile --preview --print-settings %s %f"

ifeq ($(PRINT_SUPPORT), 1)
        GTK_PRINT_BACKENDS += file,lpr,
endif

ifeq ($(CUPS_SUPPORT), 1)
        GTK_PRINT_BACKENDS += cups,
endif

ifeq ($(GDKTARGET), x11)
        gtarget=x11
endif

ifeq ($(GDKTARGET), directfb)
        gtarget=directfb
endif

GTK_LIBRARY = libgtk-${GDKTARGET}-2.0

GTK_BASE_CFLAGS_DEFINES =                               \
        -DGTK_VERSION=\"$(GTK_VERSION)\"                \
        -DGTK_BINARY_VERSION=\"$(GTK_BINARY_VERSION)\"  \
        -DGTK_COMPILATION                               \
        $(/bin/true)                    \
        -DGTK_FILE_SYSTEM_ENABLE_UNSUPPORTED            \
        -DGTK_PRINT_BACKEND_ENABLE_UNSUPPORTED

GTK_PLAT_CFLAGS_DEFINES =                               \
        -DGTK_LIBDIR=\"$(LIBDIR)\"                      \
        -DGTK_DATADIR=\"$(DATADIR)\"                    \
        -DGTK_DATA_PREFIX=\"$(PREFIX)\"                 \
        -DGTK_SYSCONFDIR=\"$(SYSCONFDIR)\"              \
        -DGTK_HOST=\"$(HOST)\"                          \
        -DGTK_PRINT_BACKENDS=\"$(GTK_PRINT_BACKENDS)\"  \
        -DGTK_PRINT_PREVIEW_COMMAND=\"$(GTK_PRINT_PREVIEW_COMMAND)\"


INCLUDES =                                              \
        $(GTK_BASE_CFLAGS_DEFINES)                      \
        $(GTK_PLAT_CFLAGS_DEFINES)                      \
        -DG_LOG_DOMAIN=\"Gtk\"                          \
        -I$(top_builddir)                               \
        -I$(top_builddir)/gtk                           \
        -I$(top_srcdir) -I../gdk                        \
        -I$(top_srcdir)/gdk                             \
        $(XCFLAGS)


all:
