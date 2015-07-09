C_COMPILER=gcc

CFLAGS=-std=c99
CFLAGS+= -Wall

TEST_DIR=test/
TEST_BUILD_DIR=test/build/
TEST_TARGET=test
TEST_SRC_FILES=$(wildcard $(TEST_DIR)src/*.c)
TEST_SRC_FILES+=$(wildcard $(TEST_DIR)*.c)

SRC_DIR=src/
SRC_FILES=$(wildcard $(SRC_DIR)*.c)

INC_DIRS=-I$(SRC_DIR) -I$(TEST_DIR)src

all: clean_obj gen_test default run

vtest: clean_obj gen_test default vrun

default:
	@$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(TEST_SRC_FILES) $(SRC_FILES)\
		-o $(TEST_BUILD_DIR)$(TEST_TARGET)

.PHONY: run vrun gen_test clean_obj clean

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
	
