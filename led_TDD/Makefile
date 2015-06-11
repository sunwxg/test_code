C_COMPILER=gcc

CFLAGS=-std=c99
CFLAGS += -Wall -g

TARGET_BASE1=LedDriverTest
TARGET1 = $(TARGET_BASE1)
SRC_FILES1=unity/LedDriver/LedDriverTest.c
INC_DIRS=-Isrc -Iunity/src
SYMBOLS=-DTEST

all: clean default

default:
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -o $(TARGET1)
	./$(TARGET1)

clean:
	$(CLEANUP)
