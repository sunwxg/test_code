C_COMPILER=gcc

CFLAGS=-std=c99
CFLAGS+= -Wall -g

TARGET=mssh

TEST_DIR=test/
TEST_BUILD_DIR=test/build/
TEST_TARGET=test
TEST_SRC_FILES=$(wildcard $(TEST_DIR)src/*.c)
TEST_SRC_FILES+=$(wildcard $(TEST_DIR)*.c)

SRC_DIR=src/
#SRC_FILES=$(wildcard $(SRC_DIR)*.c)
SRC_FILES=$(SRC_DIR)internal.c
SRCS=$(SRC_DIR)main.c $(SRC_DIR)internal.c 
SRC_LIB=-lutil

INC_DIRS=-I$(SRC_DIR) -I$(TEST_DIR)src

all: target 

test: clean_obj gen_test default run

vtest: clean_obj gen_test default vrun

default:
	@$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(TEST_SRC_FILES) \
	$(SRC_FILES) -o $(TEST_BUILD_DIR)$(TEST_TARGET)

target:
	@$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SRCS) -o $(TARGET) $(SRC_LIB)

.PHONY: run vrun gen_test clean_obj clean tags

run:
	$(TEST_DIR)src/run.sh

vrun:
	$(TEST_DIR)src/run.sh -v

gen_test:
	@rm -f $(TEST_DIR)AllTests.c
	@$(TEST_DIR)src/gen_main.sh > $(TEST_DIR)AllTests.c

clean_obj:
	@rm -f $(TEST_BUILD_DIR)*

clean: clean_obj
	
tags:
	@echo "generating tags and cscopes"
	@rm -f cscope.* tags
	@find . -name "*.[hc]" > cscope.files
	@find /usr/include/ -name "*.[ch]" -type f >>cscope.files
	@find /usr/local/include -name "*.[ch]" -type f >>cscope.files
	@find /usr/lib/gcc -name "*.[ch]" -type f >>cscope.files
	@cscope -b -q -k
	@ctags -L cscope.files
