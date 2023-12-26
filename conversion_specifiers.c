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

/**
* process_unsigned_integer - Process unsigned integer format specifier.
* @num: The unsigned integer value.
* @base: The base for conversion.
*
* Return: Number of characters printed.
*/
int process_unsigned_integer(unsigned int num, int base)
{
	int count;
	int j, i, rem;
	char buffer[32];

	i = 0;
	if (num == 0)
	{
		putchar('0');
		count++;
	}
	else
	{
		while (num != 0)
		{
			rem = num % base;

			buffer[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
			num = num / base;
		}

		for (j = i - 1; j >= 0; j--)

		{
			putchar(buffer[j]);
			count++;
		}
	}

	return (count);
}
