#!/bin/bash
gcc -shared -fPIC _printf.c -o _printf.so
export LD_PRELAOD=$PWD/_printf.so
