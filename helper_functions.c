#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * loop_through - process of iterating through
 * variable arguments
 * @in: data to be printed
 * @count: counter
 * @i: iterator
 * Return: Nil
 */

void loop_through(const char *in, unsigned int *count, unsigned int *i)
{
	_putchar(*in);
	(*count)++;
	(*i)++;
}

/**
 * handle_percentage - handles percentage input
 * @count: counter
 * @i: iterator
 */

void handle_percentage(unsigned int *count, unsigned int *i)
{
	_putchar('%');
	(*count)++;
	(*i) += 2;
}

/**
 * get_flag - finds the modifier func
 * @s: search input
 * @f: the flags construct
 *
 * Return: if modifier was valid
 */
int get_flag(char s, flags_t *f)
{
	int i = 0;

	switch (s)
	{
	case 'h':
		f->h = 1;
		i = 1;
		break;
	case 'l':
		f->l = 1;
		i = 1;
		break;
	case '+':
		f->plus = 1;
		i = 1;
		break;
	case '-':
		f->minus = 1;
		i = 0;
		break;
	case '#':
		f->hash = 1;
		i = 0;
		break;
	case ' ':
		f->space = 1;
		i = 0;
		break;
	}
	return (i);
}

/**
 * use_mod - prints modifier result
 * @l: flag variable
 * @h: flag variable
 * @res: result to print
 */
void use_mod(int *res, int *l, int *h)
{
	int result = *res;
	long longres = *res;
	short shortres = *res;

	if (*l == 1)
		putnum(longres);
	else if (*h == 1)
		putnum(shortres);
	else
		putnum(result);
}

/**
 * convert - converts number and base into string
 * @num: input number
 * @base: input base
 * @lowercase: flag if hexa values need to be lowercase
 * Return: result string
 */
char *convert(unsigned long int num, int base, int lowercase)
{
	static char *rep;
	static char buffer[50];
	char *ptr;

	rep = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}

