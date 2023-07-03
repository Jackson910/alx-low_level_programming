#include "main.h"

/**
 * _strspn - Entry point
 *@s: Input
 *@accept: Input
 *Return: Always 0 (success)
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, n, value;

	value = 0;

	for (i = 0; s[i] != '\0'; i++)
	{

		for  (n = 0; accept[n] != '\0'; n++)
		{
			if (accept[n] == s[i])
			{
				value++;
				break;
			}
		}
	}
	return (value);
}
