#include "main.h"

/**
 * handle_char_str - uses the right format spec
 * to correctly print out the argument
 * @specifier: format specifier
 * @args: arguments
 *
 * Return: num of bytes printed
 */
int handle_char_str(char specifier, va_list args)
{
	int count = 0;

	switch (specifier)
	{
		case 'c':
			count += _putchar(va_arg(args, int));
			break;
		case 's':
			count += process_string(va_arg(args, char *));
			break;
		case '%':
			count += _putchar('%');
			break;
	}
	return (count);
}

/**
 * process_string - processes the printing of a string to stdout
 * @s: string to be printed
 *
 * Return: num of bytes printed
 */
int process_string(char *s)
{
	int count = 0;

	if (s == NULL)
	{
		s = "(null)";
	}

	while (*s != '\0')
	{
		count += _putchar(*s);
		s++;
	}
	return (count);
}
