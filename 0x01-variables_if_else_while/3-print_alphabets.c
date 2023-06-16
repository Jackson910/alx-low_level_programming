#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - prints the alphabet.
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	char i;

	for (i = 'a'; i < 'z'; i++)
		putchar(i);
	for (i = 'A'; i < 'Z'; i++)
		putchar(i);
	putchar('\n');
	return (0);
}
