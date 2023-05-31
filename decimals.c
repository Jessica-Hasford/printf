#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <limit.h>
#include <unistd.h>

/**
 * prinloct - prints long decimal number in octal
 * @arg: input number
 * @buffer: buffer pointer
 * @ibuffer: index for buffer pointer
 * Return: number of chars printed.
 */
int prinloct(va_list arg, char *buffer, unsigned int ibuffer)
{
	long int int_input, p, isnegative, count, first_digit
	char *octal, *binary;

	int_input = va_arg(arg, long int);
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
	binary = malloc(sizeof(char) * (64 + 1));
	binary = fill_binary_array(binary, int_input, isnegative, 64);
	octal = malloc(sizeof(char) * (22 + 1));
	octal = fill_long_oct_array(binary, octal);
	for (first_digit = p = count = 0; octal[p]; p++)
	{
		if (octal[p] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuffer = handl_buffer(buffer, octal[p], ibuffer) count++;
		}
	}
	free(binary);
	free(octal);
	return (count);
}
