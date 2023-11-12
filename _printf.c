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
 * print_int - prints an integer
 * @n: integer to print
 *
 * Return: number of characters printed
 */
int print_int(int n)
{
	int len = 0;
	int num = n;

	if (n < 0)
	{
		num = -num;
		len += print_char('-');
	}
	if (num / 10)
	{
		len += print_int(num / 10);
	}
	len += print_char((num % 10) + '0');
	return (len);
}

/**
 * print_decimal - prints a decimal
 * @n: decimal to print
 *
 * Return: number of characters printed
 */
int print_decimal(int n)
{
	int len = 0;
	int num = n;

	if (n < 0)
	{
		num = -num;
		len += print_char('-');
	}
	if (num / 10)
	{
		len += print_decimal(num / 10);
	}
	len += print_char((num % 10) + '0');
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
			if (format[i + 1] == 'i')
				count += print_int(va_arg(args, int)), i++;
			if (format[i + 1] == 'd')
				count += print_decimal(va_arg(args, int)), i++;
		}
	}

	va_end(args);
	return (count);
}
