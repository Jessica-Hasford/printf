#include "main.h"
#include <stdarg.h>
#include <unistd.h>


void print_buffer(char buffer[], int *buff_ind);

/**
 *_printf -  This is the printf function
 *@format: This is the format.
 *@jess: This shows the number of arguments
 * Return: The characters to be displayed.
 */
int _printf(const char *format, ...)
{
	int u, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list jess;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(jess, format);

	for (u = 0; format && format[u] != '\0'; u++)
	{
		if (format[u] != '%')
		{
			buffer[buff_ind++] = format[u];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[u], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = nab_flags(format, &u);
			width = nab_width(format, &u, jess);
			precision = nab_precision(format, &u, jess);
			size = nab_size(format, &u);
			++u;
			printed = handle_print(format, &u, jess, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(jess);

	return (printed_chars);
}

/**
 * print_buffer -  This displays the elements of the buffer if available
 * @buffer: This represents an array of chars
 * @buff_ind: This represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

