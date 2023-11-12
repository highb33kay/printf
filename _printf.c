#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

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
    char *s;
    int count = 0;
    char c;

    va_start(args, format);
    if (format == NULL)
    {
        return (-1);
    }

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            write(1, &format[i], 1);
            count++;
        }
        else
        {
            if (format[i + 1] != 'c' && format[i + 1] != 's' && format[i + 1] != '%')
            {
                write(1, &format[i], 1);
                count++;
            }
            if (format[i + 1] == 'c')
            {
                c = va_arg(args, int);
                write(1, &c, 1);
                count++;
                i++;
            }
            if (format[i + 1] == 's')
            {
                int len = 0;
                s = va_arg(args, char *);

                while (s[len] != '\0')
                {
                    len++;
                }
                write(1, s, len);
                count++;
                i++;
            }
            if (format[i + 1] == '%')
            {
                write(1, "%", 1);
                count++;
                i++;
            }
        }
    }

    va_end(args);
    return (count);
}
