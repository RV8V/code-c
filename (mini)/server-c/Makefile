CC=gcc
CFLAGS=-Wall -std=c99

FILES=main.c extclib/extclib.o routes/another.o

.PHONY: default build run
default: build run

routes.o:
	$(CC) $(CFLAGS)

build: $(FILES)
	$(CC) $(CFLAGS) $(FILES) -o main

run: main
	./main

delete:
	rm -rf main
