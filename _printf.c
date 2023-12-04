#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: the concerning format
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int length = 0;
	int i;
	va_list arguments;
	va_start(arguments, format);

	if (format == NULL)
	{
		return (-1);
	}

	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			length++;
		}
		else
		{
			format++;
		}

		if (format == '\0')
		{
			break;
		}

		switch (format)
		{
			case 'c':{
					 i = va_arg(arguments, int);
				 }
				 write(1, i, strlen(i));
			case 's':{

					 strlen(
				 }
			case '%':{

				 }

