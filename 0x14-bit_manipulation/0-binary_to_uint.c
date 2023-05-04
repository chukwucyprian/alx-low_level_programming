#include "main.h"

/**
 * binary_to_uint - it converts a binary number to unsigned int
 * @b: The string containing the binary number
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
	int j;
	unsigned int deci_val = 0;

	if (!b)
		return (0);

	for (j = 0; b[j]; j++)
	{
		if (b[j] < '0' || b[j] > '1')
			return (0);
		deci_val = 2 * deci_val + (b[j] - '0');
	}

	return (deci_val);
}
