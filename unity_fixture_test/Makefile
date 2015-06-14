C_COMPILER=gcc

CFLAGS=-std=c99
CFLAGS += -Wall

TEST_DIR=test/
BUILD_DIR=test/build/
TARGET_BASE1=test1
TARGET1 = $(TARGET_BASE1)
SRC_FILES=$(TEST_DIR)src/unity_fixture.c $(TEST_DIR)src/unity.c
SRC_FILES1=$(TEST_DIR)AllTests.c $(TEST_DIR)test1.c $(TEST_DIR)test2.c
INC_DIRS=-Isrc -I$(TEST_DIR)src

all: clean_obj default

default:
	@$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES) $(SRC_FILES1) -o $(BUILD_DIR)$(TARGET1)
	. $(TEST_DIR)run.sh

clean_obj:
	@rm -f $(TARGET_BASE1)
	@rm -f $(BUILD_DIR)*

clean:
	@rm -f $(TARGET_BASE1)
	@rm -f $(BUILD_DIR)*
	@rm -f cscope.*
	@rm -f tags
	
tags:
	rm -f cscope.* tags
	find . -name "*.[hc]" > cscope.files
	find /usr/include/ -name "*.[ch]" -type f >>cscope.files
	find /usr/local/include -name "*.[ch]" -type f >>cscope.files
	cscope -b -q -k
	ctags -L cscope.files
