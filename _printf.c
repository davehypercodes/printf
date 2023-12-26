#include "main.h"

/**
 * _printf - Custom printf function.
 * @format: Format string.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	int count;
	va_list args;

	va_start(args, format);

	if (format == NULL)
	{
		return (-1);
	}
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
				return (-1);
			}
			if (*format == '%')
			{
				putchar('%');
				count++;
			}
			else
			{
				count += process_format_specifier(*format, args);
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);

	return (count);
}

/**
 * process_format_specifier - Process and print the format specifier.
 * @format_specifier: The format specifier character.
 * @args: The va_list of arguments.
 *
 * Return: Number of characters printed.
 */
int process_format_specifier(char format_specifier, va_list args)
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
 * process_string - Process and print a string.
 * @s: The string to be processed.
 *
 * Return: Number of characters printed.
 */
int process_string(char *s)
{
	int count = 0;

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
