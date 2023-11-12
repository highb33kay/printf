#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * print_char - prints a character
 * @c: character to print
 *
 * Return: number of characters printed
 */
int print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * print_string - prints a string
 * @s: string to print
 *
 * Return: number of characters printed
 */
int print_string(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	write(1, s, len);
	return (len);
}

/**
 * _printf - prints anything
 * @format: list of argument types passed to the function
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	unsigned int i;
	int count = 0;

	va_start(args, format);
	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			count += print_char(format[i]);
		}
		else
		{
			if (format[i + 1] != 'c' && format[i + 1] != 's' && format[i + 1] != '%')
				count += print_char(format[i]);
			if (format[i + 1] == 'c')
				count += print_char(va_arg(args, int)), i++;
			if (format[i + 1] == 's')
				count += print_string(va_arg(args, char *)), i++;
			if (format[i + 1] == '%')
				count += print_char('%'), i++;
		}
	}

	va_end(args);
	return (count);
}
