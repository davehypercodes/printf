#include "main.h"

/**
 * _printf - Custom printf function.
 *
 * @format: Format string.
 * @...: Variable arguments.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	if (format == NULL)
		return (-1);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
				return (-1);
			}
			count += _detect_format(*format, args);
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
 * _detect_format - Detects if a character is a valid format specifier.
 *
 * @format: The character to check.
 * @args: The va_list to check.
 *
 * Return: 1 if the character is a valid format specifier, 0 otherwise.
 */
int _detect_format(char format, va_list args)
{
	int count = 0;

	if (format == 's' || format == 'c' || format == '%')
		count += handle_char_str(format, args);
	else if (format == 'd' || format == 'i')
		count += handle_int(format, args);
	else
	{
		putchar('%');
		putchar(format);
		count += 2;
	}
	return (count);
}
