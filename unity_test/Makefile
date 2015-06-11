C_COMPILER=gcc

CFLAGS=-std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror 
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition

TARGET_BASE1=test1
TARGET1 = $(TARGET_BASE1)
SRC_FILES=test/src/unity.c
SRC_FILES1=test/test1.c
INC_DIRS=-Isrc -Itest/src
SYMBOLS=-DTEST

all: clean default

default:
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES) $(SRC_FILES1) -o $(TARGET1)
	./$(TARGET1)

clean:
	rm -f $(TARGET_BASE1)

tags:
	rm -f cscope.* tags
	find . -name "*.[hc]" > cscope.files
	find /usr/include/ -name "*.[ch]" -type f >>cscope.files
	find /usr/local/include -name "*.[ch]" -type f >>cscope.files
	cscope -b -q -k
	ctags -L cscope.files
