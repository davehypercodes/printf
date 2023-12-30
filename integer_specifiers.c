#include "main.h"

int _tobinary(char specifier, va_list args)
{
	int n = va_arg(args, int);
	int i = 0;
	int j;
	int binary[32];

	if (n == 0)
	{
		putchar('0');
		return (1);
	}

	while (n > 0)
	{
		binary[i] = n % 2;
		n /= 2;
		i++;
	}

	for (j = i - 1; j >= 0; j--)
		putchar(binary[j] + '0');

	return (i);
}