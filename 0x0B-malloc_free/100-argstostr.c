#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * argstostr - Convert the params passed to the program to string
 * @ac: The argument count
 * @av: The argument vector
 *
 * Return: Nothing
 */
char *argstostr(int ac, char **av)
{
	int ch = 0, i = 0, j = 0, k = 0;
	char *s;

	if (ac == 0 || av == NULL)
		return (NULL);

	while (i < ac)
	{
		while (av[i][j])
		{
			ch++;
			j++;
		}
		j = 0;
		i++;
	}
	s = malloc((sizeof(char) * ch) + ac + 1 + ac);

	i = 0;
	k = 0;
	while (i < ac)
	{
		j = 0;

		while (av[i][j])
		{
			s[k] = av[i][j];
			k++;
			j++;
		}
		s[k] = '\n';

		k++;
		j++;
	}
	s[k] = '\0';
	return (s);
}
