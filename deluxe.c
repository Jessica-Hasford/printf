#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @format: Formatted string in which to print the arguments.
 * @jess: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 *f: The function associated
 * Return: 1 or 2;
 */
int handle_print(const char *format, int *ind, va_list jess, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	sym_t sym_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; sym_types[i].sym != '\0'; i++)
		if (sym[*ind] == sym_types[i].sym)
			return (sym_types[i].f(list, buffer, flags, width, precision, size));

	if (sym_types[i].sym == '\0')
	{
		if (sym[*ind] == '\0')
			return (-1);
		unknow_length += write(1, "%%", 1);
	if (sym[*ind - 1] == ' ')
	unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (sym * ind] != ' ' && sym[*ind] != '%')
				--(*ind);
			if (sym[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_length += write(1, &sym[*ind], 1);
		return (unknow_length);
	}
	return (printed_characters);
}

