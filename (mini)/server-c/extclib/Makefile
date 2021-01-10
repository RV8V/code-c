CC=gcc
LN=ld
CFLAGS=-Wall -std=c99

HEADERS=http.h net.h io.h hashtab.h tree.h type.h
SOURCES=http.c net.c io.c hashtab.c tree.c type.c
OBJECTS=http.o net.o io.o hashtab.o tree.o type.o

.PHONY: default
default: build link

build: $(HEADERS) $(SOURCES)
	$(CC) $(CFLAGS) -c $(SOURCES)
link: $(OBJECTS)
	$(LN) -r $(OBJECTS) -o extclib.o
clean:
	rm -f *.o *.i *.s
