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
	int string_length = 0;
	int i;
	char *string_to_print;
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
			if (*format == '\0')
			{
				break;
			}
			switch (*format) {
				case '%':{
						 write(1, format, 1);
						 length++;
						 break;
					 }
				case 'c':{
						 i = va_arg(arguments, int);
						 write(1, &i, 1);
						 length++;
						 break;
					 }
				case 's':{
						 string_to_print = va_arg(arguments, char*);
						 while (string_to_print[string_length] != '\0')
						 {
							 string_length++;
					 }
						 write(1, string_to_print, string_length);
						 length += string_length;
						 break;
					 }
			}
		}
		format++;
	}
	va_end(arguments);
	return (length);
}
