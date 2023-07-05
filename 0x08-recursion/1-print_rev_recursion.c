#include "main.h"
#include <stdio.h>

/**
 * _print_rev_recursion - Prints a string in reverse.
 * @s: The string to be printed in reverse.
 *
 * This function takes a string argument
 * It uses the concept of recursion to achieve the reverse printing.
 */
void _print_rev_recursion(char *s)
{
	if (*s == '\0')
	{
		return;
	}
	s++;
	_print_rev_recursion(s);
	s--;
	_putchar(*s);
}

