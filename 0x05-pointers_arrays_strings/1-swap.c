#include <stdio.h>

/**
 * swap_int - Swaps the values of two integers.
 * @a: The first interger to be swapped.
 * @b: The second integer to be swapped
 *
 * Return: nothing
 */
void swap_int(int *a, int *b)
	/* the function that swaps the values of two intergers. */
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

