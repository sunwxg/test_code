CFLAGS=-g -Wall -pthread
CFLAGS+=`pkg-config --cflags --libs gobject-2.0`
CFLAGS+=`pkg-config --cflags --libs gobject-introspection-1.0`
CFLAGS+=`pkg-config --cflags --libs gjs-1.0`
CC=gcc

SRC=my_obj.c hello-world.c hello-world.h gifunc-hello.h gifunc-hello.c

all: my_obj gir-obj gir-func typelib-obj typelib-func my_gjs xml

my_obj: ${SRC}
	${CC} ${CFLAGS} $^ -o $@ ${LFLAGS}

gir-func: ${SRC}
	@libtool compile gcc `pkg-config --cflags gobject-2.0` \
	-g -c gifunc-hello.c -o gifunc.lo

	@libtool link gcc `pkg-config --libs gobject-2.0` \
	-rpath /usr/local/lib \
	gifunc.lo -o libgifunc.la

	g-ir-scanner gifunc-hello.[ch] \
	--library=gifunc \
	`pkg-config --cflags gobject-2.0` \
	--namespace=Gifunc --nsversion=0.1 --output=Gifunc-0.1.gir

typelib-func: gir-func
	g-ir-compiler Gifunc-0.1.gir --output=Gifunc-0.1.typelib

gir-obj: ${SRC}
	@libtool compile gcc `pkg-config --cflags gobject-2.0` \
	-g -c hello-world.c -o hello-world.lo

	@libtool link gcc `pkg-config --libs gobject-2.0` \
	-rpath /usr/local/lib \
	hello-world.lo -o libhello.la

	g-ir-scanner hello-world.[ch] \
	--library=hello \
	`pkg-config --cflags gobject-2.0` --include=GObject-2.0 \
	--namespace=Hello --nsversion=0.1 --output=Hello-0.1.gir

typelib-obj: gir-obj
	g-ir-compiler Hello-0.1.gir --output=Hello-0.1.typelib

my_gjs: my_gjs.c
	${CC} ${CFLAGS} $^ -o $@ ${LFLAGS}

xml: typelib-obj typelib-func
	g-ir-generate Gifunc-0.1.typelib > Gifunc-0.1.typelib.xml
	g-ir-generate Hello-0.1.typelib > Hello-0.1.typelib.xml

.PHONY: compile clean

compile: ${SRC}
	${CC} -E ${CFLAGS} $^

clean:
	@rm -rf *gir *typelib *lo *la *.o my_obj my_gjs .libs *xml
