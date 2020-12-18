#!/bin/bash

gcc -Wall -E lesson1.c -o main.i
gcc -Wall -S main.i main.s
gcc -Wall -c lesson1.c -o main.o
gcc -Wall main.o -o res.out
