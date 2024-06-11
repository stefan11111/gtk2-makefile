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


libgtkincludedir = $(includedir)/gtk-2.0/gtk

OBJ = $(gtk_all_c_sources)
ALL_HEADERS = $(gtk_public_h_sources)

.c.o:
	${CC} ${XCFLAGS} -c -o $@ $<

all: ${GTK_LIBRARY}.so.0

libgtk-x11-2.0.so.0: ${OBJ}
	${CC} ${XCFLAGS} -o $@ ${OBJ} ${XLDFLAGS}

libgtk-directfb-2.0.so.0: ${OBJ}
	${CC} ${XCFLAGS} -o $@ ${OBJ} ${XLDFLAGS}

clean:
	rm -f ${GTK_LIBRARY}.so.0 ${OBJ}

.PHONY: all clean

#
# setup source file variables
#

# GTK+ header files for public installation (non-generated, or generated
# by configure)
gtk_public_h_sources =          \
	gtk.h			\
	gtkaboutdialog.h	\
	gtkaccelgroup.h		\
	gtkaccellabel.h		\
	gtkaccelmap.h		\
	gtkaccessible.h		\
	gtkaction.h		\
	gtkactiongroup.h	\
	gtkactivatable.h	\
	gtkadjustment.h		\
	gtkalignment.h		\
	gtkarrow.h		\
	gtkaspectframe.h	\
	gtkassistant.h		\
	gtkbbox.h		\
	gtkbin.h		\
	gtkbindings.h		\
	gtkbox.h		\
	gtkbuilder.h		\
	gtkbuildable.h		\
	gtkbutton.h		\
	gtkcalendar.h		\
	gtkcelleditable.h	\
	gtkcelllayout.h		\
	gtkcellrenderer.h	\
	gtkcellrendereraccel.h	\
	gtkcellrenderercombo.h	\
	gtkcellrendererpixbuf.h	\
	gtkcellrendererprogress.h \
	gtkcellrendererspin.h   \
	gtkcellrendererspinner.h\
	gtkcellrenderertext.h	\
	gtkcellrenderertoggle.h	\
	gtkcellview.h		\
	gtkcheckbutton.h	\
	gtkcheckmenuitem.h	\
	gtkclipboard.h		\
	gtkcolorbutton.h	\
	gtkcolorsel.h		\
	gtkcolorseldialog.h	\
	gtkcombobox.h		\
	gtkcomboboxentry.h	\
	gtkcomboboxtext.h	\
	gtkcontainer.h		\
	gtkdebug.h              \
	gtkdialog.h		\
	gtkdnd.h		\
	gtkdrawingarea.h	\
	gtkeditable.h           \
	gtkentry.h		\
	gtkentrybuffer.h	\
	gtkentrycompletion.h	\
	gtkenums.h		\
	gtkeventbox.h		\
	gtkexpander.h		\
	gtkfilechooser.h        \
	gtkfilechooserbutton.h  \
	gtkfilechooserdialog.h  \
	gtkfilechooserwidget.h  \
	gtkfilefilter.h		\
	gtkfixed.h		\
	gtkfontbutton.h		\
	gtkfontsel.h		\
	gtkframe.h		\
	gtkgc.h			\
	gtkhandlebox.h		\
	gtkhbbox.h		\
	gtkhbox.h		\
	gtkhpaned.h		\
	gtkhruler.h		\
	gtkhscale.h		\
	gtkhscrollbar.h		\
	gtkhseparator.h		\
	gtkhsv.h		\
	gtkiconfactory.h	\
	gtkicontheme.h		\
	gtkiconview.h		\
	gtkimage.h		\
	gtkimagemenuitem.h	\
	gtkimcontext.h		\
	gtkimcontextsimple.h	\
	gtkimmulticontext.h	\
	gtkinfobar.h		\
	gtkinvisible.h		\
	gtkitem.h		\
	gtklabel.h		\
	gtklayout.h             \
	gtklinkbutton.h		\
	gtkliststore.h		\
	gtkmain.h		\
	gtkmenu.h		\
	gtkmenubar.h		\
	gtkmenuitem.h		\
	gtkmenushell.h		\
	gtkmenutoolbutton.h	\
	gtkmessagedialog.h	\
	gtkmisc.h		\
	gtkmodules.h		\
	gtkmountoperation.h     \
	gtknotebook.h		\
	gtkobject.h		\
	gtkoffscreenwindow.h	\
	gtkorientable.h		\
	gtkpagesetup.h		\
	gtkpaned.h		\
	gtkpapersize.h		\
	gtkplug.h		\
	gtkprintcontext.h	\
	gtkprintoperation.h	\
	gtkprintoperationpreview.h	\
	gtkprintsettings.h	\
	gtkprivate.h		\
	gtkprogressbar.h	\
	gtkradioaction.h	\
	gtkradiobutton.h	\
	gtkradiomenuitem.h	\
	gtkradiotoolbutton.h	\
	gtkrange.h		\
	gtkrc.h			\
	gtkrecentaction.h	\
	gtkrecentchooser.h 	\
	gtkrecentchooserdialog.h \
	gtkrecentchoosermenu.h 	\
	gtkrecentchooserwidget.h \
	gtkrecentfilter.h 	\
	gtkrecentmanager.h 	\
	gtkruler.h		\
	gtkscale.h		\
	gtkscalebutton.h	\
	gtkscrollbar.h		\
	gtkscrolledwindow.h	\
	gtkselection.h		\
	gtkseparator.h		\
	gtkseparatormenuitem.h	\
	gtkseparatortoolitem.h	\
	gtkshow.h		\
	gtksettings.h		\
	gtksizegroup.h		\
	gtksocket.h		\
	gtkspinbutton.h		\
	gtkspinner.h		\
	gtkstatusbar.h		\
	gtkstatusicon.h		\
	gtkstock.h		\
	gtkstyle.h		\
	gtktable.h		\
	gtktearoffmenuitem.h    \
	gtktestutils.h		\
	gtktextbuffer.h		\
	gtktextbufferrichtext.h	\
	gtktextchild.h		\
	gtktextdisplay.h	\
	gtktextiter.h		\
	gtktextmark.h		\
	gtktexttag.h		\
	gtktexttagtable.h	\
	gtktextview.h		\
	gtktoggleaction.h	\
	gtktogglebutton.h	\
	gtktoggletoolbutton.h	\
	gtktoolbar.h		\
	gtktoolbutton.h		\
	gtktoolitem.h		\
	gtktoolitemgroup.h	\
	gtktoolpalette.h	\
	gtktoolshell.h		\
	gtktooltip.h		\
	gtktreednd.h		\
	gtktreemodel.h		\
	gtktreemodelfilter.h	\
	gtktreemodelsort.h	\
	gtktreeselection.h	\
	gtktreesortable.h	\
	gtktreestore.h		\
	gtktreeview.h		\
	gtktreeviewcolumn.h	\
	gtktypeutils.h		\
	gtkuimanager.h		\
	gtkvbbox.h		\
	gtkvbox.h		\
	gtkviewport.h		\
	gtkvolumebutton.h	\
	gtkvpaned.h		\
	gtkvruler.h		\
	gtkvscale.h		\
	gtkvscrollbar.h		\
	gtkvseparator.h		\
	gtkwidget.h		\
	gtkwindow.h

gtk_unix_print_public_h_sources =    \
	gtkpagesetupunixdialog.h	\
	gtkprintunixdialog.h		\
	gtkprinter.h			\
	gtkprintjob.h			\
	gtkunixprint.h

# Installed header files without compatibility guarantees
# that are not included in gtk/gtk.h
gtk_semi_private_h_sources =    \
	gtktextlayout.h

# GTK+ header files that don't get installed
gtk_private_h_sources =		\
	gtkquery.h		\
	gtksearchengine.h	\
	gtksearchenginesimple.h	\
	gtkdndcursors.h		\
	gtkentryprivate.h	\
	gtkbuilderprivate.h 	\
	gtkcustompaperunixdialog.h\
	gtkfilechooserdefault.h	\
	gtkfilechooserembed.h	\
	gtkfilechooserentry.h	\
	gtkfilechooserprivate.h	\
	gtkfilechoosersettings.h \
	gtkfilechooserutils.h	\
	gtkfilesystem.h		\
	gtkfilesystemmodel.h	\
	gtkiconcache.h		\
	gtkintl.h		\
	gtkkeyhash.h		\
	gtkmnemonichash.h	\
	gtkmountoperationprivate.h \
	gtkpango.h		\
	gtkpathbar.h		\
	gtkplugprivate.h	\
	gtkprintoperation-private.h\
	gtkprintutils.h		\
	gtkrbtree.h		\
	gtkrecentchooserdefault.h \
	gtkrecentchooserprivate.h \
	gtkrecentchooserutils.h \
	gtksocketprivate.h	\
	gtktextbtree.h		\
	gtktextbufferserialize.h\
	gtktextchildprivate.h	\
	gtktextiterprivate.h	\
	gtktextmarkprivate.h	\
	gtktextsegment.h	\
	gtktexttagprivate.h	\
	gtktexttypes.h		\
	gtktextutil.h		\
	gtkthemes.h		\
	gtktoggleactionprivate.h\
	gtktoolpaletteprivate.h	\
	gtktreedatalist.h	\
	gtktreeprivate.h	\
	gtkwindow-decorate.h	\
	$(gtk_clipboard_dnd_h_sources)

# GTK+ C sources to build the library from
gtk_base_c_sources =            \
	gtkquery.o		\
	gtksearchengine.o	\
	gtksearchenginesimple.o	\
	fnmatch.o		\
	gtkaboutdialog.o	\
	gtkaccelgroup.o		\
	gtkaccellabel.o		\
	gtkaccelmap.o		\
	gtkaccessible.o		\
	gtkaction.o		\
	gtkactiongroup.o	\
	gtkactivatable.o	\
	gtkadjustment.o		\
	gtkalignment.o		\
	gtkarrow.o		\
	gtkaspectframe.o	\
	gtkassistant.o		\
	gtkbbox.o		\
	gtkbin.o		\
	gtkbindings.o		\
	gtkbox.o		\
	gtkbuildable.o		\
	gtkbuilder.o		\
	gtkbuilderparser.o	\
	gtkbutton.o		\
	gtkcalendar.o		\
	gtkcelleditable.o	\
	gtkcelllayout.o		\
	gtkcellrenderer.o	\
	gtkcellrendereraccel.o	\
	gtkcellrenderercombo.o	\
	gtkcellrendererpixbuf.o	\
	gtkcellrendererprogress.o \
	gtkcellrendererspin.o   \
	gtkcellrendererspinner.o\
	gtkcellrenderertext.o	\
	gtkcellrenderertoggle.o	\
	gtkcellview.o		\
	gtkcheckbutton.o	\
	gtkcheckmenuitem.o	\
	gtkcolorbutton.o	\
	gtkcolorsel.o		\
	gtkcolorseldialog.o	\
	gtkcombobox.o		\
	gtkcomboboxentry.o	\
	gtkcomboboxtext.o 	\
	gtkcontainer.o		\
	gtkdialog.o		\
	gtkdrawingarea.o	\
	gtkeditable.o           \
	gtkentry.o		\
	gtkentrybuffer.o	\
	gtkentrycompletion.o	\
	gtkeventbox.o		\
	gtkexpander.o		\
	gtkfilechooser.o	\
	gtkfilechooserbutton.o	\
	gtkfilechooserdefault.o	\
	gtkfilechooserdialog.o	\
	gtkfilechooserembed.o	\
	gtkfilechooserentry.o	\
	gtkfilechoosersettings.o \
	gtkfilechooserutils.o	\
	gtkfilechooserwidget.o	\
	gtkfilefilter.o		\
	gtkfilesystem.o		\
	gtkfilesystemmodel.o	\
	gtkfixed.o		\
	gtkfontbutton.o         \
	gtkfontsel.o            \
	gtkframe.o		\
	gtkgc.o			\
	gtkhandlebox.o		\
	gtkhbbox.o		\
	gtkhbox.o		\
	gtkhpaned.o		\
	gtkhruler.o		\
	gtkhscale.o		\
	gtkhscrollbar.o		\
	gtkhseparator.o		\
	gtkhsv.o		\
	gtkiconcache.o		\
	gtkiconcachevalidator.o	\
	gtkiconfactory.o	\
	gtkicontheme.o		\
	gtkiconview.o		\
	gtkimage.o		\
	gtkimagemenuitem.o	\
	gtkimcontext.o		\
	gtkimcontextsimple.o	\
	gtkimmulticontext.o	\
	gtkinfobar.o		\
	gtkinputdialog.o	\
	gtkinvisible.o		\
	gtkitem.o		\
	gtkkeyhash.o		\
	gtklabel.o		\
	gtklayout.o		\
	gtklinkbutton.o		\
	gtkliststore.o		\
	gtkmain.o		\
	gtkmenu.o		\
	gtkmenubar.o		\
	gtkmenuitem.o		\
	gtkmenushell.o		\
	gtkmenutoolbutton.o	\
	gtkmessagedialog.o	\
	gtkmisc.o		\
	gtkmnemonichash.o	\
	gtkmodules.o		\
	gtkmountoperation.o     \
	gtknotebook.o		\
	gtkobject.o		\
	gtkoffscreenwindow.o	\
	gtkorientable.o		\
	gtkpagesetup.o		\
	gtkpaned.o		\
	gtkpango.o		\
	gtkpapersize.o		\
	gtkpathbar.o		\
	gtkplug.o		\
	gtkprintcontext.o	\
	gtkprintoperation.o	\
	gtkprintoperationpreview.o	\
	gtkprintsettings.o	\
	gtkprintutils.o		\
	gtkprogressbar.o	\
	gtkradioaction.o	\
	gtkradiobutton.o	\
	gtkradiomenuitem.o	\
	gtkradiotoolbutton.o	\
	gtkrange.o		\
	gtkrbtree.o 		\
	gtkrc.o			\
	gtkrecentaction.o	\
	gtkrecentchooserdefault.o \
	gtkrecentchooserdialog.o \
	gtkrecentchoosermenu.o 	\
	gtkrecentchooserwidget.o \
	gtkrecentchooserutils.o \
	gtkrecentchooser.o 	\
	gtkrecentfilter.o 	\
	gtkrecentmanager.o 	\
	gtkruler.o		\
	gtkscale.o		\
	gtkscalebutton.o	\
	gtkscrollbar.o		\
	gtkscrolledwindow.o	\
	gtkselection.o		\
	gtkseparator.o		\
	gtkseparatormenuitem.o	\
	gtkseparatortoolitem.o	\
	gtksettings.o		\
	gtksizegroup.o		\
	gtkshow.o		\
	gtksocket.o		\
	gtkspinbutton.o		\
	gtkspinner.o		\
	gtkstatusbar.o		\
	gtkstatusicon.o		\
	gtkstock.o		\
	gtkstyle.o		\
	gtktable.o		\
	gtktearoffmenuitem.o    \
	gtktestutils.o		\
	gtktextbtree.o		\
	gtktextbuffer.o		\
	gtktextbufferrichtext.o	\
	gtktextbufferserialize.o\
	gtktextchild.o		\
	gtktextdisplay.o	\
	gtktextiter.o		\
	gtktextlayout.o		\
	gtktextmark.o		\
	gtktextsegment.o	\
	gtktexttag.o		\
	gtktexttagtable.o	\
	gtktexttypes.o		\
	gtktextutil.o		\
	gtktextview.o		\
	gtkthemes.o		\
	gtktoggleaction.o	\
	gtktogglebutton.o	\
	gtktoggletoolbutton.o	\
	gtktoolbar.o		\
	gtktoolbutton.o		\
	gtktoolitem.o		\
	gtktoolitemgroup.o		\
	gtktoolpalette.o	\
	gtktoolshell.o		\
	gtktooltip.o		\
	gtktreedatalist.o	\
	gtktreednd.o		\
	gtktreemodel.o		\
	gtktreemodelfilter.o	\
	gtktreemodelsort.o	\
	gtktreeselection.o	\
	gtktreesortable.o	\
	gtktreestore.o		\
	gtktreeview.o		\
	gtktreeviewcolumn.o	\
	gtktypebuiltins.o	\
	gtktypeutils.o		\
	gtkuimanager.o		\
	gtkvbbox.o		\
	gtkvbox.o		\
	gtkvolumebutton.o	\
	gtkviewport.o		\
	gtkvpaned.o		\
	gtkvruler.o		\
	gtkvscale.o		\
	gtkvscrollbar.o		\
	gtkvseparator.o		\
	gtkwidget.o		\
	gtkwindow-decorate.o    \
	gtkwindow.o		\
	$(gtk_clipboard_dnd_c_sources)

# Broken
gtk_public_h_sources += \
	gtktext.h		\
	gtktree.h		\
	gtktreeitem.h
gtk_base_c_sources += \
	gtktext.o		\
	gtktree.o		\
	gtktreeitem.o

# Deprecated
gtk_public_h_sources += \
	gtkclist.h		\
	gtkcombo.h		\
	gtkctree.h		\
	gtkcurve.h		\
	gtkfilesel.h		\
	gtkgamma.h		\
	gtkinputdialog.h	\
	gtkitemfactory.h	\
	gtklist.h		\
	gtklistitem.h		\
	gtkoldeditable.h	\
	gtkoptionmenu.h		\
	gtkpixmap.h		\
	gtkpreview.h		\
	gtkprogress.h		\
	gtksignal.h		\
	gtktipsquery.h		\
	gtktooltips.h
gtk_base_c_sources += \
	gtkclist.o		\
	gtkcombo.o		\
	gtkctree.o		\
	gtkcurve.o		\
	gtkfilesel.o		\
	gtkgamma.o		\
	gtkitemfactory.o	\
	gtklist.o		\
	gtklistitem.o		\
	gtkoldeditable.o	\
	gtkoptionmenu.o		\
	gtkpixmap.o		\
	gtkpreview.o		\
	gtkprogress.o		\
	gtksignal.o		\
	gtktipsquery.o		\
	gtktooltips.o

gtk_c_sources = $(gtk_base_c_sources)
gtk_all_c_sources = $(gtk_base_c_sources)

gtk_os_unix_c_sources = \
	gtkcustompaperunixdialog.o	\
	gtkpagesetupunixdialog.o	\
	gtkprinter.o			\
	gtkprinteroption.o		\
	gtkprinteroptionset.o		\
	gtkprinteroptionwidget.o	\
	gtkprintjob.o			\
	gtkprintoperation-unix.o	\
	gtkprintunixdialog.o		\
        gtkprintbackend.o		\
	gtksearchenginebeagle.o		\
	gtksearchenginetracker.o
gtk_all_c_sources += $(gtk_os_unix_c_sources)

gtk_private_h_sources += \
	gtkiconcachevalidator.h		\
	gtkprintbackend.h		\
	gtkprinter-private.h		\
	gtkprinteroption.h		\
	gtkprinteroptionset.h		\
	gtkprinteroptionwidget.h	\
	gtksearchenginebeagle.h		\
	gtksearchenginetracker.h
gtk_c_sources += $(gtk_os_unix_c_sources)

gtk_use_x11_c_sources = \
	gtkplug-x11.o   \
	gtksocket-x11.o \
	gtkxembed.o     \
	gtktrayicon-x11.o \
	gtkmountoperation-x11.o
gtk_use_stub_c_sources = \
	gtkplug-stub.o   \
	gtksocket-stub.o \
	gtkmountoperation-stub.o
gtk_all_c_sources += $(gtk_use_x11_c_sources) $(gtk_use_stub_c_sources)

ifeq ($(GDKTARGET), x11)
gtk_private_h_sources += gtkxembed.h gtktrayicon.h xembed.h
gtk_c_sources += $(gtk_use_x11_c_sources)
else
gtk_c_sources += $(gtk_use_stub_c_sources)
endif

gtk_clipboard_dnd_c_sources = gtkclipboard.o gtkdnd.o

# built sources that get installed with the header files
gtk_built_public_sources =			\
	gtktypebuiltins.h

# built headers that don't get installed
gtk_built_private_headers =			\
	gtkbuiltincache.h

gtk_built_sources =				\
	gtktypebuiltins.o			\
	gtktypefuncs.o				\
	${gtk_built_private_headers}		\
	${gtk_built_public_sources}

stamp_files =					\
	stamp-gtktypebuiltins.h			\
	stamp-icons

# non-header sources (headers should be specified in the above variables)
# that don't serve as direct make target sources, i.e. they don't have
# their own .lo rules and don't get publically installed
gtk_extra_sources =				\
	paper_names.o				\
	paper_names_offsets.o			\
	gen-paper-names.o			\
	gtkversion.h.in

#
# setup GTK+ sources and their dependencies
#
MAINTAINERCLEANFILES = $(gtk_built_sources) $(stamp_files) $(GENERATED_ICONS) stock-icons/icon-theme.cache
EXTRA_HEADERS =
EXTRA_DIST += $(gtk_private_h_sources) $(gtk_extra_sources)
EXTRA_DIST += $(gtk_built_sources)
EXTRA_DIST += $(STOCK_ICONS)

mkinstalldirs = mkdir -p
INSTALL_DATA = cp -r

# Install a RC file for the default GTK+ theme, and key themes
install-data-local:
	$(mkinstalldirs) $(DESTDIR)$(datadir)/themes/Raleigh/gtk-2.0
	$(INSTALL_DATA) $(srcdir)/gtkrc.default $(DESTDIR)$(datadir)/themes/Raleigh/gtk-2.0/gtkrc
	$(mkinstalldirs) $(DESTDIR)$(datadir)/themes/Default/gtk-2.0-key
	$(INSTALL_DATA) $(srcdir)/gtkrc.key.default $(DESTDIR)$(datadir)/themes/Default/gtk-2.0-key/gtkrc
	$(mkinstalldirs) $(DESTDIR)$(datadir)/themes/Emacs/gtk-2.0-key
	$(INSTALL_DATA) $(srcdir)/gtkrc.key.emacs $(DESTDIR)$(datadir)/themes/Emacs/gtk-2.0-key/gtkrc

uninstall-local:
	rm -f $(DESTDIR)$(datadir)/themes/Raleigh/gtk-2.0/gtkrc
	rm -f $(DESTDIR)$(datadir)/themes/Default/gtk-2.0-key/gtkrc
	rm -f $(DESTDIR)$(datadir)/themes/Emacs/gtk-2.0-key/gtkrc

#gtk_all_c_sources
#gtk_public_h_sources

