#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <limit.h>
#include <unistd.h>

/**
 * prinlhex - prints a long decimal in hexadecimal
 * @arg: input string
 * @buffer: buffer pointer
 * @ibuffer: index for buffer pointer
 * Return: number of characters printed
 */
int prinlhex(va_list arg, char *buffer, unsigned int ibuffer)
{
	long int int_input, i, isnegative, count, first_digit;
	char *hexadecimal, *binary;

	int_input = va_arg(arguments, long int);
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
	hexadecimal = malloc(sizeof(char) * (16 + 1));
	hexadecimal = fill_hex_array(binary, hexadecimal, 0, 16);
	for (first_digit = t = count = 0; hexadecimal[t]; t++)
	{
		if (hexadecimal[t] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuffer = handl_buffer(buffer, hexadecimal[t], ibuffer);
			count++;
		}
	}
	free(binary);
	free(hexadecimal);
	return (count);
}

