% _PRINTF(1) 1.0.0
% Kelvin Adeyemo Allison, Ihedioha Ezinwa Ezimma
% May, 2022


# NAME
_printf - a custom implementation of the printf function


# SYNOPSIS
int _printf(const char *fmt, ...);

int print_character(va_list c);

void print(const char *format, unsigned int *i, unsigned int *counter, va_list *ap, flags_t *flags);

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


# DESCRIPTION
**_printf** produces output according to a **format** as described below. **_printf** writes out output to stdout under the control of a format string that specifies how subsequent arguments are converted for output.


## Format of the format string
The format string is a character string. It is composed of zero or more directives - ordinary characters which are copied unchanged to the output stream - and conversion specifications, each of which result in fetching zero or more subsequent arguments. Each conversion specification is introduced by the character %, and ends with a conversion specifier. In between, there may be zero or more flags. The arguments must correspond properly with the conversion specifier. Each conversion specifier asks for the next argument and it is an error if insufficiently many arguments are given.


## Flag characters
**+** positive number - for %d and %i

**-** right alignment - for %d and %i

**space** - for all specifiers

**l and h** - l for long and h for short

**#**  - adds prefix of 0x to %x and 0X to X


## Conversion specifiers
Conversion specifier is a character that specifies the type of conversion to be applied:
	**c**  prints a single character

	**s, S** **s** prints a string of characters, while **S** prints a string of characters but replaces unprintble characters with their hex value

	**i** a conversion specifier for integers in base 10

	**d** a conversion specifier for decimal (base 10) numbers

	**x, X** **x** prints lowercase hexadecimals (base 16), while **X** prints uppercase hexadecimals (base 16)

	**p** a conversion specifier for pointers

	**r** prints the reverse of a string

	**R** prints a string in ROT13 format

	**b** a conversion specifier for binary integers

	**u** a conversion specifier for unsigned int

	**o** a conversion specifier for octal (base 8)

# EXAMPLES
_printf("%c", /single character/)

_printf("%s", /string of characters/)

_printf("%i", /base 10 integer/)

_printf("%d", /decimal (base 10) numbers/)

_printf("%x", /lowercase hexadecimal/)

_printf("%X", /uppercase hexadecimal/)

_printf("%S", /replace unprintable characters in a string with their hex value/)

_printf("%r", /reverse of a string/)

_printf("%R", /ROT13 format/)

_printf("%u", /unsigned int/)

_printf("%b", /binary integer/)


# EXIT VALUES
**Number of characters printed**
: Success

**-1**
: Failure


# BUGS
The output is unpreictable when you do not pass in a value to the conversion specifier - standard quirk.


# AUTHOR
Major - Kelvin Adeyemo Allison
Contributor - Ihedioha Ezinwa Ezimma


# FILES
**main.h**

**_printf.c**

**custom_func.c**

**base_cases.c**

**other_cases.c**

**more_cases.c**


# CAVEATS
Refer to *bugs*


# COPYRIGHT
Copyright © 2022 Kelvin Adeyemo Allison, Ihedioha Ezinwa Ezimma.
