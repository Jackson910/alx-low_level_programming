#include <stdio.h>

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A pointer to a string containing a binary number.
 *
 * Return: The converted number
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int bit_position = 0;

	if (b == NULL)
		return (0);
	while (b[bit_position] != '\0')
	{
		char current_char = b[bit_position];

		if (current_char != '0' && current_char != '1')
			return (0);

		result = (result << 1) + (current_char - '0');

		bit_position++;
	}

	return (result);
}
