#include <stdlib.h>
#include <unistd.h>
#include "main.h"
/**
 * _putchar - writes the character c to stdout
 * @c: character to print
 *
 * Return: On Success 1.
 * On error, -1 is returned, and errno is set appropriately
 */

int _putchar(char c)
{
	static int i;
	static char buf[BUFSIZE];

	if (c == -1 || i >= BUFSIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != -1)
		buf[i++] = c;
	return (1);
	/*old putchar*/
	/*return (write(1, &c, 1));*/
}

/**
 * _strlen - returns the length of a string
 * @s: string to be checked
 * Return: length
 */

int _strlen(char *s)
{
	int length = 0;

	while (*s++)
		length++;
	return (length);
}

/**
 * _puts - prinits out a string to the terminal
 * @str: string to be printed
 */

void _puts(char *str)
{
	int i = 0;

	while (i < _strlen(str))
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * putnum - helper function that loops through
 * an integer and prints all its digits
 * @n: integer to be printed
 */
void putnum(int n)
{
	unsigned int n1;

	if (n < 0)
	{
		_putchar('-');
		n1 = -n;
	}
	else
		n1 = n;

	if (n1 / 10)
		putnum(n1 / 10);
	_putchar((n1 % 10) + '0');
}
