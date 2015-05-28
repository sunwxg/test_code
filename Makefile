CC=gcc
CSFLAGS= -Wall -g
LIBS= -levent
FILES=$(wildcard *.c)
ITEMS=$(basename $(FILES))

all: $(ITEMS)
$(ITEMS):
	$(CC) $(CSFLAGS) -o $@ $@.c $(LIBS)

.PHONY: clean
clean:
	@rm -f $(ITEMS)
	@rm -f *.o
