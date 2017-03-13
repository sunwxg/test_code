CC=g++
CFLAGS+=-g -Wall
CFLAGS+=`pkg-config --cflags --libs QtCore QtGui`

OBJ=version simple no_title_bar popup

all: ${OBJ}

version: version.cpp
	${CC} ${CFLAGS} $^ -o $@ ${LFLAGS}

simple: simple.cpp
	${CC} ${CFLAGS} $^ -o $@ ${LFLAGS}

no_title_bar: no_title_bar.cpp
	${CC} ${CFLAGS} $^ -o $@ ${LFLAGS}

popup: popup.cpp
	${CC} ${CFLAGS} $^ -o $@ ${LFLAGS}

clean: ${OBJ}
	@rm -f $^
