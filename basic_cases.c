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
	int i = 0;

	(void)f;
	if (str == NULL)
		str = "(null)";
	while (str[i])
		_putchar(str[i++]);
	return (i);
}

/**
 * print_integer - prints base 10 integers
 * @i: integer to print
 * @f: flag
 * Return: number of printed digits
 */

int print_integer(va_list i, flags_t *f)
{
	long n;
	int counter;

	if (f->l == 1)
		n = va_arg(i, long);
	else if (f->h == 1)
		n = (short int)va_arg(i, int);
	else
		n = (int)va_arg(i, int);

	counter = count_digit(n);
	if (f->plus == 1)
		_putchar('+');
	else if (f->minus == 1)
		_putchar('-');
	putnum(n);
	return (counter);
}

/**
 * count_digit - returns the number of digits in an integer
 * for _printf
 * @i: integer to evaluate
 * Return: number of digits
 */
int count_digit(int i)
{
	unsigned int d = 0;
	unsigned int u;

	if (i < 0)
		u = i * -1;
	else
		u = i;
	while (u != 0)
	{
		u /= 10;
		d++;
	}
	return (d);
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
