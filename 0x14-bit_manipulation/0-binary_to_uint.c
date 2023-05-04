#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - it converts a binary number to unsigned int
 * @b: The string containing the binary number
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int result = 0;

	if (b == NULL)
		return (0);

	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] == '0' || b[i] == '1')
	{
		result = result * 2 + (b[i] - '0');
	}
		else
		{
			return (0);
		}
	}
	return (result);
}
