.POSIX:

configure: configure.c
	${CC} ${CFLAGS} configure.c -o configure

all: configure

clean:
	rm configure

.PHONY: all clean
