#include <stdarg.h>
#include <stdio.h>
#include "sort.h"

void _printf(const char *format, ...);
/**
 * _printf - Custom printf function to print strings
 * @format: character pointer
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

				_printfs("%d", num);
			}
			else if (*format == 'c')
			{
				int character = va_arg(args, int);

				_printfs("%c", character);
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				_printfs("%s", str);
			}
			else if (*format == '%')
			{
				_printfs("%%");
			}
		}
		else
		{
			_printfs("%c", *format);
		}

		format++;
	}

	va_end(args);
}
