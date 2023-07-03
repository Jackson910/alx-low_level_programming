#include "main.h"

/**
 * _memset - Entry point
 * @s: The memory pointed to
 * @n: The number of bytes filled
 * @b: The constant byte
 * Return: Always 0 (Success)
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}
