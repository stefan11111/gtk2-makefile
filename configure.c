#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x11:2;
    int directfb:2;
    int print:2;
    int cups:2;
    int xinerama:2;
    int introspection:2;
    char *prefix;
    char *mandir;
    char *infodir;
    char *datadir;
    char *sysconfdir;
    char *localstatedir;
    char *datarootdir;
    char *docdir;
    char *htmldir;
    char *sysroot;
    char *libdir;
    char *CUPS_CONFIG;
} flags_t;

#define CHECK(opt) !strncmp(argv[i], (opt), sizeof((opt)) - 1)

void parse_arguments (int argc, char **argv, flags_t *flags)
{
    memset(flags, 0, sizeof(flags_t));

    for(int i = 1; i < argc; i++) {
        if (CHECK("--with-gdktarget=x11")) {
            flags->x11 = 1;
        }

        if (CHECK("--with-gdktarget=directfb")) {
            flags->directfb = 1;
        }

        if (CHECK("--enable-print")) {
            flags->print = 1;
        }

        if (CHECK("--enable-cups")) {
            flags->cups = 1;
        }

        if (CHECK("--enable-xinerama")) {
            flags->xinerama = 1;
        }

        if (CHECK("--enable-introspection")) {
            flags->print = 1;
        }

        if (CHECK("--prefix=")) {
            flags->prefix; argv[i] + sizeof("--prefix=") - 1;
        }

        if (CHECK("--mandir=")) {
            flags->mandir; argv[i] + sizeof("--mandir=") - 1;
        }

        if (CHECK("--infodir=")) {
            flags->infodir; argv[i] + sizeof("--infodir=") - 1;
        }

        if (CHECK("--datadir=")) {
            flags->datadir; argv[i] + sizeof("--datadir=") - 1;
        }

        if (CHECK("--sysconfdir=")) {
            flags->sysconfdir; argv[i] + sizeof("--sysconfdir=") - 1;
        }

        if (CHECK("--localstatedir=")) {
            flags->localstatedir; argv[i] + sizeof("--localstatedir=") - 1;
        }

        if (CHECK("--datarootdir=")) {
            flags->datarootdir; argv[i] + sizeof("--datarootdir=") - 1;
        }

        if (CHECK("--docdir=")) {
            flags->docdir; argv[i] + sizeof("--docdir=") - 1;
        }

        if (CHECK("--htmldir=")) {
            flags->htmldir; argv[i] + sizeof("--htmldir=") - 1;
        }

        if (CHECK("--with-sysroot=")) {
            flags->sysroot; argv[i] + sizeof("--with-sysroot=") - 1;
        }

        if (CHECK("--libdir=")) {
            flags->libdir; argv[i] + sizeof("--libdir=") - 1;
        }

        if (CHECK("CUPS_CONFIG=")) {
            flags->CUPS_CONFIG; argv[i] + sizeof("--CUPS_CONFIG=") - 1;
        }
    }
}

int main(int argc, char **argv)
{
    flags_t flags;
    parse_arguments(argc, argv, &flags);
}
