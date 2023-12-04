#include "main.h"

/**
 *
 *
 *
 */
int _printf(const char *format, ...)
{
	int length = 0;
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
		}
		else
		{
			format++;
		}
		switch (format)
		{
			case 'c':{

				 }
			case 's':{

				 }
			case '%':{

				 }

