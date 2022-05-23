#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * print_unsigned - prints unsigned int
 * @u: unsigned int to print
 * @f: flags struct
 * Return: num of printed digits
 */

int print_unsigned(va_list u, flags_t *f)
{
	int counter = 0;
	char *result;
	unsigned int n;

	if (f->l == 1)
		n = (unsigned long)va_arg(u, unsigned long);
	else if (f->h == 1)
		n = (unsigned short)va_arg(u, unsigned int);
	else
		n = (unsigned int)va_arg(u, unsigned int);
	result = convert(n, 10, 0);
	_puts(result);
	counter += _strlen(result);
	return (counter);
}

/**
 * print_hex - ascii char values in lower case hex
 * @x: char to print
 * @f: flag struct
 * Return: num of printed chars
 */

int print_hex(va_list x, flags_t *f)
{
	char *res;
	int counter = 0;
	unsigned int l = f->l, h = f->h, hash = f->hash;

	unsigned int n;

	if (l == 1)
		n = (unsigned long)va_arg(x, unsigned long);
	else if (h == 1)
		n = (unsigned short)va_arg(x, unsigned int);
	else
		n = (unsigned int)va_arg(x, unsigned int);
	res = convert(n, 16, 1);
	if (hash == 1 && n)
		_puts("0x");
	_puts(res);
	counter += _strlen(res);
	return (counter);
}

/**
 * print_octal - prints unsigned int in octal notation
 * @o: number to print
 * @f: flag struct
 * Return: number of printed digits
 */

int print_octal(va_list o, flags_t *f)
{
	unsigned int n;
	int counter = 0;
	unsigned int l = f->l, h = f->h;
	char *res;

	if (l == 1)
		n = (unsigned long)va_arg(o, unsigned long);
	else if (h == 1)
		n = (unsigned short)va_arg(o, unsigned int);
	else
		n = (unsigned int)va_arg(o, unsigned int);
	res = convert(n, 8, 1);
	_puts(res);
	counter += _strlen(res);
	return (counter);
}

/**
 * print_HEX - prints ascii char value in uppercase hex
 * @X: char to print
 * @f: flag struct
 * Return: num of printed chars
 */

int print_HEX(va_list X, flags_t *f)
{
	int counter = 0;
	unsigned int l = f->l, h = f->h, hash = f->hash, n;
	char *res;

	if (l == 1)
		n = (unsigned long)va_arg(X, unsigned long);
	else if (h == 1)
		n = (unsigned short)va_arg(X, unsigned int);
	else
		n = (unsigned int)va_arg(X, unsigned int);

	res = convert(n, 16, 0);
	if (hash == 1 && n)
		_puts("0X");
	_puts(res);
	counter += _strlen(res);
	return (counter);
}

/**
 * print_reverse - prints reversed string
 * @r: string to be reversed
 * @f: flag struct
 * Return: num of printed chars
 */

int print_reverse(va_list r, flags_t *f)
{
	char *strrev = va_arg(r, char *);
	int len, sum = 0;

	(void)f;
	if (strrev)
	{
		for (len = 0; *strrev; strrev++)
			len++;
		strrev--;
		for (; len > 0; len--, strrev--)
			sum += _putchar(*strrev);
	}
	return (sum);
}
