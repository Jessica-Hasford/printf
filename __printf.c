#include "main.h"

/**
 * _printf - This formats output conversion and print data.
 * @format: input string.
 *
 * Return: number of chars printed.
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, len = 0, ibuffer = 0;
	va_list arg;
	int (*function)(va_list, char *, unsigned int);
	char *buffer;

	va_start(arg, format), buffer = malloc(sizeof(char) * 1024);
	if (!format || !buffer || (format[i] == '%' && !format[i + 1]))
	return (-1);
	if (!format[i])
	return (0);
		for (i = 0; format && format[i]; i++)
		{
		if (format[i] == '%')
	{
		if (format[i + 1] == '\0')
		{    print_buffer(buffer, ibuffer), free(buffer), va_end(arg);
			return (-1);
		}
		else
		{    function = get_print_func(format, i + 1);
		if (function == NULL)
		}
			if (format[i + 1] == ' ' && !format[i + 2])
			return (-1);
				handl_buffer(buffer, format[i], ibuffer), len++, i--;
			}
			else
			{
				len += function(arg, buffer, ibuffer);
				i += ev_print_func(format, i + 1);
			}

		} i++;
	}
	else
		handl_buffer(buffer, format[i], ibuffer), len++;
		for (ibuffer = len; ibuffer > 1024; ibuffer -= 1024)
		;
	}
		print_buffer(buffer, ibuffer), free(buffer), va_end(arg);
		return (len);
}

