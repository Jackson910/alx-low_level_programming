#include <stdio.h>

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to convert and print.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1UL << ((sizeof(unsigned long int) * 8) - 1);
	int flag = 0;

	if (n == 0)
	{
		putchar('0');
		return;
	}

	while (mask)
	{
		if (n & mask)
		{
			putchar('1');
			flag = 1;
		}
		else if (flag)
			putchar('0');

		mask >>= 1;
	}
}
