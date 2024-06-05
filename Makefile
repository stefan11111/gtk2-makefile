.POSIX:

all:

configure: configure.c
	${CC} ${CFLAGS} configure.c -o configure

clean:
	rm -f configure

.PHONY: all clean
