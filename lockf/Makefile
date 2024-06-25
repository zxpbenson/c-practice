# $FreeBSD: src/usr.bin/lockf/Makefile,v 1.6 2002/02/08 22:31:41 markm Exp $

PROG=	lockf

all: 
	gcc -DLINUX -o lockf lockf.c
	bzip2 -9 -c lockf.1 > lockf.1.bz2

clean: 
	rm lockf lockf.1.bz2

install: 
	install -m 0755 lockf /usr/bin/lockf
	install -m 0644 lockf.1.bz2 /usr/share/man/man1/lockf.1.bz2

deinstall:
	rm /usr/bin/lockf /usr/share/man/man1/lockf.1.bz2
