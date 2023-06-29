#include "main.h"

/**
 * _putchar - Prints a character to stdout
 * @c: The character to be printed
 *
 * Return: On success, returns the character.
 * On error, returns -1.
 */
int _putchar(char c)
{
	/* Implementation of _putchar function goes here */
	/* Example: return putchar(c); */
}

/**
 * print_number - Prints an integer
 * @n: The integer to be printed
 *
 * Description: This function prints an integer using only
 * the _putchar function. It does not use arrays, pointers,
 * long, or hard-coded special values.
 */
void print_number(int n)
{
	int reversed = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	while (n > 0)
	{
		reversed = reversed * 10 + (n % 10);
		n /= 10;
	}

	while (reversed > 0)
	{
		int digit = reversed % 10;

		_putchar('0' + digit);
		reversed /= 10;
	}
}

