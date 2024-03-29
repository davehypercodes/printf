#include "main.h"


/**
 * _printf - prints a format string to stdout
 * @format: format string
 *
 * Return: -1 if fail and num of bytes printed if success
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	/* Check for NULL pointer */
	if (format == NULL)
		return (-1);
	/* loop through characters */
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			/* Return error if format string contains only '%' */
			if (*format == '\0')
				return (-1);
			count += detect_format(*format, args);
		}
		else
		{
			count += _putchar(*format);
		}
		format++;
	}
	return (count);
}


/**
 * _putchar - prints a single char to stdout
 * @c: character to be printed
 *
 * Return: 1 on succes and -1 if fail.
 */

int _putchar(char c)
{
	static char buffer[BUFFER_SIZE];
	static int index = 0;

	if (c == '\0' || index >= BUFFER_SIZE - 1) {
		write(1, buffer, index);
		index = 0;
		memset(buffer, 0, BUFFER_SIZE);
	} else {
		buffer[index++] = c;
	}

	return 1;
}

/**
 * detect_format -  detects what format specifiers are in the format string
 * @specifier: format specifier
 * @args: va_list object, the argument that corresponds to the format spec.
 *
 * Return: num of bytes of the present va_list object
 */
int detect_format(char specifier, va_list args)
{
	int count = 0;

	if (specifier == 'c' || specifier == 's' || specifier == '%')
	{
		count += handle_char_str(specifier, args);
	}
	else if (specifier == 'i' || specifier == 'd')
	{
		count += handle_int(va_arg(args, int));
	}
	else if (specifier == 'b')
	{
		count += handle_binary(va_arg(args, unsigned int));
	}
	else if (specifier == 'u')
	{
		count += handle_unsigned_int(va_arg(args, unsigned int));
	}
	else if (specifier == 'o')
	{
		count += handle_octal(va_arg(args, unsigned int));
	}
	else if (specifier == 'x')
	{
		count += handle_hex(va_arg(args, unsigned int), 0);
	}
	else if (specifier == 'X')
	{
		count += handle_hex(va_arg(args, unsigned int), 1);
	}
	else
	{
		_putchar('%');
		_putchar(specifier);
		count += 2;
	}
	return (count);
}
