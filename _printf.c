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
			else if (*format == 'c' || *format == 's')
			{
				count += process_character(*format, args);
			}
			else if (*format == 'u' || *format == 'o' || *format == 'x' || *format == 'X')
			{
				count += process_integer(*format, args);
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
