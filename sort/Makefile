C_COMPILER=gcc

CFLAGS=-std=c99
CFLAGS += -Wall

SRC_DIR=src/
TEST_DIR=test/
BUILD_DIR=test/build/
TARGET_BASE1=sort_test
TARGET1 = $(TARGET_BASE1)
SRC_TEST_FILES1=$(TEST_DIR)src/unity_fixture.c $(TEST_DIR)src/unity.c
SRC_TEST_FILES1+=$(TEST_DIR)AllTests.c $(TEST_DIR)insertion_sort_test.c\
		$(TEST_DIR)quick_sort_test.c
INC_DIRS=-Isrc -I$(TEST_DIR)src
SRC_TEST_FILES+=$(SRC_DIR)insert_sort.c

all: clean_obj default

default:
	@$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_TEST_FILES)\
		$(SRC_TEST_FILES1) -o $(BUILD_DIR)$(TARGET1)
	$(TEST_DIR)run.sh

vtest: clean_obj
	@$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_TEST_FILES)\
		$(SRC_TEST_FILES1) -o $(BUILD_DIR)$(TARGET1)
	$(TEST_DIR)run.sh -v

clean_obj:
	@rm -f $(TARGET_BASE1)
	@rm -f $(BUILD_DIR)*

clean:
	@rm -f $(TARGET_BASE1)
	@rm -f $(BUILD_DIR)*
	@rm -f cscope.*
	@rm -f tags
	
tags:
	@echo making cscope.out and tags
	@rm -f cscope.* tags
	@find . -name "*.[hc]" > cscope.files
	@find /usr/include/ -name "*.[ch]" -type f >>cscope.files
	@find /usr/local/include -name "*.[ch]" -type f >>cscope.files
	@cscope -b -q -k
	@ctags -L cscope.files
