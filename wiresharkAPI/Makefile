C_COMPILER=gcc

CFLAGS= -std=c99
CFLAGS+= -Wall

#SRC_DIR=src/
SRC_FILES=t2.c
#SRC_FILES=$(wildcard $(SRC_DIR)*.c)
#TARGET_FILES=$(patsubst %.c,%.o,$(SRC_FILES))
#BUILD_DIR=build
TARGET=t2

#TEST_DIR=test/
#TEST_BUILD_DIR=test/build/

#TEST_TARGET =sort_test
#SRC_TEST_FILES=$(wildcard test/src/*.c test/*.c)
#SRC_TEST_FILES+=$(SRC_DIR)sort_internal.c $(SRC_DIR)insert_sort.c

INC_DIRS=-Isrc -I$(INC_PATH)glib-2.0
INC_DIRS+=-I/usr/lib/x86_64-linux-gnu/glib-2.0/include/
INC_DIRS+=-I/usr/include/wireshark/
INC_PATH=/usr/include/

#all: clean_obj build gen_test default run

#test: clean_obj gen_test default run

#vtest: clean_obj gen_test default vrun

default:
	@$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES)\
		-o $(TARGET)

#build: build_dir target
	#ar rcs $(BUILD_DIR)/lib$(TARGET).a $(TARGET_FILES)
	#$(C_COMPILER) -shared -o $(BUILD_DIR)/lib$(TARGET).so $(TARGET_FILES)

#target: CFLAGS+=-fPIC
#target: $(TARGET_FILES)

%.o: %.c
	@$(C_COMPILER) $(CFLAGS) $(INC_DIRS) -c -o $@ $?
tags:
	rm -f cscope.* tags
	find . -name "*.[hc]" > cscope.files
	find /usr/include/ -name "*.[ch]" -type f >>cscope.files
	find /usr/local/include -name "*.[ch]" -type f >>cscope.files
	find /usr/lib/ -name "*.[ch]" -type f >>cscope.files
	#find /usr/lib/gcc/x86_64-linux-gnu/5.2.1/ -name "*.[ch]" -type f >>cscope.files
	cscope -b -q -k
	ctags -L cscope.files

gotags:
	find . -name "*.go" > go.files
	find $(GOROOT)/src -name "*.go" >>go.files
	find $(GOPATH)/src -name "*.go" >>go.files
	find $(GOROOT)/src -name "*.[hcsS]" >>go.files
	ctags -L go.files
	rm -f go.files

.PHONY: gotags tags
