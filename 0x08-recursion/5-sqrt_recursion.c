#include "main.h"
#include <stdio.h>

int _sqrt(int n, int i);

/**
 * _sqrt_recursion - Return the natural square root of a number
 * @n: Number to calculate the natural square root
 *
 * Return: The natural square root
 */
int _sqrt_recursion(int n)
{
	return (_sqrt(n, 1));
}

/**
 * _sqrt - Calculates natural square root
 * @n: Number to calculate the square root
 * @i: Iterate number
 *
 * Return:
 * The natural square root
 */
int _sqrt(int n, int i)
{
	int sqrt = i * i;

	if (sqrt > n)
		return (-1);
	if (sqrt == n)
		return (1);
	return (_sqrt(n, i + 1));
}
