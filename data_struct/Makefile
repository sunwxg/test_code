PREFIX?=../build/
C_COMPILER=gcc

CFLAGS+=-std=c99
CFLAGS+= -Wall

TEST_DIR=test/
TEST_BUILD_DIR=test/build/
TEST_TARGET=test
TEST_SRC_FILES=$(wildcard $(TEST_DIR)src/*.c)
TEST_SRC_FILES+=$(wildcard $(TEST_DIR)*.c)

SRC_DIR=src/
SRC_FILES=$(wildcard $(SRC_DIR)*.c)
TARGET_FILES=$(patsubst %.c,%.o,$(SRC_FILES))
BUILD_DIR=build
TARGET=mydatabase

INC_DIRS=-I$(SRC_DIR) -I$(TEST_DIR)src

all: clean_obj build gen_test test run

vtest: clean_obj gen_test test vrun

debug:
	@CFLAGS=-g $(MAKE)

test:
	@$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(TEST_SRC_FILES) \
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

.PHONY: run vrun gen_test clean_obj clean tags test build_dir

run:
	$(TEST_DIR)src/run.sh

vrun:
	$(TEST_DIR)src/run.sh -v

build_dir:
	@mkdir -p $(BUILD_DIR)

gen_test:
	@rm -f $(TEST_DIR)AllTests.c
	@$(TEST_DIR)src/gen_main.sh > $(TEST_DIR)AllTests.c

clean_obj:
	@rm -f $(TEST_BUILD_DIR)*

clean: clean_obj
	@rm -f cscope.* tags
	@rm -f src/*.o
	@rm -f build/*
	
tags:
	@rm -f cscope.* tags
	@find . -name "*.[hc]" > cscope.files
	@find /usr/include/ -name "*.[ch]" -type f >>cscope.files
	@find /usr/local/include -name "*.[ch]" -type f >>cscope.files
	@cscope -b -q -k
	@ctags -L cscope.files
