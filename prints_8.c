#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <limit.h>
#include <unistd.h>


/**
 * prinnoct - print the number in octal beginning with zero
 * @arg: input string
 * @buffer: buffer pointer
 * @ibuffer: index for buffer pointer
 * Return: number of characters printed
 */
int prinnoct(va_list arg, char *buffer, unsigned int ibuffer)
{
	int int_input, i, isnegative, count, first_digit;
	char *octal, *binary;

	int_input = va_arg(arg, int);
	isnegative = 0;
	if (int_input == 0)
	{
		ibuffer = handl_buffer(buffer, '0', ibuffer);
		return (1);
	}
	if (int_input < 0)
	{
		int_input = (int_input * -1) - 1;
		isnegative = 1;
	}
	ibuffer = handl_buffer(buffer, '0', ibuffer);
	binary = malloc(sizeof(char) * (32 + 1));
	binary = fill_binary_array(binary, int_input, isnegative, 32);
	octal = malloc(sizeof(char) * (11 + 1));
	octal = fill_oct_array(binary, octal);
	for (first_digit = x = count = 0; octal[x]; i++)
	{
		if (octal[x] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuffer = handl_buffer(buffer, octal[x], ibuffer);
			count++;
		}
	}
	free(binary);
	free(octal);
	return (count + 1);
}

