#include "main.h"

/**
 * print_last_digit -function that prints last digit
 *
 * @i: function parameter
 * Return: Always y
 */
int print_last_digit(int i)
{
	int y;

	y = i % 10;
	if (i < 0)
		y = -y;
	_putchar(y + '0');
	return (y);
}
