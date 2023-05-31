#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(NULL)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED  2

/**
 * struct parameters - parameters struct
 * @unsign: flag if unsigned value
 * @plus_flag: on if plus_flag speciefed
 * @minus_flag: on if minus_flag speciefed
 * @hashtag_flag: on if hashtag_flag speciefed
 * @space_flag: on if space_flag specifed
 * @zero_flag: on if zero_flag specifed
 * @width: field width specifed
 * @precision: field precision specifed
 * @h_modifier: on if h_modifier specifed
 * @l_modifier: on if l_modifier is specifed
 */

typedef struct parameters
{
	unsigned int unsign       : 1;
	unsigned int plus_flag    : 1;
	unsigned int minus_flag   : 1;
	unsigned int hashtag_flag : 1;
	unsigned int space_flag   : 1;
	unsigned int zero_flag    : 1;
	unsigned int width;
	unsigned int precision;
	unsigned int h_modifier   : 1;
	unsigned int l_modifier   : 1;
}paramas_t;

/**
 * struct specifier - struct token
 * @specifier: format token
 * @f: the function associated
 */

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
}specifier_t;

/* _put.c */
int _puts(char *str);
int _putchar(char c);

/* specifier.c */
char *get_width(char *s, params_t *params, va_list ap);
int get_modifier(char *s, params_t *params);
int get_flag(char *s, params_t *params);
int get_print_func(char *s, va_list ap, params-t *params);
int (*get_specifier(char *s))(va_list ap, params_t *params);

/* params */
void init_params(params_t *params, va_list ap);

/* simple_pointers */
int print_rot13(va_list ap, params_t *params);
int print_rev(va_list ap, params_t *params);
int print_from_to(char *start, char *stop, char *except);

/* string_fields */
char *get_precision(char *p, params_t *params, va_list ap);

/* _printf.c */
int _printf(const char *format, ...);

/* print_functions.c */
int print_percent(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_char(va_list ap, params_t *params);
int print_s(va_list ap, params_t *params);

/* number.c */
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

/* convert_number.c */
int print_HEX(va_list ap, params_t *params);
int print_hex(va_list ap, params_t *params);

#endif
