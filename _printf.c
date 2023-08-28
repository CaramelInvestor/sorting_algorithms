#include <stdarg.h>
#include <stdio.h>
#include "sort.h"

void _printf(const char *format, ...);
/**
 * _printf - function to print strings
 *@format: character pointer
 */

void _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'd')
			{
				int num = va_arg(args, int);
				printf("%d", num);
			}
			else if (*format == 'c')
			{
				int character = va_arg(args, int);
				putchar(character);
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				fputs(str, stdout);
			}
			else if (*format == '%')
			{
				putchar('%');
			}
		}
		else
		{
			putchar(*format);
		}

		format++;
	}

	va_end(args);
}
