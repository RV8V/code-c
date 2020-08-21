CC = gcc

test.out: main.o different.o example.test.o limits.o
	$(CC) -Wall main.o different.o example.test.o limits.o -o test.test

main.o: main.c
	$(CC) -o0 -g3 -Wall -c main.c -o main.o
	$(CC) -masm=intel -g3 -Wall -c main.c -S

different.o: different.c
	$(CC) -o0 -g3 -Wall -c different.c -o different.o
	$(CC) -masm=intel -g3 -Wall -c different.c -S

example.test.o: example.test.c
	$(CC) -o0 -g3 -Wall -c example.test.c -o example.test.o
	$(CC) -masm=intel -g3 -Wall -c example.test.c -S

limits.o: limits.c
	$(CC) -o0 -g3 -Wall -c limits.c -o limits.o
	$(CC) -masm=intel -g3 -Wall -c limits.c -S
