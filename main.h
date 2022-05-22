#ifndef HEADER_MAIN
#define HEADER_MAIN
#include <stdarg.h>
#include <stdio.h>
#define BUFSIZE 1024

/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @minus: flag for the '-' character
 * @h: flag for the h length modifier
 * @l: flag for the l length modifier
 * @hash: flag for the '#' character
 */
typedef struct flags
{
	unsigned int plus: 1;
	unsigned int minus: 1;
	unsigned int hash: 1;
	unsigned int h: 1;
	unsigned int l: 1;
} flags_t;
/**
 * struct print - structure for printing various types
 * @t: type to print
 * @f: function to print
 */

typedef struct print
{
	char *t;
	int (*f)(va_list, flags_t *);
} print_t;

/* helpers */
int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
void putnum(int n);
void loop_through(const char *in, unsigned int *count, unsigned int *i);
void handle_percentage(unsigned int *count, unsigned int *i);
int get_flag(char s, flags_t *f);
void use_mod(unsigned int *res, unsigned int *l, unsigned int *h);
char *convert(unsigned long int num, int base, int lowercase);

/**
 * print - conditional loop of _printf
 * @format: param
 * @i: param
 * @counter: param
 * @*f: param
 * @ap: param
 * @flags: flags struct
 */
void print(const char *format, unsigned int *i, unsigned int *counter,
		va_list *ap, flags_t *flags);
void init_flags(flags_t *flag, va_list *ap);
int _printf(const char *fmt, ...);
int print_character(va_list c, flags_t *f);
int print_string(va_list s, flags_t *f);
int print_integer(va_list i, flags_t *f);
int print_d(va_list d, flags_t *f);
int print_binary(va_list b, flags_t *f);
int print_unsigned(va_list u, flags_t *f);
int print_hex(va_list x, flags_t *f);
int print_HEX(va_list X, flags_t *f);
int print_octal(va_list o, flags_t *f);
int print_reverse(va_list r, flags_t *f);
int print_STRING(va_list S, flags_t *f);
int print_pointer(va_list p, flags_t *f);
int print_ROT(va_list R, flags_t *f);
#endif