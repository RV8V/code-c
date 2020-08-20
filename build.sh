#!/bin/bash

gcc -Wall -E main.c -o main.i
gcc -Wall -S main.i main.s
gcc -Wall -c main.c -o main.o
gcc -Wall main.o -o res.out
