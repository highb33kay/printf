#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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

	if (s == NULL)
	{
		return (-1);
	}

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
 * conv_binary - converts unsigned in to binary
 * @n: the number to be converted
 *
 * Return: always 0
 */

int conv_binary(unsigned int n)
{
	unsigned int i, j;
	unsigned int num[sizeof(n) * 8];

	while (n > 0)
	{
		num[i] = n % 2;
		n = n / 2;
		i++;
	}

	for (j = i; j > 0; j--)
	{
		print_int(num[j - 1]);
	}
	return (0);
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
			switch (format[i + 1])
			{
				case 'c':
					count += print_char(va_arg(args, int)), i++;
					break;
				case 's':
					count += print_string(va_arg(args, char *)), i++;
					break;
				case 'd':
				case 'i':
					count += print_int(va_arg(args, int)), i++;
					break;
				case '%':
					count += print_char('%'), i++;
					break;
				case 'b':
					count += conv_binary(va_arg(args, int)), i++;
					break;
				default:
					count += print_char(format[i]);
			}
		}
	}
	va_end(args);
	return (count);
}
