#include "main.h"

/**
 * process_string - Process and print a string.
 * @s: The string to be processed.
 *
 * Return: Number of characters printed.
 */
int process_string(char *s)
{
	int count;

	count = 0;
	if (s == NULL)
	{
		printf("(null)");
		count += 6;
	}
	else
	{
		while (*s != '\0')
		{
			putchar(*s);
			s++;
			count++;
		}
	}

	return (count);
}
