#include "main.h"

/**
* _puts - prints a string with new line
* @str: the string to print
* Return: void
*/

int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar (*str++);
	return (str - a);
}

/**
* _putchar - writes the character c to stdout
* @c: tha character to print
* Return: on success 1;
*/

int _putchar(int c)
{
	static int i;

	static char buf(OUT¨PUT_BUF_SIZE);

	if (c == BUF_FLUSH || i  >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
