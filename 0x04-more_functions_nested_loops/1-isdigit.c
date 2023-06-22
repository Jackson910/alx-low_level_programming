#include "main.h"

/**
 * _isdigit -  checks for a digit (0 through 9).
 * @c: The digit to  be computed
 * Return:  1 for digit or 0 for any else.
 */
int _isdigit(int  c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}
