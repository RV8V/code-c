CC=gcc
LN=ld
CFLAGS=-Wall -std=c99

HEADERS=routes.h
SOURCES=routes.c
OBJECTS=routes.o

.PHONY: default
default: build link

build: $(HEADERS) $(SOURCES)
	$(CC) $(CFLAGS) -c $(SOURCES)
link: $(OBJECTS)
	$(LN) -r $(OBJECTS) -o another.o
clean:
	rm -f *.o *.i *.s
