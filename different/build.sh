#!/bin/bash

gcc -Wall -E main.c -o main.i && gcc -E different.c -o different.i && gcc -E example.test.c -o example.test.i && gcc -E limits.c -o limits.i
gcc -Wall -S main.i -o main.s && gcc -S different.i -o different.s && gcc -S example.test.i -o example.test.s && gcc -S limits.i -o limits.s
gcc -Wall -c main.c -o main.o && gcc -c different.c -o different.o && gcc -c example.test.c -o example.test.o && gcc -c limits.c -o limits.o
gcc -Wall main.o different.o example.test.o limits.o -o res.out
