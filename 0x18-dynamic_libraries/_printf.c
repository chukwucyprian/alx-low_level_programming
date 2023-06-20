#include <stdio.h>
#include <unistd.h>
#include <string.h>

int printf(const char* format, ...) 
{
	const char* output =("9 8 10 24 75 -9\nCongratulations, you win the Jackpot!\n");
	
	write(1, output, strlen(output));
}
