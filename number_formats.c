/**
 * handle_int - handles the printing of integers
 * @num: integer to be printed
 *
 * Return: The num of digits printed to stdout
 */
int handle_int(int num)
{
	long int n = num;
	int count = 0;

	if (n < 0)
	{
		count += _putchar('-');
		n = -n;
	}
	if (n / 10)
	{
		count += handle_int(n / 10);
	}
	count += _putchar((n % 10) + '0');
	return (count);
}

/**
 * handle_binary - converts an unsigned int to binary and prints it
 * @num: unsigned int to be converted
 *
 * Return: num of bytes printed
 */
int handle_binary(unsigned int num)
{
	int count = 0;
	unsigned int mask;
	int start_printing = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	mask = 1 << (sizeof(unsigned int) * 8 - 1);

	while (mask > 0)
	{
		if (num & mask)
		{
			start_printing = 1;
			count += _putchar('1');
		}
		else if (start_printing)
		{
			count += _putchar('0');
		}
		mask >>= 1;
	}
	return (count);
}

/**
 * handle_unsigned_int - handles the printing of unsigned integers
 * @num: integer to be printed
 * 
 * Return: The num of digits printed to stdout
 */
int handle_unsigned_int(unsigned int num)
{
	int count = 0;

	if (num < 10)
	{
		count += _putchar(num + '0');
	}
	else
	{
		count += handle_unsigned_int(num / 10);
		count += _putchar(num % 10 + '0');
	}
	return (count);
}

/**
 * handle_octal - handles the printing of octal numbers
 * @num: octal number to be printed
 * 
 * Return: num of bytes printed
*/
int handle_octal(unsigned int num)
{
	int count = 0;
	int octal[10];
	int i = 0;

	if (num == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		while (num > 0)
		{
			octal[i] = num % 8;
			num = num / 8;
			i++;
		}
		while (i--)
		{
			_putchar(octal[i] + '0');
			count++;
		}
	}
	return (count);
}

/**
 * handle_hex - handles the 'x' and 'X' format specifiers for hexadecimal numbers
 * @num: the number to be printed
 * @uppercase: flag indicating whether to print in uppercase or lowercase
 *
 * Return: number of bytes printed
 */
int handle_hex(unsigned int num, int uppercase)
{
	char hex[100];
	int i = 0, count = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num != 0)
	{
		int remainder = num % 16;

		if (remainder < 10)
			hex[i++] = remainder + '0';
		else
			hex[i++] = (uppercase ? remainder + 'A' - 10 : remainder + 'a' - 10);

		num /= 16;
	}

	for (i = i - 1; i >= 0; i--)
	{
		_putchar(hex[i]);
		count++;
	}

	return (count);
}
