#include "main.h"

int _printf(const char *format, ...)
{
	int count;
	char c;
	char *s;

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
				return (0);
			}
			if (*format == '%')
			{
				putchar('%');
				count++;
			}
			else
			{
				switch (*format)
				{
				case 'c':
					c = (char)va_arg(args, int);
					putchar(c);
					count++;
					break;
				case 's':
					s = va_arg(args, char *);
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
					break;
				default:
					putchar('%');
					putchar(*format);
					count += 2;
					break;
				}
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

	return count;
}
