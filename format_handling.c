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

/**
 * handle_int - handles the printing of integers
 * @num: integer to be printed
 *
 * Return: The num of digits printed to stdout
 */
int handle_int(int num)
{
	long int n = num;
	int count = 0;

	if (n < 0)
	{
		count += _putchar('-');
		n = -n;
	}
	if (n / 10)
	{
		count += handle_int(n / 10);
	}
	count += _putchar((n % 10) + '0');
	return (count);
}

/**
 * handle_binary - converts an unsigned int to binary and prints it
 * @num: unsigned int to be converted
 *
 * Return: num of bytes printed
 */
int handle_binary(unsigned int num)
{
	int count = 0;
	unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);
	int start_printing = 0;

	while (mask > 0)
	{
		if (num & mask)
		{
			start_printing = 1;
			count += _putchar('1');
		}
		else if (start_printing)
		{
			count += _putchar('0');
		}
		mask >>= 1;
	}
	return (count);
}
