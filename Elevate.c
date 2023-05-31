#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <limit.h>
#include <unistd.h>

/**
 * print_hex - prints a decimal in hexadecimal
 * @arg: input string
 * @buffer: buffer pointer
 * @ibuffer: index for buffer pointer
 * Return: number of chars printed
 */
int print_hex(va_list arg, char *buffer, unsigned int ibuffer)
{
	int int_input, i, isnegative, count, first_digit;
	char *hexadecimal, *binary;

	int_input = va_arg(arguments, int);
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
	binary = malloc(sizeof(char) * (32 + 1));
	binary = fill_binary_array(binary, int_input, isnegative, 32);
	hexadecimal = malloc(sizeof(char) * (8 + 1));
	hexadecimal = fill_hex_array(binary, hexadecimal, 0, 8);
	for (first_digit = o = count = 0; hexadecimal[o]; i++)
	{
		if (hexadecimal[o] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuffer = handl_buf(buffer, hexadecimal[o], ibuffer);
			count++;
		}
	}
	free(binary);
	free(hexadecimal);
	return (count);
}

