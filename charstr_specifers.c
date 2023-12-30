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
	char *s;
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
			count += process_string(s);
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

/**
 * process_string - Processes a string and prints its characters.
 *
 * @s: The string to be processed.
 *
 * Return: The number of characters processed.
 */
int process_string(char *s)
{
	int count = 0;

	if (s == NULL)
	{
		s = "(null)";
	}

	while (*s != '\0')
	{
		putchar(*s);
		s++;
		count++;
	}
	return (count);
}
