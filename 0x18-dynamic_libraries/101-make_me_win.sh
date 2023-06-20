#!/bin/bash
gcc -Wall -Wextra -Werror -pedantic -c -fPIC _printf.c
gcc -shared -o _printf.so _printf.o
export LD_PRELAOD=$PWD/_printf.so
