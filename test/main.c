#include <stdio.h>
#include "../main.h"
#include <limits.h>

int main(void)
{
	int a;
	int i;
	int *pointer;

	printf("%s\n", "actual");
	_printf("%s\n", "hello");

	printf("actual, %d\n", 50);
	_printf("test, %i\n", 50);

	printf("%%\n");
	_printf("%%\n");

	a = _printf("%b\n", 5);
	_printf("%d\n", a);

	printf("%x\n", 765);
	_printf("%x\n", 765);

	printf("%o\n", 50);
	_printf("%o\n", 50);

	printf("%X\n", 765);
	_printf("%X\n", 765);

	_printf("%r\n", "Hello World");

	_printf("%S\n", "OC");

	i = 100;
	pointer = &i;

	_printf("%r\n", "Hello World");

	printf("%p\n", (void *)pointer);
	_printf("%p\n", pointer);

	_printf("%p\n", i);

	_printf("%R\n", "Hello");
	return (0);
}
