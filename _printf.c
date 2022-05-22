#include "main.h"

/**
 * check_format - checks for a valid format specifier
 * @fmt: possible valid format specifier
 * Return: pointer to valid function or NULL
 */

int (*check_format(const char *fmt))(va_list ap, flags_t *flags)
{
	int i = 0;
	print_t p[] = {
		{"c", print_character},
		{"s", print_string},
		{"i", print_integer},
		{"d", print_d},
		{"b", print_binary},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"o", print_octal},
		{"S", print_STRING},
		{"p", print_pointer},
		{"r", print_reverse},
		{"R", print_ROT},
		{NULL, NULL}
	};

	while (p[i].t)
	{
		if (*fmt == p[i].t[0])
		{
			return (p[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * check_flag - deals with flag characters
 * @fmt: argument list
 * @i: i
 * @*f: format identifier
 */

void check_flag(const char *fmt, unsigned int *i)
{
	if (fmt[*i + 1] == ' ')
	{
		*i += 1;
		check_flag(fmt, &*i);
	}
}

/**
 * init_flags - clears struct fields and reset buf
 * @flag: the flags struct
 * @ap: argument pointer
 *
 * Return: void
 */
void init_flags(flags_t *flag, va_list *ap)
{
	flag->plus = 0;
	flag->minus = 0;
	flag->hash = 0;
	flag->h = 0;
	flag->l = 0;
	(void)ap;
}

/**
 * print - conditional loop of _printf
 * @fmt: param
 * @i: param
 * @counter: param
 * @flag: flag construct
 * @*f: param
 * @ap: param
 */

void print(const char *fmt, unsigned int *i, unsigned int *counter,
		va_list *ap, flags_t *flag)
{
	int (*f)(va_list, flags_t *);

	while (*fmt && fmt[*i])
	{
		if (fmt[*i] != '%')
		{
			loop_through(&fmt[*i], &*counter, &*i);
			continue;
		}
		else
		{
			if (fmt[*i + 1] == '%')
			{
				handle_percentage(&*counter, &*i);
				continue;
			}
			else
			{
				init_flags(&*flag, &*ap);
				check_flag(fmt, &*i);
				if (fmt[*i + 1] == '#')
				{
					get_flag(fmt[*i + 1], &*flag);
					*i += 1;
				}
				while (get_flag(fmt[*i + 1], &*flag))
					*i += 1;
				f = check_format(&fmt[*i + 1]);
				if (f == NULL)
				{
					loop_through(&fmt[*i], &*counter, &*i);
					continue;
				}
				*i += 2;
				*counter += (f)(*ap, &*flag);
				continue;
			}
		}
		*i += 1;
	}
}

/**
 * _printf - format printing
 * @format: list of arguments to print
 * Return: number of characters to print
 */

int _printf(const char *format, ...)
{
	va_list ap;
	/*int (*f)(va_list, flags_t *);*/
	unsigned int i = 0, counter = 0;
	flags_t flags = {0, 0, 0, 0, 0};

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	print(format, &i, &counter, &ap, &flags);
	va_end(ap);
	_putchar(-1);
	return (counter);
}
