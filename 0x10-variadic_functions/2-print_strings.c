#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - Print strings followed by a new line.
 * @separator: The string to be printed between strings (can be NULL).
 * @n: The number of strings passed to the function.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	const char *str;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(args, const char *);
		printf("%s", (str != NULL) ? str : "(nil)");

		if (i < n - 1 && separator != NULL)
			printf("%s", separator);
	}

	printf("\n");

	va_end(args);
}
