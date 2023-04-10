#include "main.h"

/**
 * _abs -check for absolute values
 *
 * @a: parameter to be checked
 * Return:Always a
 */

int _abs(int a)
{
	if (a < 0)
		a = -(a);
	else if (a >= 0)
		a = a;
	return (a);
}
