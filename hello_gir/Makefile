CFLAGS=-g -Wall -pthread
CFLAGS+=`pkg-config --cflags gobject-2.0`
CFLAGS+=`pkg-config --cflags gobject-introspection-1.0`
CFLAGS+=`pkg-config --cflags gjs-1.0`

LFLAGS+=`pkg-config --libs gobject-2.0`
LFLAGS+=`pkg-config --libs gobject-introspection-1.0 gmodule-2.0`
LFLAGS+=`pkg-config --libs gjs-1.0`
CC=gcc

SRC=my_obj.c hello-world.c hello-world.h

all: my_obj libs my_gjs

my_obj: ${SRC}
	${CC} ${CFLAGS} $^ -o $@ ${LFLAGS}

gjs: ${DEST} my_gjs gir typelib

my_gjs: my_gjs.c
	${CC} ${CFLAGS} $^ -o $@ ${LFLAGS}

.PHONY: compile gir typelib libs clean

compile: ${SRC}
	${CC} -E ${CFLAGS} $^

gir: ${DEST}
	g-ir-scanner hello-world.[ch] \
	--program=./my_obj \
	`pkg-config --cflags gobject-introspection-1.0` --include=GObject-2.0 \
	--namespace=Hello --nsversion=0.1 --output=Hello-0.1.gir \
	--warn-all

typelib: gir
	g-ir-compiler Hello-0.1.gir --output=Hello-0.1.typelib

libs:
	@libtool compile gcc `pkg-config --cflags gobject-2.0` \
	-g -c hello-world.c -o hello-world.lo
	@libtool link gcc `pkg-config --libs gobject-2.0` \
	-rpath /usr/local/lib \
	hello-world.lo -o libhello.la

	@g-ir-scanner hello-world.[ch] \
	--library=hello \
	`pkg-config --cflags gobject-2.0` --include=GObject-2.0 \
	--namespace=Hello --nsversion=0.1 --output=Hello-0.1.gir

	@g-ir-compiler Hello-0.1.gir --output=Hello-0.1.typelib

clean:
	rm -rf *gir *typelib *lo *la *.o my_obj my_gjs .libs
