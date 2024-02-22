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
			format++;
		}
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
	return (write(1, &c, 1));
}

/**
 * detect_format -  detects what format specifiers are in the format string
 * @specifier: format specifier
 * arg: va_list object, the argument that corresponds to the format spec.
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
	else
	{
		_putchar('%');
		_putchar(specifier);
		count += 2;
	}
	return (count);
}
