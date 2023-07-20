#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - Print anything based on the format specifier.
 * @format: A list of types of arguments passed to the function.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	const char *ptr = format;
	char c;
	int i;
	float f;
	char *s;

	va_start(args, format);

	while (format && *ptr)
	{
		c = *ptr;

		if (c == 'c')
		{
			printf("%c", va_arg(args, int));
		}
		else if (c == 'i')
		{
			i = va_arg(args, int);
			printf("%d", i);
		}
		else if (c == 'f')
		{
			f = va_arg(args, double);
			printf("%f", f);
		}
		else if (c == 's')
		{
			s = va_arg(args, char *);

			if (s == NULL)
				printf("(nil)");
			else
				printf("%s", s);
		}

		ptr++;
		if (*ptr && (c == 'c' || c == 'i' || c == 'f' || c == 's'))
			printf(", ");
	}

	printf("\n");

	va_end(args);
}
