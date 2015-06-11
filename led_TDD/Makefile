C_COMPILER=gcc

CFLAGS=-std=c99
CFLAGS += -Wall -g

TARGET_BASE1=LedDriverTest
TARGET1 = $(TARGET_BASE1)
SRC_FILES=test/src/unity.c
SRC_FILES1=$(SRC_FILES) test/LedDriverTest.c
TARGET_BUILD=test/build
INC_DIRS=-Isrc -Itest/src
SYMBOLS=-DTEST

all: clean default

default:
	@$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -o $(TARGET_BUILD)/$(TARGET1)
	./$(TARGET_BUILD)/$(TARGET1)

clean:
	@rm -f $(TARGET_BUILD)/$(TARGET_BASE1)
	@rm -f cscope.* tags

tags:
	rm -f cscope.* tags
	find . -name "*.[hc]" > cscope.files
	find /usr/include/ -name "*.[ch]" -type f >>cscope.files
	find /usr/local/include -name "*.[ch]" -type f >>cscope.files
	cscope -b -q -k
	ctags -L cscope.files
