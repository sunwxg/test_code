PREFIX?=../build/
C_COMPILER=gcc

CFLAGS= -std=c99
CFLAGS+= -Wall

SRC_DIR=src/
SRC_FILES=$(wildcard $(SRC_DIR)*.c)
TARGET_FILES=$(patsubst %.c,%.o,$(SRC_FILES))
BUILD_DIR=build
TARGET=mysort

TEST_DIR=test/
TEST_BUILD_DIR=test/build/

TEST_TARGET =sort_test
SRC_TEST_FILES=$(wildcard test/src/*.c test/*.c)
SRC_TEST_FILES+=$(SRC_DIR)sort_internal.c $(SRC_DIR)insert_sort.c

INC_DIRS=-Isrc -I$(TEST_DIR)src

all: clean_obj build gen_test default run

test: clean_obj gen_test default run

vtest: clean_obj gen_test default vrun

default:
	@$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_TEST_FILES)\
		-o $(TEST_BUILD_DIR)$(TEST_TARGET)

build: build_dir target
	ar rcs $(BUILD_DIR)/lib$(TARGET).a $(TARGET_FILES) 
	$(C_COMPILER) -shared -o $(BUILD_DIR)/lib$(TARGET).so $(TARGET_FILES)

target: CFLAGS+=-fPIC 
target: $(TARGET_FILES)

%.o: %.c
	@$(C_COMPILER) $(CFLAGS) $(INC_DIRS) -c -o $@ $? 
	
install:
	@echo copying files to $(PREFIX)
	@cp $(BUILD_DIR)/* $(PREFIX)
	@ls $(SRC_DIR)/*.h |grep -v internal |xargs -I{} cp {} $(PREFIX)

.PHONY: test run vrun gen_test clean_obj clean tags build_dir

run:
	@$(TEST_DIR)run.sh

vrun:
	@$(TEST_DIR)run.sh -v

gen_test:
	@$(TEST_DIR)gen_main.sh > $(TEST_DIR)AllTests.c

build_dir:
	@mkdir -p $(BUILD_DIR)

clean_obj:
	@rm -f $(TEST_TARGET)
	@rm -f $(TEST_BUILD_DIR)*

clean: clean_obj
	@rm -f cscope.*
	@rm -f tags
	@rm -f src/*.o
	@rm -f build/*
	
tags:
	@echo making cscope.out and tags
	@rm -f cscope.* tags
	@find . -name "*.[hc]" > cscope.files
	@find /usr/include/ -name "*.[ch]" -type f >>cscope.files
	@find /usr/local/include -name "*.[ch]" -type f >>cscope.files
	@cscope -b -q -k
	@ctags -L cscope.files
