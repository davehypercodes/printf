#include "main.h"

/**
* process_character - Process and print the format specifier.
* @format_specifier: The format specifier character.
* @args: The va_list of arguments.
*
* Return: Number of characters printed.
*/
int process_character(char format_specifier, va_list args)
{
	int count;

	char c;

	char *s;

	count = 0;
	switch (format_specifier)
	{
	case 'c':
		c = (char)va_arg(args, int);
		putchar(c);
		count++;
		break;
	case 's':
		s = va_arg(args, char *);
		count += process_string(s);
		break;
	default:
		putchar('%');
		putchar(format_specifier);
		count += 2;
		break;
	}

	return (count);
}

/**
* process_integer - Process and print the integer format specifier.
* @format_specifier: The format specifier character.
* @args: The va_list of arguments.
*
* Return: Number of characters printed.
*/
int process_integer(char format_specifier, va_list args)
{
	int count;
	unsigned int num;

	count = 0;
	switch (format_specifier)
	{
	case 'u':
		num = va_arg(args, unsigned int);

		count += process_unsigned_integer(num, 10);
		break;
	case 'o':
		num = va_arg(args, unsigned int);

		count += process_unsigned_integer(num, 8);
		break;
	case 'x':
		num = va_arg(args, unsigned int);

		count += process_unsigned_integer(num, 16);
		break;
	case 'X':
		num = va_arg(args, unsigned int);

		count += process_unsigned_integer(num, 16);
		break;
	default:
		putchar('%');
		putchar(format_specifier);
		count += 2;
		break;
	}

	return (count);
}

