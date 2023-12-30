#include "main.h"

/**
 * handle_char_str - Handles the character and string specifiers in _putchar.
 *
 * @specifier: The format specifier character.
 * @args: The variable argument list.
 *
 * Return: The number of characters printed.
 */
int handle_char_str(char specifier, va_list args)
{
	char c;
	const char *s;
	int count = 0;

	switch (specifier)
	{
		case 'c':
		{
			c = va_arg(args, int);
			putchar(c);
			count++;
			break;
		}
		case 's':
		{
			s = va_arg(args, char *);
			while (*s != '\0')
			{
				putchar(*s);
				s++;
				count++;
			}
			break;
		}
		case '%':
		{
			putchar('%');
			count++;
			break;
		}
		default:
		{
			putchar('%');
			putchar(specifier);
			count += 2;
			break;
		}
	}
	return (count);
}
