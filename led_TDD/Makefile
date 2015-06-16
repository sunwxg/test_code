C_COMPILER=gcc

CFLAGS=-std=c99
CFLAGS += -Wall -g
CFLAGS += -s

TEST_DIR=test/
TARGET=AllTest
SRC_FILES=$(wildcard test/src/*.c test/*.c src/*.c)
TARGET_BUILD=test/build
INC_DIRS=-Iinclude -Itest/src

all: clean_test default

default:
	@$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES) -o $(TARGET_BUILD)/$(TARGET)
	@echo "-------------------------------------------"
	$(TEST_DIR)run.sh

clean_test:
	@rm -f $(TARGET_BUILD)/$(TARGET)
clean:
	@rm -f $(TARGET_BUILD)/$(TARGET)
	@rm -f cscope.* tags

.PHONY: test vtest clean_test clean

test: clean_test
	@$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES) -o $(TARGET_BUILD)/$(TARGET)
	@echo "-------------------------------------------"
	$(TEST_DIR)run.sh

vtest: clean_test
	@$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES) -o $(TARGET_BUILD)/$(TARGET)
	@echo "-------------------------------------------"
	$(TEST_DIR)run.sh -v
	
tags:
	rm -f cscope.* tags
	find . -name "*.[hc]" > cscope.files
	find /usr/include/ -name "*.[ch]" -type f >>cscope.files
	find /usr/local/include -name "*.[ch]" -type f >>cscope.files
	cscope -b -q -k
	ctags -L cscope.files
