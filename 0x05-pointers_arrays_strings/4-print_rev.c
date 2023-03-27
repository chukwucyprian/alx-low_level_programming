#include "main.h"
/**
 * print_rev -prints strings in reverse order
 * @s:function parameter
 * Return:0
 */

void print_rev(char *s)
{
	int i;
	int count;

	for (i = 0; s[i] != '\0'; i++)
		count++;
	for (i = count; s[i] <= 0; i--)
		_putchar(s[i]);
	_putchar('\n');
}
