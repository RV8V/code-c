CC = gcc

define build-obj-different
  $(CC) -o0 -g3 -Wall -c different.c -o different.o
  $(CC) -masm=intel -g3 -Wall -c different.c -S
endef

test.out: main.o different.o example.test.o limits.o
	$(CC) -Wall main.o different.o example.test.o limits.o -o test.test

main.o: main.c main.h different.h example.test.h limits.h
	$(CC) -o0 -g3 -Wall -c main.c -o main.o
	$(CC) -masm=intel -g3 -Wall -c main.c -S

different.o: different.c  different.h
	$(call build-obj-different)

example.test.o: example.test.c example.test.h
	$(CC) -o0 -g3 -Wall -c example.test.c -o example.test.o
	$(CC) -masm=intel -g3 -Wall -c example.test.c -S

limits.o: limits.c limits.h
	$(CC) -o0 -g3 -Wall -c limits.c -o limits.o
	$(CC) -masm=intel -g3 -Wall -c limits.c -S

clean:
	rm -rf *.s *.o *.test
