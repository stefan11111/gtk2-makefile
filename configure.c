#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define CHECK(opt) !strncmp(argv[i], (opt), sizeof((opt)) - 1)

#define CHECK_ENABLE(opt) \
        if (CHECK("--enable-"#opt)) { \
            flags->opt = 1; \
        }

#define CHECK_DISABLE(opt) \
        if (CHECK("--disable-"#opt)) { \
            flags->opt = 1; \
        }

#define CHECK_STRING(name) \
        if (CHECK("--"#name"=")) { \
            flags->name = argv[i] + sizeof("--"#name"=") - 1; \
        }

typedef struct {
    int x11:2;
    int directfb:2;
    int print:2;
    int cups:2;
    int xinerama:2;
    int langinfo:2;
    int http_authstring:2;
    int papi:2;
    int shm:2;
    int xkb:2;
    int xinput:2;
    int xcursor:2;
    int xfixes:2;
    int xcomposite:2;
    int xdamage:2;
    int x11r6:2;
    int xsync:2;
    int xrandr:2;
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

static void parse_arguments (int argc, char **argv, flags_t *flags)
{
    memset(flags, 0, sizeof(flags_t));

    for(int i = 1; i < argc; i++) {
        if (CHECK("--with-gdktarget=x11")) {
            flags->x11 = 1;
            flags->shm = 1;
            flags->xkb = 1;
            flags->xinput = 1;
            flags->xcursor = 1;
            flags->xfixes = 1;
            flags->xcomposite = 1;
            flags->xdamage = 1;
            flags->x11r6 = 1;
            flags->xsync = 1;
            flags->xrandr = 1;
        }

        CHECK_DISABLE(shm);
        CHECK_DISABLE(xkb);
        CHECK_DISABLE(xinput);
        CHECK_DISABLE(xcursor);
        CHECK_DISABLE(xfixes);
        CHECK_DISABLE(xinput);
        CHECK_DISABLE(xcursor);
        CHECK_DISABLE(xfixes);
        CHECK_DISABLE(xcomposite);
        CHECK_DISABLE(xdamage);
        CHECK_DISABLE(x11r6);
        CHECK_DISABLE(xsync);
        CHECK_DISABLE(xrandr);

        if (CHECK("--with-gdktarget=directfb")) {
            flags->directfb = 1;
        }

        CHECK_ENABLE(print);
        CHECK_ENABLE(cups);
        CHECK_ENABLE(xinerama);
        CHECK_ENABLE(langinfo);
        CHECK_ENABLE(http_authstring);
        CHECK_ENABLE(papi);

        CHECK_STRING(prefix);
        CHECK_STRING(bindir);
        CHECK_STRING(mandir);
        CHECK_STRING(infodir);
        CHECK_STRING(datadir);
        CHECK_STRING(sysconfdir);
        CHECK_STRING(localstatedir);
        CHECK_STRING(datarootdir);
        CHECK_STRING(docdir);
        CHECK_STRING(htmldir);
        CHECK_STRING(libdir);
        CHECK_STRING(CUPS_CONFIG);

        if (CHECK("--with-sysroot=")) {
            flags->sysroot = argv[i] + sizeof("--with-sysroot=") - 1;
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

#define APPEND_OPTION_TO_ENVP(name, NAME) \
    if (flags->name) { \
        envp[++it] = NAME; \
    }

static void run_build(flags_t *flags)
{
    char *envp[29];
    memset(envp, 0 ,sizeof(envp));
    int it = 0;
    if (flags->x11) {
        envp[it] = "GDKTARGET=x11";
    }
    if (flags->directfb) {
        envp[it] = "GDKTARGET=directfb";
    }

    it++;

    APPEND_OPTION_TO_ENVP(print, "PRINT_SUPPORT=1");
    APPEND_OPTION_TO_ENVP(cups, "CUPS_SUPPORT=1");
    APPEND_OPTION_TO_ENVP(xinerama, "XINERAMA_SUPPORT=1");
    APPEND_OPTION_TO_ENVP(langinfo, "LANGINFO_SUPPORT=1");
    APPEND_OPTION_TO_ENVP(http_authstring, "HTTP_AUTHSTRING_SUPPORT=1");
    APPEND_OPTION_TO_ENVP(papi, "PAPI_SUPPORT=1");
    APPEND_OPTION_TO_ENVP(shm, "SHM_SUPPORT=1");
    APPEND_OPTION_TO_ENVP(xkb, "XKB_SUPPORT=1");
    APPEND_OPTION_TO_ENVP(xinput, "XINPUT_SUPPORT=1");
    APPEND_OPTION_TO_ENVP(xcursor, "XCURSOR_SUPPORT=1");
    APPEND_OPTION_TO_ENVP(xfixes, "XFIXES_SUPPORT=1");
    APPEND_OPTION_TO_ENVP(xcomposite, "XCOMPOSITE_SUPPORT=1");
    APPEND_OPTION_TO_ENVP(xdamage, "XDAMAGE_SUPPORT=1");
    APPEND_OPTION_TO_ENVP(x11r6, "X11R6_SUPPORT=1");
    APPEND_OPTION_TO_ENVP(xsync, "XSYNC_SUPPORT=1");
    APPEND_OPTION_TO_ENVP(xrandr, "XRANDR_SUPPORT=1");

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
