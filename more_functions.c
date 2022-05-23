#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_STRING - swaps out special characters
 * in a string for their hex ascii values
 * @S: string to be parsed
 * @f: flags struct
 * Return: number of printed characters
 */

int print_STRING(va_list S, flags_t *f)
{
	char *hex;
	int counter = 0;
	char *str = va_arg(S, char *);

	(void)f;
	if ((int)(!str))
	{
		puts("(null)");
		counter += _strlen("(null)");
		return (counter);
	}
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			counter += _putchar('\\');
			counter += _putchar('x');
			hex = convert(*str, 16, 1);
			if (!hex[1])
				counter += _putchar('0');
			_puts(hex);
			counter += _strlen(hex);
		}
		else
		{
			_putchar(*str);
			counter += _strlen(str);
		}
	}
	
	return (counter);
}

/**
 * print_pointer - prints an address
 * @p: address to print
 * @f: flags struct
 * Return: number of printed characters
 */

int print_pointer(va_list p, flags_t *f)
{
	int counter = 0;
	unsigned int a[16];
	unsigned int i = 0, sum = 0;
	unsigned long n, m = 1152921504606846976;
	char *str = "(nil)";

	(void)f;
	n = va_arg(p, unsigned long);
	if (n == 0)
	{
		for (; str[i]; i++)
		{
			_putchar(str[i]);
			counter++;
		}
		return (counter);
	}
	_putchar('0');
	_putchar('x');
	counter = 2;

	a[0] = n / m;
	for (i = 1; i < 16; i++)
	{
		m /= 16;
		a[i] = (n / m) % 16;
	}
	for (i = 0; i < 16; i++)
	{
		sum += a[i];
		if (sum || i == 15)
		{
			if (a[i] < 10)
				_putchar('0' + a[i]);
			else
				_putchar('0' + ('a' - ':') + a[i]);
			counter++;
		}
	}
	return (counter);
}

/**
 * print_ROT - prints a string in rot format
 * @R: string to be formatted
 * @f: flags struct
 * Return: number of printed characters
 */

int print_ROT(va_list R, flags_t *f)
{
	char *str;
	unsigned int i = 0, j = 0;
	int counter = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	(void)f;
	str = va_arg(R, char *);
	if (str == NULL)
		str = "(ahyy)";
	for (; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				_putchar(out[j]);
				counter++;
				break;
			}
		}
		if (!in[j])
		{
			_putchar(str[i]);
			counter++;
		}
	}
	return (counter);
}
