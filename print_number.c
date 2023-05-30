#include "main.h"

/**
 * _isdigit - checks if character is digit
 * @c: the character to check
 * Return: 1 if digit, 0 otherwise
 */

int _isdigit(int c)
{
	return (c >= '0' && c<= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 * Return: integer length of string
 */

int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - prints a number with options
 * @str: the base number as a string
 * @params: parameters struct
 * Return: chars printed
 */

int print_number(char *str, params_t *params)
{
	unsigned int i = _strlen(str);
	int neg = (!params->unsign && *str == '-');

	if (!params ->precision && *str == '0' && !str[i])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (params->precision != UNIT_MAX)
		while (i++ < params->precision)
			*-str = '0';
	if (neg)
		*--str = '-';
	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}


