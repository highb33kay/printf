#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _printf - prints anything
 * @format: list of argument types passed to the function
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
    // accept a format string and optional arguments
    va_list args;
    unsigned int i;
    char *s;
    int count = 0;
    char c;
    int d;

    // initialize ap to the list of arguments
    va_start(args, format);
    // check if the format string is NULL
    if (format == NULL)
    {
        return (-1);
    }

    // iterate through the format string
    for (i = 0; format[i] != '\0'; i++)
    {
        // if the current character is not a format specifier, print it and continue
        if (format[i] != '%')
        {
            write(1, &format[i], 1);
            count++;
        }
        else
        {
            // if the current character is a format specifier, print the corresponding argument
            if (format[i + 1] != 'c' && format[i + 1] != 's' && format[i + 1] != '%')
            {
                write(1, &format[i], 1);
                count++;
            }
            // if the format string is not a string, print it and return -1
            if (format[i + 1] == 'c')
            {
                c = va_arg(args, int);
                write(1, &c, 1);
                count++;
                i++;
            }
            if (format[i + 1] == 's')
            {
                // handle strings
                s = va_arg(args, char *);
                int len = 0;
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
                // handle %
                write(1, "%", 1);
                count++;
                i++;
            }
            // if (format[i + 1] == 'i')
            // {
            //     d = va_arg(args, int);
            //     int part = abs(d);
            //     char buffer[12];
            //     int length = 0;

            //     // Handle negative numbers
            //     if (d < 0)
            //     {
            //         write(1, "-", 1);
            //         count++;
            //     }

            //     // Convert integer to string
            //     do
            //     {
            //         buffer[length++] = '0' + part % 10;
            //         part /= 10;
            //     } while (part > 0);

            //     // Print characters in reverse order
            //     for (int j = length - 1; j >= 0; j--)
            //     {
            //         write(1, &buffer[j], 1);
            //         count++;
            //         i++;
            //     }

            //     i++;
            // }
        }
    }

    // free the list of arguments
    va_end(args);
    // return the number of characters printed
    return (count);
}
