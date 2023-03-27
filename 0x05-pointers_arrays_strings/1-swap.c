#include "main.h"
/**
 * swap_int -swap values function
 * @a: value a
 * @b: value b
 * Return: 0
 */

void swap_int(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
