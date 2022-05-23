#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * print_character - prints character
 * @c: char to print
 * @f: flag
 * Description: print character
 * Return: 1
 */

int print_character(va_list c, flags_t *f)
{
	char charac = (char)va_arg(c, int);

	(void)f;
	_putchar(charac);
	return (1);
}

/**
 * print_string - prints a string
 * @s: string to print
 * @f: flag
 * Return: 1
 */

int print_string(va_list s, flags_t *f)
{
	char *str = va_arg(s, char *);

	(void)f;
	if (!str)
		str = "(null)";
	return (_puts(str));
}

/**
 * print_integer - prints base 10 integers
 * @i: integer to print
 * @f: flag
 * Return: number of printed digits
 */

int print_integer(va_list i, flags_t *f)
{
	unsigned int a[10];
	unsigned int j = 1, m = 1000000000, n, sum = 0, counter = 0;
	unsigned int l = f->l, h = f->h, plus = f->plus,
		     minus = f->minus;
	unsigned int res = 0;

	n = va_arg(i, unsigned int);
	a[0] = n / m;

	for (; j < 10; j++)
	{
		m /= 10;
		a[j] = (n / m) % 10;
	}

	for (j = 0; j < 10; j++)
	{
		sum += a[j];
		if (sum != 0 || j == 9)
		{
			res = 10 * res + a[j];
			counter++;
		}
	}
	if (plus == 1)
		_putchar('+');
	else if (minus == 1)
		_putchar('-');
	use_mod(&res, &l, &h);
	return (counter);
}

/**
 * print_d - prints a base 10 decimal
 * @i: base 10 integer to print
 * @f: flag
 * Return: number of printed digits
 */

int print_d(va_list i, flags_t *f)
{
	unsigned int a[10];
	unsigned int j = 1, m = 1000000000, n, sum = 0, counter = 0;
	unsigned int l = f->l, h = f->h, plus = f->plus,
		minus = f->minus;
	unsigned int res = 0;

	n = va_arg(i, unsigned int);
	a[0] = n / m;

	for (; j < 10; j++)
	{
		m /= 10;
		a[j] = (n / m) % 10;
	}

	for (j = 0; j < 10; j++)
	{
		sum += a[j];
		if (sum != 0 || j == 9)
		{
			res = 10 * res + a[j];
			counter++;
		}
	}
	if (plus == 1)
		_putchar('+');
	else if (minus == 1)
		_putchar('-');
	use_mod(&res, &l, &h);
	return (counter);
}

/**
 * print_binary - prints unsigned int in binary
 * @b: unsigned int to print
 * @f: flag
 * Return: num of printed digits
 */

int print_binary(va_list b, flags_t *f)
{
	unsigned int n, m = 2147483648, j = 1, sum = 0;
	unsigned int a[32];
	int counter = 0;

	(void)f;
	n = va_arg(b, unsigned int);
	a[0] = n / m;

	for (; j < 32; j++)
	{
		m /= 2;
		a[j] = (n / m) % 2;
	}
	for (j = 0; j < 32; j++)
	{
		sum += a[j];
		if (sum || j == 31)
		{
			_putchar('0' + a[j]);
			counter++;
		}
	}
	return (counter);
}
