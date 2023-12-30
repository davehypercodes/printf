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
			if (_detect_char_format(*format))
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


/**
 * _detect_char_format - Detects if a character is a valid format specifier.
 *
 * @format: The character to check.
 *
 * Return: 1 if the character is a valid format specifier, 0 otherwise.
 */
int _detect_char_format(char format)
{
	int i;
	char *format_list = "cs%";

	for (i = 0; format_list[i] != '\0'; i++)
	{
		if (format == format_list[i])
			return (1);
	}
	return (0);
}