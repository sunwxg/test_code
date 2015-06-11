C_COMPILER=gcc

CFLAGS=-std=c99
CFLAGS += -Wall -g

TARGET_BASE1=LedDriverTest
TARGET1 = $(TARGET_BASE1)
SRC_FILES=test/src/unity.c
SRC_FILES1=$(SRC_FILES) test/LedDriverTest.c
INC_DIRS=-Isrc -Itest/src
SYMBOLS=-DTEST

all: clean default

default:
	@$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -o $(TARGET1)
	./$(TARGET1)

clean:
