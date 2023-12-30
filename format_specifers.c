#include "main.h"

/**
 * handle_char_str - Handles the character and string specifiers in _putchar.
 *
 * @specifier: The format specifier character.
 * @args: The variable argument list.
 *
 * Return: The number of characters printed.
 */
int handle_char_str(char specifier, va_list args)
{
	char c;
	char *s;
	int count = 0;

	switch (specifier)
	{
		case 'c':
		{
			c = va_arg(args, int);
			putchar(c);
			count++;
			break;
		}
		case 's':
		{
			s = va_arg(args, char *);
			count += process_string(s);
			break;
		}
		case '%':
		{
			putchar('%');
			count++;
			break;
		}
	}
	return (count);
}

/**
 * process_string - Processes a string and prints its characters.
 *
 * @s: The string to be processed.
 *
 * Return: The number of characters processed.
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
		putchar(*s);
		s++;
		count++;
	}
	return (count);
}

/**
 * handle_int - Handles the integer specifiers in _printf.
 *
 * @specifier: The format specifier character.
 * @args: The variable argument list.
 *
 * Return: The number of characters printed.
 */
int handle_int(char specifier, va_list args)
{
	int n;
	int count = 0;

	n = va_arg(args, int);
	if (specifier == 'd' || specifier == 'i')
	{
		count += print_number(n);
	}
	return (count);
}

/**
 * print_number - Prints an integer.
 *
 * @n: The integer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_number(int n)
{
	int count = 0;
	long m = n;

	if (m < 0)
	{
		putchar('-');
		count++;
		m = -m;
	}
	if (m / 10)
	{
		count += print_number(m / 10);
	}
	putchar(m % 10 + '0');
	count++;
	return (count);
}
