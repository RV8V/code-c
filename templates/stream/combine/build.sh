#!/bin/bash

gcc -Wall -E main.c -o main.i && gcc -E test.c -o test.i
gcc -Wall -S main.i -o main.s && gcc -S test.i -o test.s
gcc -Wall -c main.c -o main.o && gcc -c test.c -o test.o
gcc -Wall main.o test.o -o res.out
