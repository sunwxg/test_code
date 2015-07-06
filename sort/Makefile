C_COMPILER=gcc

CFLAGS= -std=c99
CFLAGS+= -Wall

SRC_DIR=src/
TEST_DIR=test/
TEST_BUILD_DIR=test/build/

TARGET =sort_test
SRC_TEST_FILES=$(wildcard test/src/*.c test/*.c)
SRC_TEST_FILES+=$(SRC_DIR)sort_internal.c $(SRC_DIR)insert_sort.c

INC_DIRS=-Isrc -I$(TEST_DIR)src

all: clean_obj gen_test default run

vtest: clean_obj gen_test default vrun

default:
	@$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_TEST_FILES)\
		-o $(TEST_BUILD_DIR)$(TARGET)

run:
	$(TEST_DIR)run.sh

vrun:
	$(TEST_DIR)run.sh -v

gen_test:
	@$(TEST_DIR)gen_main.sh > $(TEST_DIR)AllTests.c

clean_obj:
	@rm -f $(TARGET)
	@rm -f $(TEST_BUILD_DIR)*

clean: clean_obj
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
