#include "main.h"
#include <stdarg.h>
#include <unistd.h>


/**
 * print_pointer - This function displays the value of a pointer variable
 * @est: The arguments in this function
 * @buffer: The array of buffer to display the output
 * @flags:  This will round up the active flags of this function
 * @width: This will help acquire the  width in this function
 * @precision: This will specify the precision needed in the function
 * @size: This will specify the size needed in this function
 * Return: The total number of characters to be displayed
 */
int print_pointer(va_list est, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_ch = 0, pad = ' ';
	int ind = BUFF_SIZE - 2, length = 2, pad_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(est, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_address = (unsigned long)address;

	while (num_address > 0)
	{
		buffer[ind--] = map_to[num_address % 16];
		num_address /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (flags & F_PLUS)
		extra_ch = '+', length++;
	else if (flags & F_SPACE)
		extra_ch = ' ', length++;

	ind++;

	/*return (write(1, &buffer[g], BUFF_SIZE - g - 1));*/
	return (write_pointer(buffer, ind, length,
		width, flags, pad, extra_ch, pad_start));
}

/**
 * print_non_printable - This will display the ascii codes in
 * hexadecimal of non printable chars
 * @est: The arguments in this function
 * @buffer: The array of buffer to display the output
 * @flags: This will round up the active flags of this function
 * @width: This will help acquire the  width in this function
 * @precision: This will specify the precision needed in the function
 * @size: This will specify the size needed in this function
 * Return: The total number of characters to be displayed
 */
int print_non_printable(va_list est, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(est, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += fix_hex_code(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/**
 * print_rev - This will display the string in reverse format
 * @est: The arguments in this function
 * @buffer: The array of buffer to display the output
 * @flags: This will round up the active flags of this function
 * @width: This will help acquire the  width in this function
 * @precision: This will specify the precision needed in the function
 * @size: This will specify the size needed in this function
 * Return: The total number of characters to be displayed
 */

int print_rev(va_list est, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13string - Print a string in rot13.
 * @est: The arguments in this function
 * @buffer: The array of buffer to display the output
 * @flags: This will round up the active flags of this function
 * @width: This will help acquire the  width in this function
 * @precision: This will specify the precision needed in the function
 * @size: This will specify the size needed in this function
 * Return: The total number of characters to be displayed
 */
int print_rot13string(va_list est, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(est, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
