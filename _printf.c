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
	{
		return (-1);
	}

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
				return (-1);
			}
			count += handle_char_str(*format, args);
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
