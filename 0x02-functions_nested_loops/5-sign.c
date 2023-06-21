#include "main.h"

/**
 * print_sign - Prints the sign of a number
 * @n: The number to be checked
 *
 * Return: 1 for positive
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar(43); /* ASCII code for '+' */
		return (1);
	}
	else if (n < 0)
	{
		_putchar(45); /* ASCII code for '-' */
		return (-1);
	}
	else
	{
		_putchar(48); /* ASCII code for '0' */
		return (0);
	}
}

