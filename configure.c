#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

typedef struct {
    int x11:2;
    int directfb:2;
    int print:2;
    int cups:2;
    int xinerama:2;
    int introspection:2;
    int rebuilds:2;
    int shm:2;
    int xkb:2;
    int xinput:2;
    char *prefix;
    char *bindir;
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

static void parse_arguments (int argc, char **argv, flags_t *flags)
{
    memset(flags, 0, sizeof(flags_t));

    for(int i = 1; i < argc; i++) {
        if (CHECK("--with-gdktarget=x11")) {
            flags->x11 = 1;
            flags->shm = 1;
            flags->xkb = 1;
            flags->xinput = 1;
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

        if (CHECK("--enable-rebuilds")) {
            flags->rebuilds = 1;
        }

        if (CHECK("--disable-shm")) {
            flags->shm = 0;
        }

        if (CHECK("--disable-xkb")) {
            flags->xkb = 0;
        }

        if (CHECK("--disable-xinput")) {
            flags->xinput = 0;
        }

        if (CHECK("--enable-introspection")) {
            flags->print = 1;
        }

        if (CHECK("--prefix=")) {
            flags->prefix = argv[i] + sizeof("--prefix=") - 1;
        }

        if (CHECK("--bindir=")) {
            flags->bindir = argv[i] + sizeof("--bindir=") - 1;
        }

        if (CHECK("--mandir=")) {
            flags->mandir = argv[i] + sizeof("--mandir=") - 1;
        }

        if (CHECK("--infodir=")) {
            flags->infodir = argv[i] + sizeof("--infodir=") - 1;
        }

        if (CHECK("--datadir=")) {
            flags->datadir = argv[i] + sizeof("--datadir=") - 1;
        }

        if (CHECK("--sysconfdir=")) {
            flags->sysconfdir = argv[i] + sizeof("--sysconfdir=") - 1;
        }

        if (CHECK("--localstatedir=")) {
            flags->localstatedir = argv[i] + sizeof("--localstatedir=") - 1;
        }

        if (CHECK("--datarootdir=")) {
            flags->datarootdir = argv[i] + sizeof("--datarootdir=") - 1;
        }

        if (CHECK("--docdir=")) {
            flags->docdir = argv[i] + sizeof("--docdir=") - 1;
        }

        if (CHECK("--htmldir=")) {
            flags->htmldir = argv[i] + sizeof("--htmldir=") - 1;
        }

        if (CHECK("--with-sysroot=")) {
            flags->sysroot = argv[i] + sizeof("--with-sysroot=") - 1;
        }

        if (CHECK("--libdir=")) {
            flags->libdir = argv[i] + sizeof("--libdir=") - 1;
        }

        if (CHECK("CUPS_CONFIG=")) {
            flags->CUPS_CONFIG = argv[i] + sizeof("--CUPS_CONFIG=") - 1;
        }
    }
}

#define APPEND_TO_ENVP(name, NAME) \
    if (flags->name) { \
        envp[it] = (char*)malloc(strlen(flags->name) + sizeof(NAME)); \
        strcpy(envp[it], NAME); \
        strcpy(envp[it] + sizeof(NAME) - 1, flags->name); \
        it++; \
    }

static void run_build(flags_t *flags)
{
    char *envp[23];
    memset(envp, 0 ,sizeof(envp));
    int it = 0;
    if (flags->x11) {
        envp[it] = "TARGET=x11";
    }
    if (flags->directfb) {
        envp[it] = "TARGET=directfb";
    }

    it++;

    if (flags->print) {
        envp[++it] = "PRINT_SUPPORT=1";
    }

    if (flags->cups) {
        envp[++it] = "CUPS_SUPPORT=1";
    }

    if (flags->xinerama) {
        envp[++it] = "XINERAMA_SUPPORT=1";
    }

    if (flags->introspection) {
        envp[++it] = "INTROSPECTION_SUPPORT=1";
    }

    if (flags->rebuilds) {
        envp[++it] = "REBUILDS=1";
    }

    if (flags->shm) {
        envp[++it] = "SHM_SUPPORT=1";
    }

    if (flags->xkb) {
        envp[++it] = "XKB_SUPPORT=1";
    }

    if (flags->xinput) {
        envp[++it] = "XINPUT_SUPPORT=1";
    }

    APPEND_TO_ENVP(prefix, "PREFIX=");
    APPEND_TO_ENVP(bindir, "BINDIR=");
    APPEND_TO_ENVP(mandir, "MANDIR=");
    APPEND_TO_ENVP(infodir, "INFODIR");
    APPEND_TO_ENVP(datadir, "DATADIR=");
    APPEND_TO_ENVP(localstatedir, "LOCALSTATEDIR=");
    APPEND_TO_ENVP(datarootdir, "DATAROOTDIR=");
    APPEND_TO_ENVP(docdir, "DOCDIR=");
    APPEND_TO_ENVP(htmldir, "HTMLDIR=");
    APPEND_TO_ENVP(sysroot, "SYSROOT=");
    APPEND_TO_ENVP(libdir, "LIBDIR=");
    APPEND_TO_ENVP(CUPS_CONFIG, "CUPS_CONFIG=");
    envp[it] = NULL;

    if (!flags->prefix && !flags->bindir) {
        execve("/usr/bin/make", NULL, envp);
        return; /* unreacheble */
    }

    if (flags->bindir) {
        char *makedir = (char*)malloc(strlen(flags->bindir) + sizeof("/make"));

        strcpy(makedir, flags->bindir);
        strcpy(makedir + strlen(flags->bindir), "/make");

        execve(makedir, NULL, envp);
        return; /* unreachable */
    }
    char *makedir = (char*)malloc(strlen(flags->prefix) + sizeof("/bin/make"));

    strcpy(makedir, flags->prefix);
    strcpy(makedir + strlen(flags->prefix), "/bin/make");

    execve(makedir, NULL, envp);
}

int main(int argc, char **argv)
{
    flags_t flags;
    parse_arguments(argc, argv, &flags);

    if(!flags.x11 && !flags.directfb) {
        flags.x11 = 1;
    }

    if(flags.x11 && flags.directfb) {
        if(!fork()) {
            flags.x11 = 0;
            flags.directfb = 1;
            run_build(&flags);
        }
        else {
            int status;
            wait(&status);
            flags.x11 = 1;
            flags.directfb = 0;
            run_build(&flags);
        }
        return 0; /* unreachable */
    }

    run_build(&flags);
    return 0; /* unreacheble */
}
